#include "functions.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void update_elements (string ID_number,string age1,string year_course1,string semester1,const string filename)
{
	// new data of student
	
    string age;
    string year_course;
    string semester;
    
    cout << "Read the new data of student:" << "\n \n";
    
    cout << "Age: ";
    getline (cin,age);
    cout << endl;
    
    cout << "Year Course: ";
    getline (cin,year_course);
    cout << endl;
    
    cout << "Semester: ";
    getline (cin,semester);
    cout << endl;
    
    
    
	
	
	fstream file;
	file.open(filename,ios::in); // open file to read (data of students)
	
	if ( !file.is_open() )
	{
		cerr << "Error opening file to read the data of students" << endl;
		exit (0);
	}
	
	
	
	vector <string> lines; // all data of file
	
	string line;
	
	// check the position of strings (age, year course & semester)
	
	size_t pos1;
	size_t pos2;
	size_t pos3;
	
	while ( getline(file,line) )
    {
    	
	    if ( line.find("Student ID Number: " + ID_number) != string::npos )
	    {
	    	lines.push_back(line);
	    	
		    while ( getline(file,line) )
		    {
		    	
			    pos1 = line.find ("Age: ");
		        pos2 = line.find ("Year Course: ");
		        pos3 = line.find ("Semester: ");
		
		        if ( pos1 != string::npos )
		        {
			       line.replace ( 8, age1.length(), age);
		        }
		
		        else if ( pos2 != string::npos )
		        {
			       line.replace ( 16, year_course1.length(), year_course );
		        }
		
		        else if ( pos3 != string::npos )
		        {
			       line.replace ( 13, semester1.length(), semester );
			       
			       lines.push_back(line);
			       break; // for the last element of student (no continue read lines from the file)
		        }
		        
		        lines.push_back(line); // save every line in vector 
		        
		    }
		    
	    }
	    
	    else
	    {
	    	lines.push_back(line); // save every line in vector
		}
	    
    }
	
	file.close(); // close file (read)
	
	
	
	
	
	file.open(filename,ios::out); // open file to write 
	
	if ( !file.is_open() )
	{
		cerr << "Error opening file to write the data of students" << endl;
		cerr << "Error update elements" << endl;
		
		exit(1);
	}
	
	for (const auto& ln : lines) // write data from vector to file
	{
		file << ln << endl;
	}
	
	file.close(); // close file (write)
	
	
	cout << "//////////////" << "\n \n";
	
	cout << "The data updated" << "\n \n";	
}

















