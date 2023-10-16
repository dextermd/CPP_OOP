#pragma once
#include <iostream>
#include "FileSystemEntity.h"

using namespace std;

class File : public FileSystemEntity
{
private:
	int size;

public:

	File(string file_name, int file_size);

	void show() const override{
		cout << "File: " << name << "\t\t\tSize: " << size << " bytes" << endl;
	}

	int get_size() const override {
		return size;
	}

};

