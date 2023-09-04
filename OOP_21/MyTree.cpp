
#include <iostream>
#include "MyTree.h"
using namespace std;



MyTree::Node::Node(int _data, Node * _right, Node * _left): data(_data), left(_left), right(_right)
{
	/*data = _data;
	left = _left;
	right = _right;*/
}



//----------------------------------------------------------
void MyTree::Add(Node *& node, const int& _data)
{
	if (node == nullptr)
		node = new Node(_data);      // конструктор Node
	else if (_data < node->data)
		Add(node->left, _data);
	else Add(node->right, _data);
}



//----------------------------------------------------------
void MyTree::Show(Node* node)const
{
	if (!node) return;
	Show(node->left);
	cout << node->data << "  "; //Данные ветки
	Show(node->right);
}

MyTree::Node* MyTree::Find_Element(Node* node, int _data) const
{
	while (node != nullptr && node->data != _data){
		if (_data > node->data)
		{
			node = node->right;
		}
		else {
			node = node->left;
		}
	}
	return node;
}

MyTree::Node* MyTree::R_Find_Element(Node* node, int _data) const
{
	if (node == nullptr) return nullptr;

	if (node->data == _data) 
		return node;

	if (node->data <= _data) R_Find_Element(node->right, _data);
	else return R_Find_Element(node->left, _data);
}

bool MyTree::Find_Element(int _data) const
{
	return Find_Element(root, _data);
}

bool MyTree::R_Find_Element(int _data) const
{
	return R_Find_Element(root, _data);
}




//----------------------------------------------------------
void MyTree::DeleteSubMyTree(Node * node)
{
	if (node != nullptr)                
	{
		DeleteSubMyTree(node->left);                
		DeleteSubMyTree(node->right); 
		//cout << node->data << "   ";
		
		delete node;                 
		node = nullptr;                 
		count--;
	}
}

