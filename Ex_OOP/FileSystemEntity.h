#pragma once
#include <iostream>

using namespace std;

class FileSystemEntity
{

protected:
	string name;

public:

	FileSystemEntity() {};
	FileSystemEntity(const string& _name) : name(_name) {}

	virtual void show() const = 0;
	virtual int get_size() const = 0;
	virtual string get_name() const { return name; }

	virtual ~FileSystemEntity() = default;

};

