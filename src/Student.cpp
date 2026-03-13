#include "Student.hpp"

#include <string>

using namespace std;

Student :: Student (string name,int age1,string gender1,string school1,string dep_edu1,string ID_number1,int year,int semester1)
{ 
    // registration elements
    
	full_name = name;
	age = age1;
	gender = gender1;
	
	school = school1;
	dep_edu = dep_edu1;
	
	ID_number = ID_number1;
	
	year_course = year;
	semester = semester1;
}

void Student :: getter1 (string& name,int& age1,string& gender1,string& school1)
{
	// automatically return for all variables
	
	name = full_name;
	age1 = age;
	gender1 = gender;
	school1 = school;
}

void Student :: getter2 (string& dep_edu1,string& ID_number1,int& year,int& semester1)
{
	// automatically return for all variables
	
	dep_edu1 = dep_edu;
	ID_number1 = ID_number;
	year = year_course;
	semester1 = semester;
}





















