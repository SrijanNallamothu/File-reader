#include "File_reader.h"
#include <string>
File_reader ::File_reader(string name)
{
    file_name = name;
}

string File_reader::get_filename()
{
    return file_name;
}