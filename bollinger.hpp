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
#include <vector>
#include "input.hpp"

#ifndef BOLLINGER_H
#define BOLLINGER_H
class Bollinger {
public:
	Bollinger(const char *file);
	~Bollinger();

	void run(Input In);
	void calculEcartType(int period);
	void calculBPlus(Input In);
	void calculBMoins(Input In);
	void calculMoyenMobile(Input In);

	double getMoyenne() const;
	double getSd() const;
	double getBp() const;
	double getBm() const;
private:
	std::vector<std::string> values;
	double sd;
	double moyenne;
	double bp;
	double bm;

	int i;
	int start;
};
#endif
