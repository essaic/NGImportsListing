// NGImportsListing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Loader.h"


void displayModules(std::string line) {
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	_splitpath_s(line.c_str(), NULL, 0, NULL, 0, fname, _MAX_FNAME, ext, _MAX_EXT);
	std::cout << "File " << fname << ext << ": " << std::endl << std::endl;
	E32Image image;


	try {
		loader::load(line, image);
	}
	catch (...) {
		std::cout << "Error during parsing of file";
	}
	std::cout << line << std::endl;
	std::cout << std::endl;

}


int main(int argc, char* argv[])
{

	if (argc < 2) {
		std::cout << "Should specify the path to a file containing a list of .app/.exe/.dll files" << std::endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}
	std::ifstream file(argv[1]);
	std::string line;

	//load every symbian exe to display all the module names
	while (std::getline(file, line))
	{
		displayModules(line);
	}
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

