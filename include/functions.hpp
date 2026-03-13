#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

// declaration of all functions

#include "Student.hpp"

#include <string>

using namespace std;

int menu ();

void read1 (string&,int&,string&,string&);
void read2 (string&,string&,int&,int&);

int st_appear (const string);

void write_file (Student&,const string&);

int search_ID_number (const string,string&);

int delete_student (string,const string&);

void change_enumeration (int,const string);

void update_elements (string,string,string,string,const string);

#endif



