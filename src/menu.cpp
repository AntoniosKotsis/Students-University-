#include "functions.hpp" // include the declaration of function

#include <iostream>

using namespace std;

int menu ()
{
	// messages for management of elements
	
	cout << "1. Registration" << endl;
	cout << "2. Appear elements" << endl; 
	cout << "3. Search (Student ID Number)" << endl;
	cout << "4. Delete (Student ID Number)" << endl;
	cout << "5. Update elements" << endl;
	cout << "6. Exit" << endl;
	
	cout << "\n";
	
	int number; // selection number for above operations
	
	cout << "Select: ";
	cin >> number;
	cout << endl;
	
	while (number < 1 || number > 6) // in case of FALSE operation
	{
		cout << "Select: ";
	    cin >> number;
	    cout << endl;
	}
	
	return number;
}







