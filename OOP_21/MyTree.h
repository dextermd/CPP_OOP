#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class MyTree {

private:

	struct Node {  		// inner stuct
		int data;  		// полезные данные и ключ 
		Node * right;
		Node * left;

		Node(int _data, Node * _right = nullptr, Node * _left = nullptr);	// конструктор
	};

	Node * root;	// адрес корня
	int count;		// количество узлов

	int GetCount()const { return count; }
		
	void Add(Node*& node, const int& _data);
	void DeleteSubMyTree(Node* node);
	void Show(Node* node)const;
	
	Node* Find_Element(Node* node, int _data) const;
	Node* R_Find_Element(Node* node, int _data) const;

	
public:
	MyTree() { root = nullptr; count = 0; }

	bool Find_Element(int _data) const;

	bool R_Find_Element(int _data)const;

	~MyTree() { 
		DeleteSubMyTree(root); 
		/*cout << "\ncount = "<< count;
		_getch();*/
	}

	void Add(const int & _data) 
	{ 
		Add(root, _data);
		count++; 
	}

	void Show()const {
		if (count) Show(root);
		else
		{
			cout << "\nTree Empty ";
			return;
		}
	}

	
	int getCount()const { return count; }

};
