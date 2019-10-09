#ifndef MONTH_H
#define MONTH_H

#include"./planet.hpp"

class month{
    private:
        Planet* planets;
    public:
        month();
        ~month();
        void add_planets(Planet* planets);
};

#endif