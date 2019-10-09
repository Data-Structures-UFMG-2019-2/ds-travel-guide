#include"../include/planet.hpp"

Planet::Planet(std::string name, int time){
    this->name = name;
    this->time = time;
}

Planet::~Planet(){

}

std::string Planet::get_name(){
    return this->name;
}

int Planet::get_time(){
    return this->time;
}