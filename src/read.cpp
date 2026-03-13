#include "functions.hpp" // include the declaration of functions

#include <iostream>
#include <string>

using namespace std;

void read1 (string& name,int& age,string& gender,string& school)
{
	cout << "Full Name:" << endl;
	getline (cin,name);
	cout << endl;
	
	cout << "Age: ";
	cin >> age;
	cout << endl;
	
	cin.ignore (); // clear buffer
	
	cout << "Gender: Male OR Female" << endl;
	getline (cin,gender);
	cout << endl;
	
	while (gender != "Male" && gender != "Female")
	{
		cout << "Gender: Male OR Female" << endl;
	    getline (cin,gender);
	    cout << endl;
	}
	
	cout << "School:" << endl;
	getline (cin,school);
	cout << endl;
}

void read2 (string& dep_edu,string& ID,int& year,int& semester)
{
	cout << "Department Education:" << endl;
	getline (cin,dep_edu);
	cout << endl;
	
	cout << "Student ID Number:" << endl;
	getline (cin,ID);
	cout << endl;
	
	cout << "Year Course: ";
	cin >> year;
	cout << endl;
	
	cout << "Semester: ";
	cin >> semester;
	cout << endl;
}









