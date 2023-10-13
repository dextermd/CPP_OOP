#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <array>
#include <vector>
#include <algorithm>
#include "string_to_b_file.h"
#include <list>
#include "person.h"

using namespace std;


template<class T>
void show(const list<T>& lst)
{
	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

bool decr(int a, int b) { return a > b; }

// ������� ����������� �������
bool is_even(int a) { return a % 2 == 0; };


bool comp_age(const Person& p1, const Person& p2)
{
	return p1.get_age() < p2.get_age();
}


bool comp_surname_decr(const Person& p1, const Person& p2)
{
	return (p1 > p2);  // ����� ����������
}


int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(0));


#if 0

	// ---------------------------------------------------------------------------------------------------------------------
	// �������� � ������������������� ��������� ������

	vector<int> v = { 2, 3, 6, 9, 8 }, v2(5);
	int row = 3, col = 5;

	vector<vector<int>> arr(row, vector<int>(col));

	//vector<vector<int>>::iterator it = arr.begin();
	for (auto it_row = arr.begin(); it_row != arr.end(); it_row++)
	{
		for (auto it_col = it_row->begin(); it_col != it_row->end(); it_col++)
		{
			*it_col = rand() % 10;
			cout << *it_col << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	// ---------------------------------------------------------------------------------------------------------------------
	// ������� ������� � �������������� ranfe_base �����

	for (auto value : arr)
	{
		for (auto v : value)
		{
			cout << v << "  ";
		}
		cout << endl;
	}


	cout << endl << endl;

	vector<vector<int>> arr2(row, vector<int>(col));
	for (auto& value : arr2)
	{
		for (auto& v : value)
		{
			v = rand() % 10;
			cout << v << "  ";
		}
		cout << endl;
	}

	cout << endl << endl;

	for (const auto& value : arr2)
	{
		for (const auto& v : value)
		{
			cout << v << "  ";
		}
		cout << endl;
	}

#endif


#if 1

	// ���������� � �������������---------------------------------------------

	list<int> lt = { 12, 6, -9, 5, 34, 8, 7, 7, 11, 6, 6, 6, 5, 5 };

	for (auto x : lt)
	{
		cout << x << "  ";
	}
	cout << endl << endl;

#endif

#if 0



	//// ����������------------------------------------------------------------
	cout << "\n������ ����� ���������� �� ����������� \n";
	lt.sort();  // �� ����������� 
	show(lt);

	cout << "\n������ ����� ���������� �� �������� \n";
	lt.sort(decr);  // �� ��������
	show(lt);

#endif // 0


#if 0


	// ���������� ��������� � ������/�����-----------------------------------
	cout << "\n���������� ��������� � ������/�����\n";
	lt.push_back(20);
	lt.push_front(5);
	show(lt);
	cout << "\nsize = " << lt.size() << endl;


#endif // 0

#if 0


	// �������� ���������: �������/����������--------------------------------
	cout << "\n�������� ���������: �������/����������\n";
	lt.pop_back();
	lt.pop_front();
	show(lt);
	cout << "\nsize = " << lt.size() << endl;

#endif // 0

#if 0


	// �������� ���������������� ����������-----------------------------------
	cout << "\n�������� ���������������� ����������\n";
	lt.unique();
	show(lt);

#endif // 0


#if 0


	// ������-----------------------------------------------------------------
	cout << "\nreverse\n";
	lt.reverse();
	show(lt);

#endif // 0

#if 0


	// ���������� ��������� --------------------------------------------------
	cout << "\n���������� ���������\n";
	auto it = lt.begin();
	++it;
	lt.insert(it, 222);  // 

	show(lt);
	cout << endl << *it << endl;// �������� ��������� �� ��������� �������


	//it += 3;// error

	advance(it, 3);// �������� ��������� �� 3 ������������ ������� �������

	cout << "\n������ " << distance(lt.begin(), it) << endl;


	lt.insert(it, -1000); // ����� ���������� �������� ��������� �� 1
	show(lt);
	cout << endl << *it << endl;


	advance(it, -3);
	cout << endl << *it << endl;


#endif // 0

#if 0


	// �������� ��������� - �� ���������------------------------------------
	// ����� �������� �������� �������� �� ����� ���������� ��������
	cout << "\n�������� ��������� �� ���������\n";
	it = lt.erase(it);
	show(lt);
	cout << endl << *it << endl;
	cout << "\n������ " << distance(lt.begin(), it) << endl;

#endif // 0

#if 0
	
	// �������� ���������(��� ��������) - �� ��������--------------------------------------
	cout << "\n�������� ��������� �� ��������\n";
	lt.remove(34);
	lt.remove(2000);  //  ������ �� ���������
	show(lt);

	cout << "\n������ �������� �������� - ( ���� �� ������� ��� ������ �������� � ��������� ��������)";
	lt.remove_if(is_even);
	show(lt);

#endif // 0

#if 0

	// ���������� ������ ����������� ����������� ���������
	lt.assign(5, 10);
	show(lt);
	cout << endl << lt.size() << endl;

#endif // 0

#if 0


	// ����������� ������----------------------------------------------------

	cout << "\n����������� ������\n";
	list<int> sp;

	sp = lt;  // �������� ������������ - 1
	show(lt);

	cout << "\n����������� ����� ������\n";
	list<int> sp2;
	it = lt.begin();
	advance(it, 4);
	//cout << endl << *it << endl;

	sp.assign(it, lt.end());

	show(sp);

#endif // 0

#if 0

	// �������� �� ���� ���������---------------------------------------------
	cout << "\n�������� �� ���� ��������� ������\n";
	cout << "\nsize = " << lt.size() << endl;
	lt.clear();
	show(lt);
	cout << "\nsize = " << lt.size() << endl;

	auto it3 = lt.begin();
	lt.insert(it3, 200);
	show(lt);


#endif // 0


	//--------------------------------------------------------------------
#if 0

	list<string> fam = { "������","������","�������" };
	show(fam);


#endif // 0

	//--------------------------------------------------------------------
#if 0

	/*
	 ������������ ������ ������������ �������(string),
	 ����������� ���� ������ ����� ����������.
	 */


	list<string> tovar;
	string tmp;

	cout << "\n������� ��� ������������ ������ \n";
	for (int i = 0; i < 3; i++)
	{
		getline(cin, tmp);
		tovar.push_back(tmp);
	}

	//show(tovar);
	cout << "\n������ �������:\n";
	for (auto x : tovar)
		cout << x << endl;


#endif // 0


	//--------------------------------------------------------------------
#if 1

	// � ������ Person �������� MyString �� string
	// �������� ������ �����������, �������������������
	// �� ����� ���������� � ������� �� �����.

	list<Person> staff = { { "Ivan", "Borisov",30,180,75 },
							{ "Semen","Akimov", 25,160,55 },
							{ "Petr", "Petrov",28,170,69 } };
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}
	//
	////����������------------------------------------------
	// � ������ Person ����������� ���������� operator<
	staff.sort();


	cout << "\n---------sort by surname---------------\n";
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}


	cout << "\n----------sort by age-------------------\n";

	staff.sort(comp_age);
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}

	cout << "\n----------sort by surname decr-------------------\n";

	staff.sort(comp_surname_decr);
	for (auto v : staff)
	{
		//cout << v;
		v.show();
		cout << endl;
	}

#endif

	/* �����/������:

	+ ������� � �������� ����������� ����������: ���������� ������ ���������.

	- �� ������������ ������ �������������� �����:
	����� ������ � ������������� ��������, �������� �������� ��� ��������������.

	- ����� ����, � ������� �� �������, ������������� �����������
	������ ��� ��� ��������� �� ������ ������� ������.

	*/

	_getch();
}


/*
��������� �������� ��� ������ ������ �� ���������������� �����������:

-	���� ��������� ������������ ������ � ���������,
	������ ����������������;

-	���� ���������� ��������� �������� �������,
	����� ���������������� ������;

-	���� �� ������ ����� ����������� ��������� � �������
	�������� � ��������, ���������������� ������;

-	���� ��� �� ����� ����������� ��������� � �������
	�������� � ������ ����������, ������ ����������������, ��� deque.

	�������: ������������ ������� ������ �� ������� - ������
	����� �� ���� ��������� ������� ����� ������.
*/