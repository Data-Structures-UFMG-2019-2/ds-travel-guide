#include<iostream>
#include<cstdlib>
#include"./include/planet.hpp"
#include"./include/travel_guide.hpp"


int main(){
    int max_time = 0, planets_num = 0, name_max_length = 0;

    while (std::cin >> max_time >> planets_num >> name_max_length){
        TravelGuide::read_planets(max_time, planets_num, name_max_length);
        /* ... */
        TravelGuide::free_planets();
    }

    return 0;
}