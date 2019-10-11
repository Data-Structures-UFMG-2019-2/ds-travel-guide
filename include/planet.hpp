#ifndef PLANET_H
#define PLANET_H

#include<string>

class Planet {
    private:
        std::string name;
        int time;
    public:
        Planet(std::string name, int time);
        ~Planet();
        std::string get_name();
        int get_time();
        std::string to_s();
};

#endif