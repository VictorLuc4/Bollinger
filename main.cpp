/*
** Created by Victor Lucas
*/

#include "bollinger.hpp"

void printHelp()
{
	std::cout << "Bollinger" << "Bands\n\n" <<
		"USAGE\n" <<  "    ./bollinger [-h] period standard_dev indexes_file index_number\n\n"
		  << "    period\t\tperiod number of indexes for the moving average\n"
		  << "    standard_dev\tstandard deviation coefficient to apply\n"
		  << "    indexes_file\tfile containing daily indexes\n"
		  << "    index_number\tindex number to compute moving average and Bollinger bands\n\n"
		  << "OPTIONS\n"
		  <<"-h\tprint the usage and quit." << std::endl;
}


int main(int ac, const char **av)
{
	try {
		if (ac == 5)
		{
			Input In(av);
			Bollinger bol(av[3]);

			In.printInput();
			bol.run(In);
		}
		else if (ac == 2) {
			std::string av1 = av[1];

			(av1 == "-h") ? printHelp() : exit(84);
		}
		else
			return 84;
	}
	catch (...) {
		return 84;
	}
	return 0;
}
