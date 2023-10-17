#include "FileManager.h"

void FileManager::add_disk(const string& name)
{
	Disk* n_disk = new Disk(name);
	disks.push_back(n_disk);
}

const void FileManager::show() const
{
	for (const auto& disk : disks)
	{
		disk->show();
	}
}

void FileManager::add_file_to_disk(const string& disk_name, const string& format, const string& name, int size)
{
    for (auto& disk : disks)
    {
        if (disk->get_name() == disk_name)
        {
            File* new_folder = new File(format, name, size);
            disk->add_file(new_folder);
        }
    }
}
