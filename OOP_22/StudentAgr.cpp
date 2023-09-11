#include "StudentAgr.h"

StudentAgr::StudentAgr()
{
	this->surname = "no surname";
	this->name = "no name";
	this->age = 0;
	this->vuz = "no vuz";
	this->marks = 0u; //unsigned int   //MyArray(unsigned int size, int val = 0);

}

StudentAgr::StudentAgr(const MyString& surname, const MyString& name, 
	int age, const MyString& vuz, const MyArray& marks, 
	const ListOneType<MyString>& subjects)
{
	this->surname = surname;
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks;
	this->subjects = subjects;
}

ostream& operator<<(ostream& out, const StudentAgr& student)
{
	out << "\nФамилия:  " <<student.surname << endl;
	out << "Имя:      " << student.name << endl;
	out << "Возраст:  " << student.age << endl;
	out << "Вуз:      " << student.vuz << endl;
	if (student.marks.get_size())
	{
		out << "Кол-во оценок :  " << student.marks.get_size() << endl;
		out << "Оценки :  " << student.marks << endl;
		out << "Средний балл :  " << student.get_average() << endl;
	}
	else {
		out << "Оценок нет" << endl;
	}

	//out << student.subjects << endl;
	out << "Предметы :";
	student.subjects.show();

	return out;
}

void StudentAgr::add_subject(const MyString & data)
{
	this->subjects.add_begin(data);
}

bool StudentAgr::operator<(const StudentAgr& student)
{
	return this->surname < student.surname;
}

void StudentAgr::save_txt(FILE* f) const
{
	fprintf(f, "\nФамилия          :  %s", this->surname.get_str());
	fprintf(f, "\nИмя              :  %s", name.get_str());
	fprintf(f, "\nВозраст          :  %d", this->age);
	fprintf(f, "\nВуз              :  %s", this->vuz.get_str());
	fprintf(f, "\nКол-во оценок    :  %d", this->marks.get_size());

	if (marks.get_size()) {
		fprintf(f, "\nОценки           :  ");
		for (int i = 0; i < this->marks.get_size(); i++)
		{
			fprintf(f, "%d  ", this->marks[i]);
		}
		fprintf(f, "\nСредний балл     :  %.2f", this->get_average());
	}
	fprintf(f, "\nКол-во предметов :  %d", this->subjects.get_count());
	if (subjects.get_count())
	{
		fprintf(f, "\nПредметы         :  ");
		for (int i = 1; i <= subjects.get_count(); i++)
		{
			fprintf(f, "%s  ", subjects.get_by_pos(i).get_str());
		}
	}
	fprintf(f, "\n");
}


void StudentAgr::save_to_binary_file(FILE* f)
{
	surname.save_to_binary_file(f);
	name.save_to_binary_file(f);
	fwrite(&this->age, sizeof(this->age), 1, f);
	vuz.save_to_binary_file(f);
	marks.save_to_binary_file(f);
	subjects.save_to_binary_file(f);

	//int count = this->subjects.get_count();
	//fwrite(&count, sizeof(count), 1, f);

	//for (int i = 1; i <= count; i++)
	//{
	//	// Запись длины строки
	//	int len = this->subjects.get_by_pos(i).getLength();
	//	fwrite(&len, sizeof(len), 1, f);
	//	// Запись содержимого строки
	//	fwrite(this->subjects.get_by_pos(i).get_str(), len + 1, 1, f);
	//}
}
void StudentAgr::read_from_binary_file(FILE* f)
{
	surname.read_from_binary_file(f);
	name.read_from_binary_file(f);
	fread(&this->age, sizeof(this->age), 1, f);
	vuz.read_from_binary_file(f);
	marks.read_from_binary_file(f);
	subjects.read_from_binary_file(f);
}

void StudentAgr::save_to_binary_file2(FILE* f)
{
	// Запись длины строки
	int len = this->surname.getLength();
	fwrite(& len, sizeof(len), 1, f);
	// Запись содержимого строки
	fwrite(this->surname.get_str(), this->surname.getLength() + 1, 1, f);

	len = this->name.getLength();
	fwrite(&len, sizeof(len), 1, f);
	// Запись содержимого строки
	fwrite(this->name.get_str(), this->name.getLength() + 1, 1, f);

	fwrite(&this->age, sizeof(this->age), 1, f);

	len = this->vuz.getLength();
	fwrite(&len, sizeof(len), 1, f);
	// Запись содержимого строки
	fwrite(this->vuz.get_str(), this->vuz.getLength() + 1, 1, f);

	len = this->marks.get_size();
	fwrite(&len, sizeof(len), 1, f);
	// Запись содержимого строки
	fwrite(this->marks.get_ptr(), this->marks.get_size()*sizeof(int), 1, f);

	int count = this->subjects.get_count();
	fwrite(& count, sizeof(count), 1, f);
	
	for (int i = 1; i <= count; i++)
	{
		// Запись длины строки
		len = this->subjects.get_by_pos(i).getLength();
		fwrite(&len, sizeof(len), 1, f);
		// Запись содержимого строки
		fwrite(this->subjects.get_by_pos(i).get_str(), len + 1, 1, f);
	}
}


void StudentAgr::read_from_binary_file2(FILE* f)
{
	int len;
	fread(&len, sizeof(len), 1, f);
	// setLength - освобождаем старую память, задаем новую длину и выделяем новую память
	this->surname.setLength(len);
	// читаем содержимое строки
	fread(this->surname.get_str(), len + 1, 1, f);

	fread(&len, sizeof(len), 1, f);
	this->name.setLength(len);
	fread(this->name.get_str(), len + 1, 1, f);

	fread(&this->age, sizeof(this->age), 1, f);

	fread(&len, sizeof(len), 1, f);
	this->vuz.setLength(len);
	fread(this->vuz.get_str(), len + 1, 1, f);

	fread(&len, sizeof(len), 1, f);
	this->marks.set_size(len);
	fread(this->marks.get_ptr(), len*sizeof(int), 1, f);

	int count;
	fread(&count, sizeof(count), 1, f);

	for (int i = 1; i <= count; i++)
	{
		fread(&len, sizeof(len), 1, f);
		MyString sub;
		sub.setLength(len);
		fread(sub.get_str(), len + 1, 1, f);
		this->subjects.add_end(sub);
	}
}