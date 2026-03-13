#include "functions.hpp"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

void change_enumeration (int old_data,const string filename)
{
	old_data++; // the first false enumeration
	
	int new_data;
	new_data = old_data - 1;
	
	// from int to string
	
	string old_data1 = to_string (old_data);
	string new_data1 = to_string (new_data);
	
	char ch;
	ch = old_data1.at(0);
    
	fstream file;
	file.open(filename,ios::in); // open file to read (data students)
	
	if ( !file.is_open() )
	{
		cerr << "Error opening file to read the data of students" << endl;
		exit (0);
	}
	
	
	vector <string> data_file; // declaration vector for data of the file
	
	string line;
	
	while ( getline(file,line) )
	{
		if ( !line.empty() && line.at(0) == ch ) // change the wrong enumeration
		{
			cout << "Change the false enumeration -> " << old_data1 << endl;
			
			size_t pos = line.find(old_data1);
			
			if (pos != string::npos)
			{
				line.replace ( pos, old_data1.length(), new_data1 );
			
			    cout << "Completed the change from " << old_data1 << " -> " << new_data1 << "\n \n";
			
			    cout << "Give the next false enumeration (increase by 1 the change false enumeration):" << endl;
		        getline (cin,old_data1);
		        cout << endl;
		        
		        if ( old_data1.empty() )
		        {
		        	cerr << "The string is empty" << endl;
		        	cerr << "The change of enumeration is impossible" << endl;
    	            file.close(); // close file (read)  
    	            
    	            exit (1);
				}
		    
		        ch = old_data1.at(0);
		
		        cout << "Give the right enumeration (decrease by 1 the false enumeration):" << endl;
		        getline (cin,new_data1);
		        cout << endl;
		        
		        if ( new_data1.empty() )
		        {
		        	cerr << "The string is empty" << endl;
		        	cerr << "The change of enumeration is impossible" << endl;
		        	file.close(); // close file (read)
		        	
		        	exit (2);
				}
		    
		        cout << "//////////////" << "\n \n";
			}
			
			else // no wrong enumeration
			{
				cout << "This string has not position in the file" << "\n \n";
			}		
		}
		
		data_file.push_back (line);	// write every line to vector
	}
	
	file.close(); // close file (read)
	
	
	
	file.open(filename,ios::out); // open file to write
	
	if ( !file.is_open() )
	{
		cerr << "Error opening file to write the data of students" << endl;
		exit (3);
	}
	
	for (const auto& ln : data_file) // write the new data in the file by vector
	{
		file << ln << endl;
	}
	
	file.close(); // close file (write)
	
	cout << "The old data changed" << "\n \n";
}












