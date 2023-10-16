#include <iostream>
#include <conio.h>
#include "coord.h"
#include "person.h"
#include<iomanip>
#include <map>
#include <set>
#include <vector>
#include "Coord.h"

using namespace std;
//------------------------------------------------------------------------

// �������� ����������� ������� , �.�. ��������� ��� ��������� � ���������� bool
bool comp(const string& a, const string& b)
{
	return a > b;
}

//------------------------------------------------------------------------
// �������� - ��� ��������� ��� �����, � ������� ���� ���������� operator() 
// � ������������ bool
struct Compare {

	bool operator()(const string& a, const string& b)const
	{
		return a > b;
	}
};

//------------------------------------------------------------------------
bool cmp_person(const Person& a, const Person& b)
{
	return a.get_surname() > b.get_surname();
}

//------------------------------------------------------------------------
struct CmpPerson {

	bool operator()(const Person& a, const Person& b)const
	{
		return a.get_surname() > b.get_surname();
	}
};
//------------------------------------------------------------------------


int main()
{
	system("chcp 1251>nul");
	system("color 1F");

	/*
	������������� ����������:

	- map     (�����������, �����)
		����� �� set, �� �������� �������� � ���� std::pair
		���� - pair.first, �������� - pair.second
		������������ ������ ������ �� ����� - at() � []
		������, ����� �������� ���� �� ��������, � ����� ��������� ��� ��������.

	- multimap
		���������� multiset
		�� ������������ ������ ������ �� �����
*/

//����������� - map-------------------------------------------------------
/*
������� �������������:
- ������-����. �������. ���� -������� �����, �������� � ���������� �������
- ����� ����. ���� - ������������ ������, �������� � ���� ������
- ��������. ���� - �����, �������� - ���������� ������� ��� ������ �������.
*/

#if 0

	map<int, int> m;
	cout << m.size() << endl;

	//m.insert(2, -2);// error

	m.insert(pair<int, int>(2, -2));
	m.emplace(10, 6);
	m.insert(make_pair(5, 50));
	m.emplace(-10, 6);

	m[-5] = 500;
	m[3];

	m.at(10) = 100;//+ exception   �������� �� ����� ��������
	m[10] = 50;// �������� �� ����� ��������

	m.emplace(10, 1000);// �������� �� ����� �� ��������
	m.emplace(1, 1000);

	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	cout << "���������� �������� �� �����: " << m.count(10) << endl;
	cout << "���������� �������� �� �����: " << m.count(300) << endl;



#endif


	// ���������� ���������: []----------------------------------------------
#if 0

	cout << m[-5] << endl;// 0

	cout << m[100] << endl << endl;// �� ����� 100 ������������ 0

	m[50];// �� ����� 50 ������������ 0

	m[45] = 200;
	m[45] = 400;// ���� ��������, �������� ��������������
	m.at(45) = 100;

	auto r = m.emplace(7, 500);// ���� ��������, �������� �� ��������

	if (r.second)
	{
		cout << "\n�������� ���������\n";
	}
	else {
		cout << "\n�������� �� ���������\n";
	}
	// ������ �� ��������� map      ---------------------------------------
	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}



#endif // 0

#if 0


	/*auto*/map<int, int>::iterator it = m.begin();

	cout << endl << it->first << "  " << (*it).second << endl;
	++it;
	cout << endl << it->first << "  " << (*it).second << endl;
	//it += 3;//error
	advance(it, 3);
	cout << endl << it->first << "  " << it->second << endl;

	cout << "\nsize: " << m.size() << endl << endl;

	// ������ �� ��������� map      ---------------------------------------
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		cout << it->first << "  " << (*it).second << endl;
	}

	//  ���������� ��������� � ������: count---------------------------------
	cout << "\n���������� ��������� � ������ -5:  " << m.count(-5);
	cout << "\n���������� ��������� � ������ 150:  " << m.count(150);

#endif // 0


	// ����� �������� �� �����: find------------------------------------------
#if 0


	it = m.find(3);

	if (it != m.end())
	{
		cout << "\n��������� ������: " << it->first << "  " << it->second;
		cout << "\n�������(������): " << distance(m.begin(), it) << endl;
	}
	else {
		cout << "\n������� �� ������";
		// ��������� �������
		--it;
		cout << "\n" << it->first << "  " << it->second;
	}

#endif // 0

	//-----------------------------------------------------------------------
	// �������� ��������� �� map

	// �������� ������ �������� �� map �� ����� ---------------------------
#if 0

	cout << "\n��������------------------\n";
	cout << m.erase(45) << endl;


	if (m.count(-5))
	{
		cout << "\n������� ������: " << m.erase(-5) << endl; // �������� �� ��������
	}
	else {
		cout << "\n�������� ��� � map\n";
	}

	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}


	it = m.find(10);
	if (it != m.end())
	{
		it = m.erase(it);// �������� �� ���������

		if (it != m.end()) {
			cout << "\n������� ������, ��������� ���������:  " << (*it).first << endl;
			cout << "\n�������(������): " << distance(m.begin(), it) << endl;// �� ��������� ��������
		}
	}
	else {
		cout << "\n�������� ��� � map";
	}


	cout << endl << endl;
	for (auto v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

#endif // 0


	//-----------------------------------------------------------------------
	//��������������:  ������� ���� � ������� ������� � map------------------


#if 0
	map<int, int> m;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];
	m[-40] = 5;
	m[240] = 5;

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	for (auto it = m.begin(); it != m.end(); /*++it*/)
	{
		if (!(it->first % 2))
		{
			it = m.erase(it);// 
		}
		else {
			++it;
		}
	}


	cout << "\nmap ����� �������� ��� � ������� �������: \n";
	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}



	//int a = 10;
	//int* p = &a;

	////int c = ++(* p)  - (* p)++ / 2 + a;// 11-5+11=17
	////cout << "\nc = "<< c << endl;

	//a = (*p)++ - (*p)++ / 2 + a;// 10-5+10=15
	//cout << "\na = " << a << endl;



#endif // 0

	//-----------------------------------------------------------------------
	// �������� ���������� ��������� �� map �� ��������----------------------
	/*
		lower_bound(key) - �������� �� ������ �������, ��� ���� ������ ��� ����� ���������� �����;
		upper_bound(key) - �������� �� ������ �������, ��� ���� ������ ���������� �����;
		(key ������ ���� ������ �������� ���������� ��������)
	*/
#if 0

	map<int, int> m;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];//  

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	auto lm = m.lower_bound(5);
	cout << "\nlm = " << lm->first << "  " << lm->second << endl;

	//auto um = m.upper_bound(200); //! key ������ ���� ������ �������� ���������� ��������)
	auto um = m.upper_bound(24);
	cout << "\num = " << um->first << "  " << um->second << endl;

	m.erase(lm, um);

	cout << "\nmap ����� �������� �� ��������: \n";
	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}


#endif // 0

	//-----------------------------------------------------------------------
	// ����������� map
#if 0


	map<int, int> m;
	map<int, int> m2;

	m.insert(pair<int, int>(10, 15));
	m.emplace(-5, 5);
	m.emplace(4, 5);
	m.insert(make_pair(-25, 16));
	m[20] = 358;
	m[24] = 12;
	m[31];
	m[7] = 300;
	m[26] = 15;
	m[-30] = 1;
	m[200];//  

	for (const auto& v : m)
	{
		cout << v.first << "  " << v.second << endl;
	}

	m2 = m; // ������� 1 operator=
	cout << endl;
	for (const auto& v : m2)
	{
		cout << v.first << "  " << v.second << endl;
	}

	//auto i1 = m.begin();
	//auto i2 = m.begin();
	//advance(i1, 3);
	//advance(i2, 7);// �� ������

	//map<int, int>m3(i1,i2);
	//cout << endl<< endl << endl;
	//for (const auto& v : m3)
	//{
	//	cout << v.first << "  " << v.second << endl;
	//}



	//auto lb = m.lower_bound(3);
	//auto ub = m.upper_bound(24);// ������������

	//map<int, int> m4(lb, ub);

	//cout << endl << endl << endl;
	//for (const auto& v : m4)
	//{
	//	cout << v.first << "  " << v.second << endl;
	//}

#endif // 0

	//-----------------------------------------------------------------------
	// ������: ���������� ���������� �������----------------------------------



	// ������� 1 - � ���������� �������, �� ���������------------------------


#if 0
	map<  string, string  > mt{ {"����", "069874213"}, { "����","069325987" } };

	mt["����"] = "079654789";
	mt["����"] = "060654189";
	mt["����"] = "079888888";// �������� ���������
	mt["�����"] = "079654111";
	mt["������"] = "068654789";

	mt.emplace("�����", "060457895");// �������� �� ���������
	mt.emplace("�����", "062222222");

	cout << "\n���������� ���������:\n";
	for (auto v : mt)
	{
		cout << v.first << "  " << v.second << endl;
	}
	cout << endl << endl;
#endif


	// ������� 2 - � �������� ���������� ������� �� ��������� -----------------

#if 0

		//bool (*)(const string&, const string&) - ��������� �� ����������� ������� - v1

		//map<   string, string, bool (*)(const string&, const string&)   > mt(comp);

	map<string, string, Compare> mt;//compare - ������ - ��������  v2

	mt.emplace("����", "069874213");
	mt.emplace("����", "069325987");

	mt["����"] = "079654789";
	mt["����"] = "060654189";
	mt["����"] = "079888888";// �������� ���������
	mt["�����"] = "079654111";
	mt["������"] = "068654789";

	mt.emplace("�����", "060457895");// �������� �� ���������
	mt.emplace("�����", "062222222");

	cout << "\n���������� ���������:\n";
	for (auto v : mt)
	{
		cout << v.first << "  " << v.second << endl;
	}

#endif // 0

	//--------------------------------------------------------------------
	//��������������: 

	/*
	��������� ��������� map ����������� ������� �� ���� / ���� ������,
	���� � ���������� ����� � ���� �������� � ������� �� ��� �����.

	�������� map, ������������������� �� ����� ����������,
	������� �� �����.

	�������� ����������� ����� ������ � ����������.
	*/


#if 0

	map<string, pair<string, string>> voc;

	voc.emplace("�����", make_pair("pear", "pere"));
	voc.emplace("������", pair<string, string>("apple", "mar"));
	voc.emplace("��������", make_pair("orange", "portocala"));
	cout << endl;

	for (auto v : voc)
	{
		cout << left << setw(15) << v.first << setw(15) << v.second.first
			<< setw(15) << v.second.second << endl;
	}


#endif // 0

	//--------------------------------------------------------------------
	/*
	 ������: ��� �������� ���?
	 ���������� ���������� �������� ������� - ��������� �������
	*/
#if 0

	vector<int> v{ 25, -9, 25, 9, 5, 7, 8, 5, 25, 3, 25, 9, 7, 7, 7, 25, 9 };
	map<int, int> count;

	for (auto x : v)
	{
		cout << x << "  ";
		count[x]++;
	}

	cout << endl;

	count[10];//0
	count[10]++;//1
	count[10]++;//2
	count[25]++;//6
	for (auto v : count)
	{
		cout << v.first << "\t" << v.second << endl;
	}


#endif // 0

	//--------------------------------------------------------------------
	// �������� map �� ��������� � ������ ���� ����������������� ������
	// � ���������������� ������ ��� ����� ����������� ����������� �������� <.
#if 0

	// ������: ������� map � ����� Person(����) � coord.
	{
		map<Person, Coord> mp;

		Person a("Ivanov", "Ivan", 20, 180, 75);
		Person b("Borisov", "Anton", 18, 170, 65);
		Person c("Aromov", "Alex", 25, 175, 65);

		mp[a] = Coord(25, 9);
		mp[b] = { -5,9 };
		mp[c] = "12,6";

		mp.emplace(make_pair(Person("Domov", "Alex", 21, 175, 65), Coord(2, -3)));

		for (auto v : mp)
		{
			v.first.show();
			cout << " -> " << v.second << endl;
		}
	}

#endif
	//-----------------------------------------------
	//������� 2 (� �������� ���������� �������)
#if 0
	// ���� ������ ���� ����������

	{
		//map<Person, Coord, bool(*)(const Person&, const Person&)> mp(cmp_person);    // cmp_person - ����������� �������
		map<Person, Coord, CmpPerson> mp;//cmpPerson - ��������


		Person a("Ivanov", "Ivan", 20, 180, 75);
		Person b("Borisov", "Anton", 18, 170, 65);
		Person c("Aromov", "Alex", 25, 175, 65);

		mp[a] = Coord(25, 9);
		mp[b] = { -5,9 };
		mp[c] = "25,-25";

		mp.emplace(make_pair(Person("Domov", "Alex", 21, 175, 65), Coord(2, -3)));
		cout << endl << "============================" << endl;
		for (auto v : mp)
		{
			v.first.show();
			cout << " -> " << v.second << endl;
		}
	}
#endif // 0

	//-----------------------------------------------
	/* ����������:

	���������� ��� ����������� �� ��� ��������� ����������
	(����������� ��� �������� ������ ���������������� �������).
	���  ���  ������ ���� ����������:
		-	�������� =
		-	�������� <
		-	�������� �� ���������
			(��� ������ ��� �������� ������� ������������ �� ���������).
	*/


	//-----------------------------------------------------------------------
	// ������: ���������� ������---------------------------------------------
#if 0

	map <string, string> Capitals;
	string country, city;

	Capitals["Russia"] = "Moscow";
	Capitals["Ukraine"] = "Kiev";
	Capitals["USA"] = "Washington";

	cout << "� ����� ������ �� ������? ";
	getline(cin, country);
	//cin >> country;

	// ��������, ���� �� ����� ������ � ������� Capitals
	if (Capitals.count(country))
	{
		// ���� ���� - ������� �� �������
		cout << "������� ����� ������ " << Capitals[country] << endl;
	}
	else
	{
		// �������� �������� ������� � ������� ��� � �������
		cout << "��� ���������� ������� ����� ������? ";
		cin >> city;
		Capitals[country] = city;
	}
	cout << endl;

	for (auto it = Capitals.begin(); it != Capitals.end(); ++it) {
		cout << setw(10) << left << "\n������:" << setw(12)
			<< (*it).first << setw(10) << "- �������: " << setw(12)
			<< it->second;
	}


#endif // 0
	//===============================================================
	// multimap
#if 1


	multimap<string, int> mlt;
	mlt.insert(pair<string, int>("������", 20));
	mlt.insert(pair<string, int>("������", 23));
	mlt.insert(pair<string, int>("�������", 18));
	mlt.insert(pair<string, int>("������", 21));
	mlt.insert(pair<string, int>("������", 51));

	mlt.emplace("������", 15);
	// mlt.insert("������", 15); //  error
	mlt.insert(pair<string, int>("������", 45));

	cout << endl;

	for (auto x : mlt)
	{
		cout << x.first << "    " << x.second << endl;
	}
	cout << endl;

	cout << "\n������� ��������(�� �����): " << mlt.count("������") << endl;

	// ����� � ������� ��� �������� �� ����� "������"
	// �������� ��� �������� � ������ 

	auto pr = mlt.equal_range("������");

	if (pr.first != pr.second) {
		for (auto it = pr.first; it != pr.second; ++it) {
			cout << it->first << "->" << it->second << endl;
		}
	}
	else {
		cout << "\n�������� �� �������";
	}

#endif // 0
	_getch();
	return 0;
}

//===============================================================
/* �����/������:

map ������� �� ��� ����/��������, ������ ���� ������������ ��� ������ ��������,
� �������� �������� �������� ���������� (��������, ���������� ����������)

+ ���� ����� ������������ ��� �������� ������ �������� �� �����.
		������� ����� �������� �� ����� �������������� ��������� ����,
		��� ���� �������� � ��������������� ����.

- ���������� � �������� ������� ����� ���� �������
  ��������������� ���������� ���������, ����������� � ������.

- ���� ������ ���� ����������.

*/