#ifndef UCINETDL_FILEREADER_H
#define UCINETDL_FILEREADER_H
#include "File_reader.h"
#include <vector>
#include <tuple>


class UCINETDL_filereader : public File_reader
{
    private:

        int n; // No of nodes.

        vector<string> AVector; // E1
        vector<string> BVector; // E2
        vector<float> WVector;  // Weight
        
        vector<tuple<float,string>> NVector; // Nodes and their weights.

    public:

        UCINETDL_filereader(string file_name);
       
        void read_file();
        void write_file();
};


#endif