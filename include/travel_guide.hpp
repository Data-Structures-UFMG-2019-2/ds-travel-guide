#ifndef TRAVEL_GUIDE_H
#define TRAVEL_GUIDE_H

#define QUICKSORT 1
#define MERGESORT (-1)

#define ALPHABET 26

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
        static void sort_planets(int algorithm);
        static Queue<Month>* visit_planets();
        static void print_schedule(Queue<Month>* schedule); // Destroys the schedule
        static void radix_sort(Planet** planets, int length);
        static void merge_sort(Planet** planets, int left, int right);
        static void merge(Planet** planets, int left, int middle, int right);
        static void quick_sort(Planet** planets, int begin, int end);
        static int partition(Planet** planets, int begin, int end);
        static void swap_planets(int a, int b);
};

#endif