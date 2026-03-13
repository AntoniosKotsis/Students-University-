#include "Student.hpp"

#include "functions.hpp" // include the declaration of functions

#include <iostream>
#include <string>

using namespace std;

int main (int argc,char** argv)
{
	// filename (data students)
	string st_data;
	cout << "Filename for data students (.txt OR .csv):" << endl;
	getline (cin,st_data);
	cout << endl;
	
	// declaration variables for all students
	
	string full_name;
	int age;
	string gender;
		
	string school;    // the school of department education
	string dep_edu;  // department education	
		
	string ID_number; // student ID number
		
	int year_course; // study year
	int semester;
	
	// menu (management of students)
	int i;
	i = menu ();
	
	cin.ignore (); // clear buffer
	
	while (i != 6)
	{
		if (i == 1) // registration
		{
			// read data 
			read1 (full_name,age,gender,school);
			read2 (dep_edu,ID_number,year_course,semester);
			
			Student st (full_name,age,gender,school,dep_edu,ID_number,year_course,semester); // registration

			write_file (st,st_data);
		}
		
		else if (i == 2) // appear data for all students
		{
			st_appear (st_data); // appear data students from the file
		}
		
		else if (i == 3) // search student with ID number
		{
			search_ID_number (st_data,ID_number);
		}
		
		else if (i == 4) // delete student with ID number
		{
			int there;
			there = search_ID_number (st_data,ID_number);	
			
			if (there)
			{
				int fal_enum;
			    fal_enum = delete_student (ID_number,st_data);
			    
			    cin.ignore(); // clear buffer
			    
			    change_enumeration (fal_enum,st_data);
			}
			
			else
			{
				cout << "No delete data of student \n \n";
			}
		}
		
		else if (i == 5)
		{
			int there;
			there = search_ID_number (st_data,ID_number);
			
			if (there)
			{
				// old data of student

                string age1;
                string year_course1;
                string semester1;
				
				cout << "Read the current data of student:" << "\n \n";
				
				cout << "Age: ";
                getline (cin,age1);
                cout << endl;
    
                cout << "Year Course: ";
                getline (cin,year_course1);
                cout << endl;
    
                cout << "Semester: ";
                getline (cin,semester1);
                cout << endl;
				
				cout << "//////////////" << "\n \n";
				
				update_elements (ID_number,age1,year_course1,semester1,st_data);
			}
			
			else
			{
				cout << "No update data of student" << "\n \n";
			}
		}
		
		i = menu ();
		
		cin.ignore (); // clear buffer for the first attribute of class "Student" (string)
	}
	
	return 0;
}










