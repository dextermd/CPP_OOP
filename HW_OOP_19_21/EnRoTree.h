#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "MyString.h"

using namespace std;

class EnRoTree
{
private:

	struct Text {  						
		MyString enText;  					
		MyString roText;  						 
		Text* right;
		Text* left;

		Text(const MyString& _enText, const MyString& _roText, Text* _right = nullptr, Text* _left = nullptr);
	};

	Text* root;
	int count;			

	//Add Methods
	void Add(Text*& text, MyString& en, MyString& ro);

	//Get Methods
	int GetCount()const { return count; }

	// Show Methods
	void Show(Text* text) const;
	bool search(Text* text, const MyString& _search) const;

	// File Methods
	void save_txt(Text* text, FILE* f) const;
	void save_to_binary_file(Text* text, FILE* f);
	void read_from_binary_file(Text*& text, FILE* f);

	// Delete Methods
	void DeleteSubEnRoTree(Text* text);

public:
	EnRoTree() { root = nullptr; count = 0; }

	~EnRoTree() {
		DeleteSubEnRoTree(root);
	}

	void Add()
	{
		char buf[250];
		MyString en;
		MyString ro;
		cout << "\nEnter a word in English: ";
		cin.getline(buf, sizeof(buf));
		en = buf;
		cout << "\nEnter the translation in Romanian: ";
		cin.getline(buf, sizeof(buf));
		ro = buf;
		Add(root, en, ro);
		count++;
	}

	void search() const {
		char buf[250];
		MyString _search;
		cout << "\nEnter a search word: ";
		cin.getline(buf, sizeof(buf));
		_search = buf;
		search(root, _search);
	}

	void Show()const {
		if (count){
			cout << "\nEnglish - Romanian fragment dictionary :\n";
			Show(root);
		}
		else
		{
			cout << "\nTree Empty\n";
			return;
		}
	}

	void save_txt(FILE* f)
	{
		save_txt(root, f);
	}

	void save_to_binary_file(FILE* f) {
		save_to_binary_file(root, f);
	}

	void read_from_binary_file(FILE* f) {
		read_from_binary_file(root, f);
	}

	int getCount()const { return count; }
};

