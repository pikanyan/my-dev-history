#include "main.h"

#include "Director.h"
#include "HTMLBuilder.h"
#include "TextBuilder.h"

#include <iostream>
#include <string>



int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		usage();

		return 0;
	}



	std::string arg = argv[1];


	if (arg == "plain")
	{
		TextBuilder textBuilder;
		Director director(&textBuilder);

		director.construct();

		std::cout << textBuilder.getResult() << "\n";
	}
	else if (arg == "html")
	{
		HTMLBuilder htmlBuilder;
		Director director(&htmlBuilder);

		director.construct();

		std::cout << htmlBuilder.getResult() << " has been created.\n";
	}
	else
	{
		usage();

		return 0;
	}



	return 0;
}


void usage()
{
	std::cout << "Usage: Main plain - create document in plain text\n";
	std::cout << "Usage: Main html - create document in HTML format\n";
}
