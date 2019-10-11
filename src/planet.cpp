#include<sstream>

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

std::string Planet::to_s(){
    std::stringstream stream;
    stream << this->name << ": " << this->time;
    return stream.str();
}