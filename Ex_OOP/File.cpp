#include "File.h"
#include <iomanip>

File::File(const string& format, const string& name, int size) : FileSystemEntity(name, size)
{
	this->format = format;
}

void File::show() const
{
	cout << left << setw(25) << "file" << setw(25) << name + "." + format << setw(25) << size << setw(25) << endl;
}

int File::get_size() const
{
	return size;
}


