
#include <iostream>
#include "MyTree.h"
using namespace std;

MyTree::Node::Node(int _data, Node * _right , Node *_left )
	: data(_data), left(_left), right(_right)
{
	/*data = _data;
	left = _left;
	right = _right;*/
}

//----------------------------------------------------------
void MyTree::Add(Node *& node, const int& data)
{
	if (node == nullptr)
		node = new Node(data);      // конструктор Node
	else if (data < node->data)
	Add(node->left, data);
	else Add(node->right, data);
}


//----------------------------------------------------------
void MyTree::Show(Node* node)const
{
	if (!node) return;
	//cout << node->data << "  "; //Данные ветки
	Show(node->left);
	cout << node->data << "  "; //Данные ветки
	Show(node->right);
}


//----------------------------------------------------------
void MyTree::DeleteSubMyTree(Node * node)
{
	if (node != nullptr)                
	{
		DeleteSubMyTree(node->left);                
		DeleteSubMyTree(node->right); 
		//cout << endl << node->data << "   ";
		
		delete node;                 
		node = nullptr;                 
		count--;
	}
}

MyTree::Node* MyTree::search(Node* node, int data) const
{
	/*while (node != nullptr && node->data != data)
	{
		if (data >= node->data) {
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	return node;*/

	if (!node) return nullptr;
	if (node->data == data) return node;
	
	if (node->data <= data) return search(node->right, data);
	else return search(node->left, data);
}

void MyTree::save_txt(Node* node, FILE* f) const
{
	if (!node) return;
	save_txt(node->left, f);
	fprintf(f, "%d ", node->data);
	save_txt(node->right, f);
}

void MyTree::save_to_binary_file(Node* node, FILE* f)
{
	if (!node) return;
	save_to_binary_file(node->left, f);
	fwrite(&node->data, sizeof(node->data), 1, f);
	save_to_binary_file(node->right, f);
}

void MyTree::read_from_binary_file(Node*& node, FILE* f)
{
	int num;
	while (fread(&num, sizeof(num), 1, f) == 1)
	{
		node = new Node(num);
		if (num < node->data)
			read_from_binary_file(node->left, f);
		else read_from_binary_file(node->right, f);
		this->count++;
	}	
}

