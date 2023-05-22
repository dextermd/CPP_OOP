#include <iostream>
#include "Student.h"

using namespace std;

void show(const Student& st)
{
	cout << "\nИмя:             " << st.name;
	cout << "\nФамилия:         " << st.surname;
	cout << "\nВуз:             " << st.vuz;
	cout << "\nДата рождения:   " << st.birthday.day << "." << st.birthday.month << "." << st.birthday.year;
	cout << "\nОценки :         ";

	for (int i = 0; i < 5; i++)
	{
		cout << st.marks[i] << " ";
	}

	cout << "\nСредний бал:     " << average(st);

	cout << endl;
}

void show(Student* m, int s)
{
	for (int i = 0; i < s; i++)
	{
		show(m[i]);
	}
}

void init(Student& data)
{
	cout << "\nИмя:              ";
	cin.getline(data.name, sizeof(data.name));
	cout << "\nФамилия:          ";
	cin.getline(data.surname, sizeof(data.surname));
	cout << "\nВуз:              ";
	cin.getline(data.vuz, sizeof(data.vuz));

	//cout << "\nДата рождения(день, месяцm год):     ";
	//cin >> data.birthday.day >> data.birthday.month >> data.birthday.year;

	cout << "\nДата рождения(день, месяцm год):    ";
	show(data.birthday, true);

	cout << "\nОценки(кол-во 5): ";
	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << ": ";
		cin >> data.marks[i];
	}


}

double average(const Student& data)
{
	double avg = 0;

	for (int i = 0; i < data.N; i++)
	{
		avg += data.marks[i];
	}

	return avg / data.N;
}

int find_student(Student* m, int size, const char* surname)
{
	for (int i = 0; i < size; i++)
	{
		//if (strcmp(m[i].surname, surname) == 0) // strcmp сравнивает два char
		if (_strcmpi(m[i].surname, surname) == 0)// _strcmpi сравнивает два char без учета регистра на латинице
		{
			return i;
		}
	}

	return -1;
}

Student best(Student* mas, int size)
{
	Student max;
	
	max = mas[0];
	for (int i = 1; i < size; i++)
	{
		if (average(mas[i]) > average(max))
		{
			max = mas[i];
		}
	}

	return max;
}

void show_best(Student* mas, int size)
{
	Student b = best(mas, size);
	double media = average(b);

	for (int i = 0; i < size; i++)
	{
		if (average(mas[i]) == media)
		{
			show(mas[i]);
		}
	}
}

bool show_vuz(Student* m, int size, const char* vuz)
{
	bool p = false; // Пусть такого вуза нет
	for (int i = 0; i < size; i++)
	{
		if (_strcmpi(m[i].vuz, vuz) == 0) // _strcmpi сравнивает два char без учета регистра на латинице
		{
			show(m[i]);
			p = true; // Студент найден
		}
	}

	return p;
}

bool search_sub_surname(Student* m, int size, const char* sub_surname)
{
	bool f = false;

	for (int i = 0; i < size; i++)
	{
		char* p = strstr(m[i].surname, sub_surname);
		if (p)
		{
			show(m[i]);
			f = true;
		}
	}
	
	return f;
}

bool search_sub_surname_d(Student* m, int size, const char* sub_surname)
{
	bool f = false;
	int count = strlen(sub_surname);

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < strlen(m[i].surname); k++)
		{
			for (int x = 0; x < count; x++)
			{
				if (m[i].surname[k] == sub_surname[x])
				{
					f = true;
				}
			}
		}
	}
	return f;
}

// booble sort
void sort_by_surname(Student* mas, int size)
{
	Student  temp;

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size - 1 - i; k++)
		{
			if (_strcmpi(mas[k].surname, mas[k + 1].surname) > 0) 
			{
				temp = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = temp;
			}
		}
	}
}

void sort_by_media(Student* mas, int size)
{
	Student  temp;

	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size - 1 - i; k++)
		{
			if (average(mas[k]) < average(mas[k + 1]))
			{
				temp = mas[k];
				mas[k] = mas[k + 1];
				mas[k + 1] = temp;
			}
		}
	}
}

// Функции для  критериев сортироваки для передачи в качестве параметров в шаблон функции сортироваки
bool cpm_by_year_decr(const Student& a, const Student& b)
{
	return a.birthday.year < b.birthday.year;
}

bool cpm_by_year_incr(const Student& a, const Student& b)
{
	return a.birthday.year > b.birthday.year;
}

bool cpm_by_media_incr(const Student& a, const Student& b)
{
	return average(a) > average(b);
}

bool cpm_by_media_decr(const Student& a, const Student& b)
{
	return average(a) < average(b);
}

