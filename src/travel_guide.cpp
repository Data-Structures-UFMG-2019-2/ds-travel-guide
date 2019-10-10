#include<cstdlib>
#include<iostream>

#include"../include/travel_guide.hpp"

Planet** TravelGuide::planets = nullptr;
int TravelGuide::max_time = 0;
int TravelGuide::planets_num = 0;
int TravelGuide::name_max_length = 0;

void TravelGuide::read_planets(int max_time, int planets_num, int name_max_length){
    TravelGuide::planets = (Planet**) malloc(planets_num*sizeof(Planet*));
    TravelGuide::max_time = max_time;
    TravelGuide::planets_num = planets_num;
    TravelGuide::name_max_length = name_max_length;

    for (int i = 0; i < planets_num; i++){
        std::string name;
        int time;

        std::cin >> time >> name;
        TravelGuide::planets[i] = new Planet(name, time);
    }
}

Planet** TravelGuide::get_planets(){
    return TravelGuide::planets;
}

void TravelGuide::free_planets(){
    for (int i = 0; i < TravelGuide::planets_num; i++){
        delete TravelGuide::planets[i];
    }
    free(TravelGuide::planets);
}