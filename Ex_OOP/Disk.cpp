#include "Disk.h"
#include "File.h"
#include <iomanip>

void Disk::show() const
{
	if (disk_content.empty()) {
		cout << "\nДиск пуст!";
	}
	else {
		cout << "\n\t\t\tDisk: " << name << endl;
		cout << "---------------------------------------------------------\n";
		cout << left << setw(25) << "type" << setw(25) << "name" << setw(25) << "size" << setw(25) << endl << endl;
		for (const auto& value : disk_content)
		{
			value->show();
		}
		cout << "\n---------------------------------------------------------\n";
	}
}

int Disk::get_size() const
{
	return size;
}

void Disk::add_file(const string& format, const string& file_name, int size)
{
	File* file = new File(format, file_name, size);
	disk_content.insert(file);
}

void Disk::add_file(File* file)
{
	disk_content.insert(file);
}

void Disk::add_file_to_folder(const string& dest_folder, const string& format, const string& file_name, int size)
{
	Folder* target_folder = nullptr;
	
	for (const auto& entity : disk_content)
    {
        if (auto folder = dynamic_cast<Folder*>(entity))
        {
            if (folder->get_name() == dest_folder)
            {
                target_folder = folder;
                break;
            }
        }
    }

	if (target_folder)
	{
		File* new_file = new File(format, file_name, size);
		target_folder->add_file(new_file);
	}
	else {
		cout << "\nТакой папки не существует!";
	}
}

void Disk::add_folder(const string& folder_name, int size)
{
	Folder* folder = new Folder(folder_name, size);
	disk_content.insert(folder);
}


