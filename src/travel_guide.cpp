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
    quick_sort(planets, 0, TravelGuide::planets_num-1);
}

void TravelGuide::quick_sort(Planet** planets, int begin, int end){
    if(begin < end){
        int pivot_index = TravelGuide::partition(planets, begin, end);
        TravelGuide::quick_sort(planets, begin, pivot_index-1);
        TravelGuide::quick_sort(planets, pivot_index+1, end);
    }
}

int TravelGuide::partition(Planet** planets, int begin, int end){
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
        if(planets[i]->get_time() < pivot->get_time()){
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

