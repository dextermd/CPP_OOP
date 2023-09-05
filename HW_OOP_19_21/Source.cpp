#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <Windows.h>
#include "MyString.h"
#include "MyTree.h"



using namespace std;


int main()
{

#if 1
	/*
		������� 1. ��� ��� ������������� ������ ��������� ������ ������(MyTree) ���������� ������ ��� :
		- ������ ������ ������ � ��������� ����;
		- ������ ������ ������ � �������� ����;
		- ������ ������ �� ��������� ����� � �������������� ������� ������.
	*/

	MyTree t;

	t.Show();
	cout << endl;

	t.Add(25);
	t.Add(4);
	t.Add(33);
	t.Add(335);
	t.Add(678);
	t.Add(135);
	t.Add(663);
	t.Add(144);
	t.Add(15);
	t.Add(17);
	t.Add(50);

	t.Show();
	cout << endl;

	FILE* file;
	errno_t err;

	// Write
	err = fopen_s(&file, "text.txt", "wb");
	if (!err)
	{
		t.save_txt(file);
		fclose(file);
		cout << endl;
	}

#endif


#if 0
	/*
		������� 2. ���������� ����� - ������� ������� � ������� ��������� ������ ������.������
		����� ������� ����� �� ����������, ��������� ���� � ������� ����� �� �������.��� ����
		������������ ��� ������������ ����� ������� / MyString�.����������� ���������
		���������� ������ :
		- ���������� ������ � �������;
		- ����� ����������� �����, � ������ ������� ����� � ������� � ���� �������,� � ������ ���������� � ���������;
		- ������ ������� � ��������� ����;
		- ������ ������ ������� � �������� ����;
		- ���������� ������� �� ��������� �����(� �������������� ������).
	*/




	/*
		������ ������ ��������� ��������� :
		������� ����� �� ���������� : window
		������� ������� �� ������� : ����
		������� ����� �� ���������� : table
		������� ������� �� ������� : ����
		������� ����� �� ���������� : apple
		������� ������� �� ������� : ������

		�������� ����� - �������� ������� :
		apple - ������
		table - ����
		window - ����
		
		- ������� ����� ��� ������ : table
		������� : ����

		- ������� ����� ��� ������ : pen
		������ ����� ��� � �������.

		������ �������� � ����

		���������� ��������� ������ �� ���������� 0
		������ �����

		������ �������� �� ����� :
		apple - ������
		table - ����
		window - ����
		���������� ��������� ������ ����� ���������� 3

		��������������� ������� �� ����� ����������(5 - 10 ����).
		����������������� ������ ���� ������� ������.
		�� ������� ����������� ���� ������������ ��� ������ �� ��������.
	*/




#endif



}