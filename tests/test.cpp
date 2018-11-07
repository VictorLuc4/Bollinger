/*
** Created by Victor Lucas
*/

#include <criterion/criterion.h>
#include <string.h>
#include "../input.hpp"

const int len = 11;
const char *av[5] = {"NULL", "123", "456.123", "NULL.txt", "789"};

Test(input, function_getIndex)
{
	Input p(av);
	int nb = 789;

	cr_assert_eq(p.getIndex(), nb);
}

Test(input, function_getPeriod)
{
	Input p(av);
	int nb = 123;

	cr_assert_eq(p.getPeriod(), nb);
}

Test(input, function_getCoef)
{
	Input p(av);
	double nb = 456.123;

	cr_assert_eq(p.getCoef(), nb);
}

Test(input, function_setIndex)
{
	Input p(av);
	int nb = 666;

	p.setIndex(nb);

	cr_assert_eq(p.getIndex(), nb);
}

Test(input, function_setPeriod)
{
	Input p(av);
	int nb = 555;

	p.setPeriod(nb);

	cr_assert_eq(p.getPeriod(), nb);
}

Test(input, function_setCoef)
{
	Input p(av);
	double nb = 111.222;

	p.setCoef(nb);

	cr_assert_eq(p.getCoef(), nb);
}
