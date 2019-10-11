#ifndef MONTH_H
#define MONTH_H

#include"./planet.hpp"

class Month{
    private:
        int planets_num;
        Planet** planets;
    public:
        Month(Planet** planets, int planets_num);
        ~Month();
        int get_planets_num();
        Planet** get_planets();
};

#endif