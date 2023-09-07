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

		Text(MyString*& _enText, MyString*& _roText, Text* _right = nullptr, Text* _left = nullptr);
	};

	Text* root;
	int count;							


public:
	EnRoTree() { root = nullptr; count = 0; }
};

