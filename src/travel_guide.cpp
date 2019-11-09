#include<cstdlib>
#include<iostream>
#include<cassert>
#include<sstream>
#include<random>
#include<cmath>

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

void TravelGuide::sort_planets(int algorithm){
    switch (algorithm){
        case MERGESORT:
            TravelGuide::merge_sort(planets, 0, TravelGuide::planets_num-1);
            break;

        case QUICKSORT:
            TravelGuide::quick_sort(planets, 0, TravelGuide::planets_num-1);
            break;
        
        default:
            TravelGuide::quick_sort(planets, 0, TravelGuide::planets_num-1);
            break;
    }
}

Queue<Month>* TravelGuide::visit_planets(){
    TravelGuide::sort_planets(MERGESORT);
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
            else{
                time_spent += planet->get_time();
                visited++;
                TravelGuide::visited++;
            }
        }
        TravelGuide::radix_sort(TravelGuide::planets+begin, TravelGuide::visited-begin);
        schedule->add(new Month(TravelGuide::planets+begin, visited));
    }
    return schedule;
}

void TravelGuide::print_schedule(Queue<Month>* schedule){
    for (int i = 0; schedule->length() > 0; i++){
        Month* month = schedule->remove();
        Planet** planets = month->get_planets();
        for (int j = 0; j < month->get_planets_num(); j++){
            std::cout << i+1 << ' ' << planets[j]->get_name() << ' ' << planets[j]->get_time() << std::endl;
        }
        delete month;   
    }
    delete schedule;
}

void TravelGuide::radix_sort(Planet** planets, int length){
    Queue<Planet>** count_vector = (Queue<Planet>**) malloc(ALPHABET*sizeof(Queue<Planet>*));
    for (int i = 0; i < ALPHABET; i++){
        count_vector[i] = new Queue<Planet>();
    }
    for (int position = TravelGuide::name_max_length-1; position >= 0; position--){
        for (int i = 0; i < length; i++){
            count_vector[(planets[i]->get_name().c_str()[position])-'a']->add(planets[i]);
        }
        int j = 0;
        for (int i = 0; i < ALPHABET; i++){
            while(count_vector[i]->length() > 0){
                planets[j] = count_vector[i]->remove();
                j++;
            }
        }
    }
    for (int i = 0; i < ALPHABET; i++){
        delete count_vector[i];
    }
    free(count_vector);
}

void TravelGuide::merge_sort(Planet** planets, int left, int right){
    if(left < right){
        int middle = left + ceil((right - left)/2);
        TravelGuide::merge_sort(planets, left, middle);
        TravelGuide::merge_sort(planets, middle + 1, right);
        TravelGuide::merge(planets, left, middle, right);
    }
}

void TravelGuide::merge(Planet** planets, int left, int middle, int right){
    int i, j, k; 
    int size_left = (middle - left) + 1; 
    int size_right =  (right - middle); 
    Planet **left_array, **right_array;

    left_array = (Planet**) malloc(size_left*sizeof(Planet*));
    right_array = (Planet**) malloc(size_right*sizeof(Planet*)); 
  
    for (i = 0; i < size_left; i++) {
        left_array[i] = planets[left + i]; 
    }
    for (j = 0; j < size_right; j++){
        right_array[j] = planets[middle + 1 + j]; 
    }

    i = 0;
    j = 0;
    k = left;
    while (i < size_left && j < size_right) { 
        if (left_array[i]->get_time() <= right_array[j]->get_time()) { 
            planets[k] = left_array[i]; 
            i++; 
        } 
        else{
            planets[k] = right_array[j]; 
            j++; 
        }
        k++; 
    }
    while (i < size_left) { 
        planets[k] = left_array[i]; 
        i++; 
        k++; 
    }
    while (j < size_right) { 
        planets[k] = right_array[j]; 
        j++; 
        k++; 
    }
    free(left_array);
    free(right_array);
}

void TravelGuide::quick_sort(Planet** planets, int begin, int end){
    if(begin < end){
        int pivot_index = TravelGuide::partition(planets, begin, end);
        TravelGuide::quick_sort(planets, begin, pivot_index-1);
        TravelGuide::quick_sort(planets, pivot_index+1, end);
    }
}

int TravelGuide::partition(Planet** planets, int begin, int end){
    int random_index = end;
    Planet* pivot = planets[random_index];
    int pivot_index = begin;
    for (int i = begin; i <= end; i++){
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

