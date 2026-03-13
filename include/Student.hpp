#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

using namespace std;

class Student
{
    private:
	    string full_name;
		int age;
		string gender;
		
		string school;    // the school of department education
		string dep_edu;  // department education	
		
		string ID_number; // student ID number
		
		int year_course; // study year
		int semester;
		
	public:
		Student (string,int,string,string,string,string,int,int); // registration students
		
		void getter1 (string&,int&,string&,string&);
		void getter2 (string&,string&,int&,int&);
};

#endif





