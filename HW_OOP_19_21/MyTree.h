#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class MyTree {

private:

	struct Node {  						//  inner stuct
		int data;  						//  полезные данные и ключ 
		Node * right;
		Node * left;

		Node(int _data, Node * _right = nullptr, Node * _left = nullptr);	// конструктор
	};

	Node * root;						// адрес корня
	int count;							// количество узлов

	int GetCount()const { return count; }
		
	void Add(Node*& node, const int& data);
	void DeleteSubMyTree(Node* node);
	void Show(Node* node)const;

	Node* search(Node* n, int data)const;

	
public:
	MyTree() { root = nullptr; count = 0; }

	~MyTree() { 
		DeleteSubMyTree(root); 
		/*cout << "\ncount = "<< count;
		_getch();*/
	}

	void Add(const int & data) 
	{ 
		Add(root, data);				// вызов private method
		count++; 
	}

	void Show()const {
		if (count) Show(root);			// вызов private method
		else
		{
			cout << "\nTree Empty\n";
			return;
		}
	}

	bool search(int value) const {
		return search(root, value);		//вызов private метода
	}

	int getCount()const { return count; }

};
