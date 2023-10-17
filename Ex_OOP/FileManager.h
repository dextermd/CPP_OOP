#pragma once
#include <vector>
#include "Folder.h"
#include "Disk.h"
#include"FileSystemEntity.h"

class FileManager
{
private:
	vector<Disk*> disks;

public:
	
	void add_disk(const string& name);
	const void show() const;
	void add_file_to_disk(const string& disk_name, const string& format, const string& name, int size);
	//void add_folder_to_disk();
};

