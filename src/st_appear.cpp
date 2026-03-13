#include "functions.hpp"

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

int st_appear (const string filename) // name of file
{
	fstream file; // declaration file
	file.open (filename,ios::in); // open file to read
	
	if ( !file.is_open() ) // error opening file
	{
		cerr << "Error opening file to read the data of students" << endl;
		cerr << "There are not students in the file" << "\n \n";
		return 0; // no exit program (continue program)
	}
	
	// opening file
	
	string line; // This variable will have the content for every line
	bool flag = false;
	
	while ( getline(file,line) ) // read every line of file separately
	{
		flag = true;
		
		cout << line << endl; // appear content for every line
	}
	
	if (!flag) 
	{
		cout << "There is the file" << endl;
		cout << "The file has not data of students" << "\n \n";
	}
	
	file.close(); // close file
	
	return 0; // continue program
}







