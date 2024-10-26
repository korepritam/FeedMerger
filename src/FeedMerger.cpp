//============================================================================
// Name        : Merger.cpp
// Author      : Pritam Kore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "StandardIncludes.h"

int main(int argc, char** argv) {
	cout << argc << endl; // prints !!!Hello World!!!
	for(int i=2; i<argc; i++) {
		cout << argv[i] << " ";
		ifstream inputFile(argv[i]);

	    // Check if the file was opened successfully
	    if (!inputFile) {
	        std::cerr << "Error opening file!" << std::endl;
	        return 1; // Exit with error code
	    }

	    std::string line;
	    // Read the file line by line
	    while (std::getline(inputFile, line)) {
	        std::cout << line << std::endl; // Output the line to the console
	    }

	    // Close the file
	    inputFile.close();


	}
	return 0;
}
