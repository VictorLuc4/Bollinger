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

Bollinger::~Bollinger()
{
}

void Bollinger::run(Input In)
{
	std::cout << "OUTPUT" << std::endl;
	this->calculMoyenMobile(In);
        std::cout << "MA: " << this->moyenne << std::endl;
	this->calculEcartType(In.getPeriod());
        this->calculBPlus(In);
	std::cout << "B+: " << this->bp << std::endl;
	this->calculBMoins(In);
	std::cout << "B-: " << this->bm << std::endl;
}

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

void Bollinger::calculBPlus(Input In)
{
        this->bp = this->moyenne + (this->sd * In.getCoef());
}

void Bollinger::calculBMoins(Input In)
{
        this->bm = this->moyenne - (this->sd * In.getCoef());
}

void Bollinger::calculMoyenMobile(Input In)
{
	std::vector<double> order;
	int j = 0;

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
	while (j < i){
		this->moyenne += order[j];
		j++;
	}
        this->i = this->start;
	if (In.getPeriod() <= 0)
		throw  std::invalid_argument("Division by 0 is forbidden");
        this->start = In.getIndex() - In.getPeriod() + 1;
        this->moyenne = (this->moyenne / In.getPeriod());
}

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
