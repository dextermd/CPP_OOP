#pragma once
#include <iostream>

using namespace std;

class FileSystemEntity
{

protected:
	string name;
	int size;

public:

	FileSystemEntity(const string& name, int size);

	virtual void show() const;
	virtual int get_size() const = 0;
	virtual string get_name() const = 0;

	virtual ~FileSystemEntity() {};

};

