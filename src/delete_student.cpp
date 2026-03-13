#include "functions.hpp"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int delete_student (string ID_number,const string& file_stud)
{
	fstream file1;
	file1.open(file_stud,ios::in); // open file to read (data students) original file
	
	if ( !file1.is_open() )
	{
		cerr << "Error opening file to read the data of students" << endl;
		exit (0);
	}
	
	
    // temporary file
	
	string file_temp;
	cout << "Filename for temporary file (.txt OR .csv):" << endl;
	getline (cin,file_temp);
	cout << endl;
	
	fstream file2;
	file2.open(file_temp,ios::out); // open file to write (data of students) temporary file
	
	if ( !file2.is_open() )
	{
		cerr << "Error opening file to write the data of students" << endl;
		file1.close(); // close file1 (original file)
		
		exit (1);
	}
	
	
	
	
	string line;
	
    while ( getline(file1,line) )
    {
    	if ( line.find(ID_number) != string::npos )
    	{
    		for (int i=1; i<11; i++)
    		{
    			// no write these lines in temporary file
    			getline (file1,line);
			}
		}
		
		else
		{
			// write lines in temporary file
			file2 << line << endl;
		}
	}
	
	// close files
	file1.close(); // original file
	file2.close(); // temporary file
	
	
	
	
	file2.open(file_temp,ios::in); // temporary file
	
	if ( !file2.is_open() )
	{
		cerr << "Error opening file to read the data of students" << endl;
		cerr << "Problem with data of students in temporary file" << endl;
		
		exit(2);
	}
	
	
	
	
	file1.open(file_stud,ios::out); // original file
	
	if ( !file1.is_open() )
	{
		cerr << "Error opening file to write the data of students" << endl;
		cerr << "Problem with data of students in original file" << endl;
		
		exit(3);
	}
	
	
	// transfer data from temporary file in original file
	
	while ( getline(file2,line) )
	{
		file1 << line << endl;
	}
	
	// close files
	file2.close(); // temporary file
	file1.close(); // original file
	
	
	cout << "The data of student deleted" << "\n \n";
	
	int fal_enum;
	cout << "False Enumeration of Student: ";
	cin >> fal_enum;
	cout << endl;
	
	return fal_enum;
}










