#pragma once
#include "Directory.h"
class FileManager : public Directory
{
private:
    Directory root;

public:
    FileManager() : root("Root") {}

    void create_file(const string& file_name, int file_size);

    void create_directory(const string& dir_name);

    void show() const;

    bool delete_obj(const string& obj);
};

