#ifndef FILE_READER_H
#define FILE_READER_H
#include <string>
using namespace std;
class File_reader
{
private:
    string file_name;

public:
    File_reader(string name);
    
    virtual void read_file() = 0;  //Read the file with the given file_name in the derived class and store the required info.
    virtual void write_file() = 0; //Modify the stored info, create a new file and write the new information in the file

protected:
    string get_filename();
};
#endif