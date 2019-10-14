#include<iostream>
#include<cstdlib>
#include"./include/planet.hpp"
#include"./include/travel_guide.hpp"
#include"./include/month.hpp"
#include"./include/queue.hpp"

int main(){
    int max_time = 0, planets_num = 0, name_max_length = 0;
    Queue<Month>* schedule;

    while (std::cin >> max_time >> planets_num >> name_max_length){
        TravelGuide::read_planets(max_time, planets_num, name_max_length);
        // std::cout << TravelGuide::planets_to_s() << std::endl;
        schedule = TravelGuide::visit_planets();
        for (int i = 0; schedule->length() > 0; i++){
            Month* month = schedule->remove();
            Planet** planets = month->get_planets();
            for (int j = 0; j < month->get_planets_num(); j++){
                std::cout << i+1 << ' ' << planets[j]->get_name() << ' ' << planets[j]->get_time() << std::endl;
            }
            delete month;   
        }
        TravelGuide::free_planets();
    }
    delete schedule;

    return 0;
}