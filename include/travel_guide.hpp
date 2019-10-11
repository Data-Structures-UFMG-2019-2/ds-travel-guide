#ifndef TRAVEL_GUIDE_H
#define TRAVEL_GUIDE_H

#include"./planet.hpp"

class TravelGuide{
    private:
        static Planet** planets;
        static int max_time;
        static int planets_num;
        static int name_max_length;
    public:
        TravelGuide();
        ~TravelGuide();
        static void read_planets(int max_time, int planets_num, int name_max_length);
        static Planet** get_planets();
        static void free_planets();
        static std::string planets_to_s();
        static void sort_planets();
        static void quick_sort(Planet** planets, int begin, int end);
        static int partition(Planet** planets, int begin, int end);
        static void swap_planets(int a, int b);
};

#endif