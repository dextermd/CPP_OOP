#pragma once
#include <iostream>
#include "FileSystemEntity.h"

using namespace std;

class File : public FileSystemEntity
{
private:
	string format;

public:

	File(const string& format, const string& name, int size = 0);
	void show() const override;
	int get_size() const override;
	string get_name() const override { return name; };
};

