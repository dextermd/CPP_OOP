#include "FileSystemEntity.h"
#include <iomanip>
#include "Folder.h"

FileSystemEntity::FileSystemEntity(const string& name, int size)
{
	this->name = name;
	this->size = size;
}

void FileSystemEntity::show() const
{

}

