#include "EnRoTree.h"
#include <iostream>

using namespace std;

EnRoTree::Text::Text(MyString*& _enText, MyString*& _roText, Text* _right, Text* _left)
{
	//int lenEn = _enText->getLength();
	//this->enText = new char[lenEn + 1];
	//strcpy_s(this->enText, lenEn + 1, _enText->get_str());

	//int lenRo = _roText->getLength();
	//this->roText = new char[lenRo + 1];
	//strcpy_s(this->roText, lenRo + 1, _roText->get_str());

	this->enText = _enText->get_str();
	this->roText = _roText->get_str();

	left = _left;
	right = _right;
}
