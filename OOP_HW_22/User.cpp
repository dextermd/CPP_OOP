#include "User.h"
#include <fstream>


User::User()
{
	this->login = "No Login";
	this->password = "No Password";
	this->name		= "No Name";
	this->surname	= "No Surname";
	this->email		= "No Email";
	this->phone		= "No Phone";
	this->address	= "No Address";
}

User::User(const MyString& login, const MyString& password, const MyString& name, const MyString& surname,
	const MyString& email, const MyString& phone, const MyString& address)
{
	this->login = login;
	this->password = password;
	this->name = name;
	this->surname = surname;
	this->email = email;
	this->phone = phone;
	this->address = address;
}

void User::show() const
{
	cout << "\nLogin:		" << this->login << endl;
	cout << "\Password:	" << this->password << endl;
	cout << "\Name:		" << this->name << endl;
	cout << "\Surname:	" << this->surname << endl;
	cout << "\Email:		" << this->email << endl;
	cout << "\Phone:		" << this->phone << endl;
	cout << "\Address:	" << this->address << endl;
	
}

void User::init(ListOneT<User>& data)
{
	char buf[256];
	do
	{
		cout << "\nInput login: ";
		cin.getline(buf, sizeof(buf));
		this->login = buf;

	} while (data.user_login_exist(this->login));


	cout << "\nInput password: ";
	cin.getline(buf, sizeof(buf));
	this->password = buf;

	cout << "\nInput name: ";
	cin.getline(buf, sizeof(buf));
	this->name = buf;

	cout << "\nInput surname: ";
	cin.getline(buf, sizeof(buf));
	this->surname = buf;

	cout << "\nInput email: ";
	cin.getline(buf, sizeof(buf));
	this->email = buf;

	cout << "\nInput phone: ";
	cin.getline(buf, sizeof(buf));
	this->phone = buf;

	cout << "\nInput address: ";
	cin.getline(buf, sizeof(buf));
	this->address = buf;

	ofstream save_file("user.txt", ios::app);
	if (save_file)
	{
		save_file << *this;
		data.add_begin(*this);
		save_file.close();
	}
	else {
		cout << "\nError writing file!";
	}

}

void User::signin(ListOneT<User>& data) const
{
	char buf[256];
	MyString tmp_str;
	cout << "\nPlease input login: ";
	cin.getline(buf, sizeof(buf));
	tmp_str = buf;
	if (data.user_login_correct(tmp_str))
	{
		cout << "\nPlease input password: ";
		cin.getline(buf, sizeof(buf));
		tmp_str = buf;

		if (data.user_password_correct(tmp_str))
		{
			cout << "\nLogin Successful!";
		}
	}
	else {
		cout << "\nLogin not exist.\n";
	}
	
}


void User::read_from_binary_file_plus(std::ifstream& in) const
{

}



ostream& operator<<(ostream& out, const User& user)
{
	out << "\nLogin:		" << user.login << endl;
	out << "\Password:	" << user.password << endl;
	out << "\Name:		" << user.name << endl;
	out << "\Surname:	" << user.surname << endl;
	out << "\Email:		" << user.email << endl;
	out << "\Phone:		" << user.phone << endl;
	out << "\Address:	" << user.address << endl;

	return out;
}

std::ostream& operator<<(std::ofstream& out, User& obj)
{
	int len;

	len = obj.login.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.login.get_str(), len + 1);

	len = obj.password.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.password.get_str(), len + 1);

	len = obj.name.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.name.get_str(), len + 1);

	len = obj.surname.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.surname.get_str(), len + 1);

	len = obj.email.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.email.get_str(), len + 1);

	len = obj.phone.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.phone.get_str(), len + 1);

	len = obj.address.getLength();
	out.write((char*)&len, sizeof(len));
	out.write(obj.address.get_str(), len + 1);

	return out;
}

std::istream& operator>>(std::ifstream& in, User& obj)
{
	int len;
	char buff[256];

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.login = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.password = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.name = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.surname = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.email = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.phone = buff;

	in.read((char*)&len, sizeof(len));
	in.read(buff, len + 1);
	obj.address = buff;

	return in;
}


User::~User()
{
}