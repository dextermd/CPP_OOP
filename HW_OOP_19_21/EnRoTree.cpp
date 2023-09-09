#include "EnRoTree.h"
#include <iostream>

using namespace std;

EnRoTree::Text::Text(const MyString& _enText, const MyString& _roText, Text* _right, Text* _left)
{
	this->enText = _enText;
	this->roText = _roText;

	left = _left;
	right = _right;
}

void EnRoTree::Add(Text*& text, MyString& en, MyString& ro)
{
	if (text == nullptr)
		text = new Text(en, ro);      // конструктор Node
	else if (en < text->enText)
		Add(text->left, en, ro);
	else Add(text->right, en, ro);
}

void EnRoTree::DeleteSubEnRoTree(Text* text)
{
	if (text != nullptr)
	{
		DeleteSubEnRoTree(text->left);
		DeleteSubEnRoTree(text->right);

		delete text;
		text = nullptr;
		count--;
	}
}

void EnRoTree::Show(Text* text) const
{
	if (!text) return;
	Show(text->left);
	cout << text->enText << " - " << text->roText << endl;
	Show(text->right);
}

bool EnRoTree::search(Text* text, const MyString& _search) const
{
	if (!text) {
		cout << "\nThere is no such word in the dictionary.\n";
		return false;
	}
		
	if (text->enText == _search) {
		cout << "\nTranslation : " << text->roText;
		return true;
	}

	if (text->enText <= _search) return search(text->right, _search);
	else return search(text->left, _search);
}

void EnRoTree::save_txt(Text* text, FILE* f) const
{
	if (!text) return;
	save_txt(text->left, f);
	fprintf(f, "%s %s ", text->enText.get_str(), text->roText.get_str());
	save_txt(text->right, f);
}

void EnRoTree::save_to_binary_file(Text* text, FILE* f)
{
	if (!text) return;
	save_to_binary_file(text->left, f);

	int lenen = text->enText.getLength();
	fwrite(&lenen, sizeof(lenen), 1, f);
	fwrite(text->enText.get_str(), text->enText.getLength() + 1, 1, f);

	int lenro = text->roText.getLength();
	fwrite(&lenro, sizeof(lenro), 1, f);
	fwrite(text->roText.get_str(), text->roText.getLength() + 1, 1, f);

	save_to_binary_file(text->right, f);
}

void EnRoTree::read_from_binary_file(Text*& text, FILE* f)
{
	MyString strEn;
	MyString strRo;
	char bufEn[250];
	char bufRo[250];
	int lenen;
	int lenro;

	if (!fread(&lenen, sizeof(lenen), 1, f))
		return;

	fread(bufEn, lenen + 1, 1, f);
	strEn = bufEn;

	if (!fread(&lenro, sizeof(lenro), 1, f))
		return; 

	fread(bufRo, lenro + 1, 1, f);
	strRo = bufRo;

	text = new Text(strEn, strRo);

	if (strEn < text->enText)
		read_from_binary_file(text->left, f);
	else
		read_from_binary_file(text->right, f);

	this->count++;
}
