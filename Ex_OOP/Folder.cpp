#include "Folder.h"
#include <iomanip>


void Folder::show() const
{
	//cout << left << setw(25) << "folder" << setw(25) << name << setw(25) << size << setw(25) << endl;
	//for (const auto& value : folder_content)
	//{
	//	cout << "-- " << value;
	//}

    cout << left << setw(25) << "folder" << setw(25) << "[" + name + "]" << setw(25) << size << setw(25) << endl;

    for (const auto& entity : folder_content) {
        if (dynamic_cast<Folder*>(entity)) {
            entity->show();
        }
    }
}

int Folder::get_size() const
{
	int total_size = 0;
	return total_size;
}

void Folder::add_file(File* file)
{
    folder_content.insert(file);
    size += (*file).get_size();
}

Folder* Folder::find_folder(const string& folder_name)
{
    if (name == folder_name)
    {
        return this;
    }

    for (const auto& entity : folder_content)
    {
        if (auto folder = dynamic_cast<Folder*>(entity))
        {
            Folder* found_folder = folder->find_folder(folder_name);
            if (found_folder != nullptr)
            {
                return found_folder;
            }
        }
    }

    return nullptr;
}

Folder::~Folder()
{

}

