/*
** Created by Victor Lucas
*/

#ifndef _INPUT_HPP_
# define _INPUT_HPP_

#include <string>
#include <iostream>
#include <cstdlib>

class Input {
public:
        Input(const char **av);
        ~Input();

	void printInput();
        double getCoef() const;
        int getPeriod() const;
        int getIndex() const;
        void setCoef(double coef);
        void setPeriod(int period);
        void setIndex(int index);

private:
        int _period;
        int _index_nb;
        double _coef;
};

#endif
