#ifndef MONTH_H
#define MONTH_H

#include"./planet.hpp"

class month{
    private:
        static int max_time;
        int planets_num;
        Planet** planets;
    public:
        month(Planet** planets);
        ~month();
        static void set_max_time(int time);
        void add_planets(Planet** planets);
};

#endif