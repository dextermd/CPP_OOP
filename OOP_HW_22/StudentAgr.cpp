#include "StudentAgr.h"

StudentAgr::StudentAgr()
{
	this->surname = "no surname";
	this->name = "no name";
	this->age = 0;
	this->vuz = "no vuz";
	
}

StudentAgr::StudentAgr(const MyString& surname, const MyString& name, int age, const MyString& vuz, const MyArray& marks, const ListOneT<MyString>& subjects)
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
	out << "\nSurname:	" << student.surname << endl;
	out << "\Name:		" << student.name << endl;
	out << "\Age:		" << student.age << endl;
	out << "\Vuz:		" << student.vuz << endl;
	if (student.marks.avarage_array())
	{
		out << "Count Marks:	" << student.marks.get_size() << endl;
		out << "Marks:		" << student.marks;
		out << "MarksAverage:	" << student.get_average() << endl;
	}
	else {
		out << "Empty Marks " << endl;
	}
	//out << "Subjects:		" << student.subjects << endl;
	out << "Subjects:	";
	student.subjects.show();

	return out;
}

std::ostream& operator<<(std::ofstream& out, StudentAgr& obj)
{
	int len;
	int marks_size;

	len = obj.surname.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.surname, len + 1);

	len = obj.name.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.name, len + 1);

	out.write((char*)&obj.age, sizeof(obj.age));

	len = obj.vuz.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.vuz, len + 1);

	marks_size = obj.marks.get_size();
	out.write((char*)&marks_size, sizeof(marks_size));
	out.write((char*)obj.marks.get_ptr(), sizeof(obj.marks.get_ptr()) * marks_size);

	int count = obj.subjects.get_count();
	out.write((char*)&count, sizeof(count));

	for (int i = 1; i <= count; i++)
	{
		len = obj.subjects.get_by_pos(i).getLength();
		out.write((char*)&len, sizeof(len));
		out.write(obj.subjects.get_by_pos(i).get_str(), len + 1);
	}


	return out;
}

std::istream& operator>>(std::ifstream& in, StudentAgr& obj)
{
	int len;
	int marks_size;

	in.read((char*)&len, sizeof(len));
	in.read(obj.surname, len + 1);

	in.read((char*)&len, sizeof(len));
	in.read(obj.name, len + 1);


	in.read((char*)&obj.age, sizeof(obj.age));

	in.read((char*)&len, sizeof(len));
	in.read(obj.vuz, len + 1);

	in.read((char*)&marks_size, sizeof(marks_size));
	obj.marks.set_size(marks_size);
	in.read((char*)obj.marks.get_ptr(), sizeof(obj.marks.get_ptr()) * marks_size);

	int count;
	in.read((char*)&count, sizeof(count));

	for (int i = 1; i <= count; i++)
	{
		in.read((char*)&len, sizeof(len));
		MyString sub;
		sub.setLength(len);
		in.read(sub.get_str(), len + 1);
		obj.subjects.add_end(sub);
	}

	return in;
}

void StudentAgr::add_subject(const MyString& data)
{
	this->subjects.add_begin(data);
}

bool StudentAgr::operator<(const StudentAgr& student)
{
	return this->surname < student.surname;
}

void StudentAgr::save_txt(FILE* f) const
{

	fprintf(f, "\n\nSurname		: %s \n", this->surname.get_str());
	fprintf(f, "Name		: %s \n", this->name.get_str());
	fprintf(f, "Age		: %d \n", this->age);
	fprintf(f, "Vuz		: %s \n", this->vuz.get_str());

	if (marks.avarage_array())
	{
		fprintf(f, "Count Marks	: %d\n", this->marks.get_size());
		fprintf(f, "Marks		: ");

		for (int i = 0; i < this->marks.get_size(); i++)
		{
			fprintf(f, "%d ", this->marks[i]);
		}

		fprintf(f, "\nAverage Marks	: %f \n", this->get_average());
	}

	fprintf(f, "Subjects	: ");

	for (int i = 1; i <= subjects.get_count(); i++)
	{
		fprintf(f, "%s ", this->subjects.get_by_pos(i).get_str());
	}

	//printf("\nOk\n\n");
}


double StudentAgr::get_average() const
{
	return this->marks.avarage_array();
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

void StudentAgr::save_to_file_plus(std::ostream& fout) const
{
	fout << "Surname				: " <<  this->surname.get_str() << endl;
	fout << "Name				: " <<  this->name.get_str() << endl;
	fout << "Age					: " << this->age << endl;

	if (marks.avarage_array())
	{
		fout << "Count Marks			: " << this->marks.get_size() << endl;

		fout << "Marks				: ";

		for (int i = 0; i < this->marks.get_size(); i++)
		{
			fout << this->marks[i] << " ";
		}

		fout << "\nAverage Marks		: " << this->get_average() << endl;
	}

	fout << "Subjects			: ";

	for (int i = 1; i <= subjects.get_count(); i++)
	{
		fout << this->subjects.get_by_pos(i).get_str() << " ";
	}

}
