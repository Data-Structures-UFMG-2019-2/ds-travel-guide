#include<cstdlib>
#include<iostream>
#include<cassert>
#include<sstream>
#include<random>

#include"../include/travel_guide.hpp"

Planet** TravelGuide::planets = nullptr;
int TravelGuide::max_time = 0;
int TravelGuide::planets_num = 0;
int TravelGuide::name_max_length = 0;
int TravelGuide::visited = 0;

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

std::string TravelGuide::planets_to_s(){
    std::stringstream stream;
    stream << '[';
    for (int i = 0; i < TravelGuide::planets_num; i++){
        if(i != 0){
            stream << ", ";
        }
        stream << TravelGuide::planets[i]->to_s();
    }
    stream << ']';
    return stream.str();
}

void TravelGuide::free_planets(){
    for (int i = 0; i < TravelGuide::planets_num; i++){
        delete TravelGuide::planets[i];
    }
    free(TravelGuide::planets);
}

void TravelGuide::sort_planets(){
    quick_sort(planets, 0, TravelGuide::planets_num-1, VISIT_TIME);
}

Queue<Month>* TravelGuide::visit_planets(){
    TravelGuide::sort_planets();
    Queue<Month>* schedule = new Queue<Month>();

    while (TravelGuide::visited < TravelGuide::planets_num){
        int time_spent = 0;
        int begin = TravelGuide::visited;
        int visited = 0;

        for (int i = begin; i < TravelGuide::planets_num; i++){
            Planet* planet = TravelGuide::planets[i];
            if(time_spent + planet->get_time() > TravelGuide::max_time){
                break;
            }
            time_spent += planet->get_time();
            visited++;
            TravelGuide::visited++;
        }
        TravelGuide::quick_sort(TravelGuide::planets, begin, TravelGuide::visited-1, NAME);
        schedule->add(new Month(TravelGuide::planets+begin, visited));
    }
    return schedule;
}

void TravelGuide::quick_sort(Planet** planets, int begin, int end, int sort_parameter){
    if(begin < end){
        int pivot_index = TravelGuide::partition(planets, begin, end, sort_parameter);
        TravelGuide::quick_sort(planets, begin, pivot_index-1, sort_parameter);
        TravelGuide::quick_sort(planets, pivot_index+1, end, sort_parameter);
    }
}

int TravelGuide::partition(Planet** planets, int begin, int end, int sort_parameter){
    /* TODO: make pivot selection random */
    // std::random_device rd;
    // std::mt19937 eng(rd());
    // std::uniform_int_distribution<> rand_generator(begin, end);
    // int random_index = rand_generator(eng);
    // std::cout << "Pivot aleatorio: " << random_index << std::endl;
    // assert(random_index >= begin && random_index <= end);
    int random_index = end;
    Planet* pivot = planets[random_index];
    int pivot_index = begin;
    for (int i = begin; i < end; i++){
        if((planets[i]->get_time() < pivot->get_time()) && (sort_parameter == VISIT_TIME)){
            TravelGuide::swap_planets(i, pivot_index);
            pivot_index++;
        }
        else if((planets[i]->get_name().compare(pivot->get_name()) < 0) && (sort_parameter == NAME)){
            TravelGuide::swap_planets(i, pivot_index);
            pivot_index++;
        }
    }
    TravelGuide::swap_planets(pivot_index, random_index);
    return pivot_index;
}

void TravelGuide::swap_planets(int a, int b){
    Planet* temp = TravelGuide::planets[a];
    TravelGuide::planets[a] = TravelGuide::planets[b];
    TravelGuide::planets[b] = temp;
}

