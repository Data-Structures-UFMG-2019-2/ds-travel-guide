#include"../include/month.hpp"

Month::Month(Planet** planets, int planets_num){
    this->planets = planets;
    this->planets_num = planets_num;
}

Month::~Month(){

}

int Month::get_planets_num(){
    return this->planets_num;
}

Planet** Month::get_planets(){
    return this->planets;
}