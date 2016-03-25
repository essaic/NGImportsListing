// NGImportsListing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Loader.h"




//"C:/Users/marius/Documents/Project/N-Gage/Roms/Proper/Elder Scrolls Travels, The - Shadowkey (USA, Europe) (En,Fr,De,Es,It) (26.10.2004)/system/apps/6r51/6r51.app";

bool has_suffix(const std::string& s, const std::string& suffix)
{
	return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
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
		// Process str
		char fname[_MAX_FNAME];
		char ext[_MAX_EXT];
		_splitpath_s(line.c_str(), NULL, 0, NULL, 0, fname, _MAX_FNAME, ext, _MAX_EXT);
		std::cout << "File " << fname << ext << ": " << std::endl << std::endl ;
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
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

