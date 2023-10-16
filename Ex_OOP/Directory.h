#pragma once
#include <iostream>
#include <map>
#include "FileSystemEntity.h"

using namespace std;

class Directory : public FileSystemEntity
{
private:
	map<string, FileSystemEntity*> directory_content;

public:
	Directory() {};
	Directory(const string& dir_name) : FileSystemEntity(dir_name) {};

	void show() const override {
		cout << "Directory: " << name << endl;
		
		for (const auto& value : directory_content) {
			value.second.show();
		}
	}

	int get_size() const override {
		int total_size = 0;
		for (const auto& value : directory_content) {
			total_size += value.second.get_size();
		}

		return total_size;
	}

};

