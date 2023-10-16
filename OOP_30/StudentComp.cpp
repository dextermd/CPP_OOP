#include "StudentComp.h"
#include <iomanip>

//------------------------------------------------------------
StudentComp::StudentComp()
{
	this->surname = "no surname";// operator= MyString
	this->name = "no name";
	this->age = 0;
	this->vuz = "no vuz";
	this->marks.push_back(0);
}
//------------------------------------------------------------
StudentComp::StudentComp(const std::string& surname, const std::string& name, const int& age,
	const std::string& vuz, const std::vector<int>& marks, const std::list<std::string>& subjects)
{
	this->surname = surname;// operator= std::string
	this->name = name;
	this->age = age;
	this->vuz = vuz;
	this->marks = marks; //TODO
	this->subjects = subjects;
}
//------------------------------------------------------------
void StudentComp::take_subject(const std::string& sub)
{
	this->subjects.push_back(sub);
}
//------------------------------------------------------------
double StudentComp::get_average() const
{
	int val = 0;
	for (std::vector<int>::const_iterator it = this->marks.cbegin(); it != this->marks.cend(); ++it)
		val += *it;

	return double(val) / this->marks.size();
}
//------------------------------------------------------------
bool StudentComp::save_txt(std::ofstream& f)
{
	if (!f.is_open())
		return false;

	f << "\n\nФамилия:           " << this->surname;
	f << "\nИмя:               " << this->name;
	f << "\nВозраст:           " << this->age;
	f << "\nВуз:               " << this->vuz;
	f << "\nКол-во оценок:     " << (!this->get_average() ? 0 : this->marks.size());
	f << "\nОценки:            ";

	for (auto& v : this->marks)
		f << v << ' ';

	f << std::setprecision(2) << std::fixed;
	f << "\nСредний балл:      " << this->get_average();
	f << "\nКол-во предметов:  " << this->subjects.size();


	if (this->subjects.size())
	{
		f << "\nПредметы:          ";

		for (const auto& subj : this->subjects)
			f << subj << ' ';
	}
	f << std::endl;

	return true;
}
//------------------------------------------------------------
std::ostream& operator<<(std::ostream & out, const StudentComp& st)
{
	std::cout << "\n\nФамилия:           "<< st.surname;
	std::cout << "\nИмя:               "<< st.name;
	std::cout << "\nВозраст:           "<< st.age;
	std::cout << "\nВуз:               "<<st.vuz;
	std::cout << "\nКол-во оценок:     "<< (!st.get_average() ? 0 : st.marks.size());
	std::cout << "\nОценки:            ";

	for (auto& v : st.marks)
		std::cout << v << ' ';

	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "\nСредний балл:      " << st.get_average();
	std::cout << "\nКол-во предметов:  " << st.subjects.size();


	if (st.subjects.size()) 
	{
		std::cout << "\nПредметы:          ";

		for (const auto& subj : st.subjects)
			std::cout << subj << ' ';
	}
	std::cout << std::endl;

	return out;
}
//------------------------------------------------------------
std::ofstream& operator<<(std::ofstream& fout, const StudentComp& obj)
{
	if (!fout.is_open())
		throw std::invalid_argument("File can't be open");

	size_t size = obj.surname.length();
	fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));
	fout.write(obj.surname.data(), size);

	size = obj.name.length();
	fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));
	fout.write(obj.name.data(), size);

	fout.write(reinterpret_cast<const char*>(&obj.age), sizeof(int));

	size = obj.vuz.length();
	fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));
	fout.write(obj.vuz.data(), size);

	size = obj.marks.size();
	fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));

	for (const auto& mark : obj.marks)
		fout.write(reinterpret_cast<const char*>(&mark), sizeof(int));

	size = obj.subjects.size();
	fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));

	for (std::list<std::string>::const_iterator it = obj.subjects.cbegin(); it != obj.subjects.cend(); ++it)
	{
		size = it->length();
		fout.write(reinterpret_cast<char*>(&size), sizeof(size_t));
		fout.write(it->data(), size);
	}

	return fout;
}
//------------------------------------------------------------
std::ifstream& operator>>(std::ifstream& fit, StudentComp& obj)
{
	if (!fit.is_open())
		throw std::invalid_argument("File can't be open");

	size_t size;
	fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	obj.surname.resize(size);
	//fit.read(obj.surname.data(), size);
	fit.read(const_cast<char*>(obj.surname.data()), size);

	fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	obj.name.resize(size);
	//fit.read(obj.name.data(), size);
	fit.read(const_cast<char*>(obj.name.data()), size);

	fit.read(reinterpret_cast<char*>(&obj.age), sizeof(int));

	fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	obj.vuz.resize(size);
	//fit.read(obj.vuz.data(), size);
	fit.read(const_cast<char*>(obj.vuz.data()), size);

	fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));
	obj.marks.resize(size);
	fit.read((char*)obj.marks.data(), sizeof(int) * size);

	fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));

	while (obj.subjects.size() != size)
	{
		std::size_t size;
		std::string str;
		
		fit.read(reinterpret_cast<char*>(&size), sizeof(size_t));// читаем размер строки
		str.resize(size);
		fit.read(const_cast<char*>(str.data()), size);// читаем строку
		obj.subjects.push_back(str);

		str.clear();
	}

	return fit;
}
//------------------------------------------------------------
bool operator<(const StudentComp& a, const StudentComp& b)
{
	return a.surname < b.surname;
}

////------------------------------------------------------------
//bool StudentComp::operator<(const StudentComp& a)
//{
//	return this->surname < a.surname;
//}
