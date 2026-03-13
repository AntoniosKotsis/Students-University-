#include "functions.hpp"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int search_ID_number (const string filename,string& ID_number)
{
	fstream file; // declaration file
	file.open (filename,ios::in); // open file to read
	
	if ( !file.is_open() ) // error opening file
	{
		cerr << "Error opening file to read the data of students" << endl;
		cerr << "There are not data of students" << "\n \n";
		return 0; // no exit program (continue program)
	}
	
	// read student ID number
	
	cout << "Student ID Number:" << endl;
	getline (cin,ID_number);
	cout << endl;
	
	string line; 
	bool there = false; // there is OR there is not the student ID number
	
	while ( getline(file,line) ) // read every line from the file
	{
		if (line.find ("Student ID Number: " + ID_number) != string::npos) // there is the student ID number
		{
			there = true;
			
			cout << "There is the Student ID Number" << "\n \n";
			
			// appear data of student

            cout << "Data Student:" << "\n \n";		
			cout << line << endl;
			
			for (int i=1; i<8; i++)
			{
				getline(file,line);
				cout << line << endl;
			}
			
			cout << endl;
			
			break;
		}
	}
	
	file.close(); // close file
	
	if (there) return 1;
	
	else
	{
		cout << "There is not the Student ID Number" << "\n \n";
		return 0;
	}
}
















