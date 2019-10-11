#ifndef TRAVEL_GUIDE_H
#define TRAVEL_GUIDE_H
#define VISIT_TIME 1
#define NAME (-1)

#include"./planet.hpp"
#include"./month.hpp"
#include"./queue.hpp"

class TravelGuide{
    private:
        static Planet** planets;
        static int max_time;
        static int planets_num;
        static int name_max_length;
        static int visited;
    public:
        TravelGuide();
        ~TravelGuide();
        static void read_planets(int max_time, int planets_num, int name_max_length);
        static Planet** get_planets();
        static void free_planets();
        static std::string planets_to_s();
        static void sort_planets();
        static Queue<Month>* visit_planets();
        static void quick_sort(Planet** planets, int begin, int end, int sort_parameter);
        static int partition(Planet** planets, int begin, int end, int sort_parameter);
        static void swap_planets(int a, int b);
};

#endif