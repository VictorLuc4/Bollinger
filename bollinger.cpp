/*
** Created by Victor Lucas
*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <algorithm>

#include "input.hpp"
#include "bollinger.hpp"

/* Contrusctor  : getting file indexes */
Bollinger::Bollinger(const char *file)
{
	std::string line;
	std::ifstream myfile(file);

	if (myfile)
	{
		while (getline(myfile, line))
		{
			this->values.push_back(line);
		}
	} else {
		exit(84);
	}
	myfile.close();
	this->i = 0;
	this->start = 0;
}

/* Destructor */
Bollinger::~Bollinger()
{
	/* Nothing to do */
}

void Bollinger::run(Input In)
{
	/* Compute the results */
	this->calculMoyenMobile(In);
	this->calculEcartType(In.getPeriod());
	this->calculBPlus(In);
	this->calculBMoins(In);
	
	/* Print the results to the stdout */
	std::cout << "OUTPUT" << std::endl;
	std::cout << "MA: " << this->moyenne << std::endl;
	std::cout << "B+: " << this->bp << std::endl;
	std::cout << "B-: " << this->bm << std::endl;
}

/* Standard deviation calculation */
void Bollinger::calculEcartType(int period)
{
	double variance = 0;
	double carre = 0;

	while (this->start <= this->i - 1)
	{
		carre = pow((atof(this->values[this->start].c_str()) - this->moyenne), 2);
		variance = variance + (double)carre;
		this->start++;
	}
	if (variance > 0) {
		variance = variance / (double)period - 1.00;
		this->sd = sqrt(variance);
		this->sd <= 0.01 ? (this->sd = 0.00) : 1;
		std::cout << "SD: " <<  this->sd << std::endl;

	}
	else {
		exit(84);
	}
}

/* Higher band calculation */
void Bollinger::calculBPlus(Input In)
{
        this->bp = this->moyenne + (this->sd * In.getCoef());
}

/* Lower band calculation */
void Bollinger::calculBMoins(Input In)
{
        this->bm = this->moyenne - (this->sd * In.getCoef());
}

/* Mobile average calculation */
void Bollinger::calculMoyenMobile(Input In)
{
	std::vector<double> order;
	this->start = In.getIndex() - In.getPeriod() + 1;
	this->i = 0;

	this->moyenne = 0.0;
	if (this->start < 0)
		throw  std::invalid_argument("Argument 4 is not valid");

        while (this->start <= In.getIndex() && (unsigned int)this->start < this->values.size())  {
		order.push_back(atof(this->values[this->start].c_str()));
                this->start += 1;
                this->i++;
        }
	std::sort(order.begin(), order.end());
	
	int inc = 0;
	while (inc < i){
		this->moyenne += order[inc];
		inc++;
	}
	this->i = this->start;
	if (In.getPeriod() <= 0)
		throw  std::invalid_argument("Division by 0 is forbidden");
	this->start = In.getIndex() - In.getPeriod() + 1;
	this->moyenne = (this->moyenne / In.getPeriod());
}

/* --- Getters and setters --- */

double Bollinger::getMoyenne() const
{
	return this->moyenne;
}

double Bollinger::getSd() const
{
	return this->sd;
}

double Bollinger::getBp() const
{
	return this->bp;
}

double Bollinger::getBm() const
{
	return this->bm;
}
