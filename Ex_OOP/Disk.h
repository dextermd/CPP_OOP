#pragma once
#include <iostream>
#include <vector>
#include "Folder.h"

using namespace std;

class Disk : public FileSystemEntity
{
private:
	set<FileSystemEntity*> disk_content;

public:
	Disk(const string& disk_name, int size = 0) : FileSystemEntity(disk_name, size) {};
	void show() const override;
	int get_size() const override;
	string get_name() const override { return name; };
	void add_file(const string& format, const string& file_name, int size);
	void add_file(File* file);
	void add_file_to_folder(const string& dest_folder, const string& format, const string& file_name, int size);
	void add_folder(const string& folder_name, int size);

};

