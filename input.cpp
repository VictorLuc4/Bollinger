/*
** Created by Victor Lucas
*/

#include "input.hpp"
#include <iomanip>
#include <string>

/* Contructor */
Input::Input(const char **av)
{
	std::string av1 = av[1];
	std::string av2 = av[2];
	std::string file = av[3];
	std::string av4 = av[4];
	std::string toCompare(file.substr(file.find_last_of(".") + 1));

	if (toCompare.compare("txt") != 0)
		exit(84);
        _period = atoi(av1.c_str());
        _index_nb = atoi(av4.c_str());
        _coef = atof(av2.c_str());
	if (_period <= 0 || _index_nb <= 0 || _coef <= 0)
		exit(84);
	if (_period >= _index_nb)
		exit(84);
}

/* Destructor */
Input::~Input()
{
	/* Nothing to do */
}

void Input::printInput()
{
	std::cout << "INPUT" << std::endl;
	std::cout << "Index: " << this->_index_nb << std::endl;
	std::cout << "Period: " << this->_period << std::endl;
	std::cout << "SD_coef: " << std::setprecision(2) << 
	std::fixed << this->_coef << "\n" << std::endl;
}

/* --- Getters and setters --- */

void Input::setCoef(double coef)
{
        _coef = coef;
}

void Input::setPeriod(int period)
{
        _period = period;
}

void Input::setIndex(int index)
{
        _index_nb = index;
}

double Input::getCoef() const
{
        return _coef;
}

int Input::getPeriod() const
{
        return _period;
}

int Input::getIndex() const
{
        return _index_nb;
}
