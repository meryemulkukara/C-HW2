#include "LibrarySystem.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{



	string fileName;
	cout<<"Enter the file name: ";
	cin>>fileName;


	LibrarySystem lib;
	lib.readFile( fileName);


	return 0;
}




