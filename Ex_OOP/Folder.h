#pragma once
#include <iostream>
#include <set>
#include "FileSystemEntity.h"
#include "File.h"

using namespace std;

class Folder : public FileSystemEntity
{
private:
	set<FileSystemEntity*> folder_content;

public:
	Folder(const string& folder_name, int size) : FileSystemEntity(folder_name, size = 0) {};

	void show() const override;
	int get_size() const override;
	string get_name() const override { return name; };
	void add_file(File* file);
	
	Folder* find_folder(const string& folder_name);

	~Folder();

};

