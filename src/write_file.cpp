#include "functions.hpp" // include the declaration of functions

#include "Student.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_file (Student& p,const string& st_data)
{
	// declaration attributes of class "Student"
	
	string full_name;
	int age;
	string gender;
		
	string school;    // the school of department education
	string dep_edu;  // department education	
		
	string ID_number; // student ID number
		
	int year_course; // study year
	int semester;
	
	fstream file; // declaration file
	file.open ( st_data, ios::out | ios::app ); // open file (write OR append)
	
	if ( !file.is_open() ) // check the opening of file
	{
		cerr << "Error opening the file" << endl;
		exit (1);
	}
	
	cout << "Open file to write the data of student" << "\n \n";
	
	// automatically return for all variables
	p.getter1 (full_name,age,gender,school); 
	p.getter2 (dep_edu,ID_number,year_course,semester);
	
	int enu_stud; // enumeration students
	cout << "Enumeration Student: ";
	cin >> enu_stud;
	cout << endl;
	
	// write data for the file
	
	file << enu_stud << ". Student ID Number: " << ID_number << endl;
	
	file << "   Full Name: " << full_name << endl;
	file << "   Age: " << age << endl;
	file << "   Gender: " << gender << endl;
	
	file << "   School: " << school << endl;
	file << "   Department Education: " << dep_edu << endl;
	
	file << "   Year Course: " << year_course << endl;
	file << "   Semester: " << semester << "\n \n";
	
	file << "///////////////////////// \n \n";
	
	file.close (); // close file
	
	cout << "The file closed" << endl;
	cout << "The data written to file successfully" << "\n \n";
}








