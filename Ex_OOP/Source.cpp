#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <list>
#include "FileManager.h"
#include "File.h"
#include "Folder.h"
#include "Disk.h"


using namespace std;

int main()
{
	FileManager manager;
	manager.add_disk("C");
	manager.add_disk("D");
	manager.add_file_to_disk("C", "zip", "data", 1000);
	manager.show();
	
	//Disk* disk_c = new Disk("C");
	//Disk* disk_c = new Disk("D");

	//disk_c->add_file("rar", "demo_file", 10);
	//disk_c->add_file("txt", "demo_file2", 10);
	//disk_c->add_folder("demo_folder", 0);
	//disk_c->add_folder("demo_folder2", 0);
	//disk_c->add_folder("demo_folder3", 0);
	//disk_c->show();
	//disk_c->add_file_to_folder("demo_folder", "txt", "work-time", 20);
	//disk_c->show();

	_getch();
}