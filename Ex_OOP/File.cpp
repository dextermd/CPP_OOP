#include "File.h"

File::File(string file_name, int file_size) : FileSystemEntity(file_name)
{
	size = file_size;
}
