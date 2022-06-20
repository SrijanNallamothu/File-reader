#include "UCINETDL_Filereader.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <string>
#include <math.h>

UCINETDL_filereader :: UCINETDL_filereader(string file_name) : File_reader(file_name)
{
    read_file();
    write_file();
}

bool isInt(string str); // Checks whether the string is Int.
bool isFloat(string s); // Checks whether the string is float.

void UCINETDL_filereader :: read_file()
{
    ifstream Readfile(get_filename());
    
    string inp;

    getline(Readfile,inp);
    if(inp != ""){cerr << "Wrong file type";return;}

    getline(Readfile,inp);
    if(inp != "dl"){cerr << "Wrong file type";return;}

    getline(Readfile,inp);
    if(inp != "format=edgelist1"){cerr << "Wrong file type";return;}

    getline(Readfile,inp);
    if(inp != "labels embedded:"){cerr << "Wrong file type";return;}
	
    getline(Readfile,inp);
    if(inp.substr(0,2) != "n="){cerr << "Wrong file type";return;}
    if(!isInt(inp.substr(2,inp.length()))){cerr << "Wrong file type";return;}

    n = stoi(inp.substr(2,inp.length()));
    
    getline(Readfile,inp);
    if(inp != "data:"){cerr << "Wrong file type";return;}
    
    string E1,E2,W;

    while(Readfile.peek() != EOF){

    	if (Readfile >> E1 && Readfile >> E2 && Readfile >> W) 
    	{
     		
			if(!isFloat(W)){cerr << "Wrong Input type";return;}

        	AVector.push_back(E1);
        	BVector.push_back(E2);
        	WVector.push_back(stof(W));
    	}

    	else{
    		cerr << "Wrong file type";
    		return;
    	}

    }

    int l= AVector.size();

    for(int i=0;i<l;i++){

        int nN = NVector.size();
        int flag=0;

        if(nN==0){NVector.push_back(tuple<float,string>(WVector[i],AVector[i]));}
        else{

        	for(int j=0;j<nN;j++){
            	if(get<1>(NVector[j]).compare(AVector[i])==0){
                	get<0>(NVector[j]) = get<0>(NVector[j]) + WVector[i];
                	flag=1;
            	}            
        	}  
        

        	if(flag ==0){
        		NVector.push_back(tuple<float,string>(WVector[i],AVector[i]));
        
        	}
        }


        nN = NVector.size();
        flag=0;

        for(int j=0;j<nN;j++){
             if(get<1>(NVector[j]).compare(BVector[i])==0){
                get<0>(NVector[j]) = get<0>(NVector[j]) + WVector[i];
                flag=1;
            }    
                      
        } 

        if(flag ==0){
        NVector.push_back(tuple<float,string>(WVector[i],BVector[i]));
        
        } 

    }

    if(NVector.size()!=n){cerr << "There are " <<n<< " nodes "<<"but "<<NVector.size()<<" given" ;return;}

    sort(NVector.begin(), NVector.end());
    Readfile.close();
}

void UCINETDL_filereader :: write_file()
{
    
    
    ofstream Fileout("output.dl");
    Fileout <<endl;
    Fileout << "dl" << endl;
    Fileout << "format=edgelist1" << endl;
    Fileout << "labels embedded:" << endl;
    Fileout << "n=";
    Fileout << n << endl;
    Fileout << "data:" << endl;

    int NN =(NVector.size())-((NVector.size())/2);

    for(int i=(NVector.size()-1);i>(NN-1);i--){

    	for(int j=0;j<AVector.size();j++){

        	if(AVector[j].compare(get<1>(NVector[i]))==0){

            	for(int k=(NVector.size()-1);k>(NN-1);k--){

                	if(BVector[j].compare(get<1>(NVector[k]))==0){

                    	Fileout << AVector[j] <<" "<< BVector[j] <<" "<< WVector[j] << endl;
               		}
            	}
        	}
    	}
    }

    Fileout.close();
}

int main(){

    UCINETDL_filereader U = UCINETDL_filereader("input.dl");
}


bool isFloat(string s){
    istringstream iss(s);
    float dummy;
    iss >> noskipws >> dummy;
    return iss && iss.eof();     
}

bool isInt(string str){
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}
