#include<string>
#include<sstream>
#include<iostream>

#include"../include/queue.hpp"
#include"../include/month.hpp"

template<class T>
Queue<T>::Queue(){
    this->size = 0;
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
Queue<T>::~Queue(){

}

template<class T>
int Queue<T>::length(){
    return this->size;
}

template<class T>
void Queue<T>::add(T* object){
    Cell<T>* cell = new Cell<T>(object);

    if(this->size == 0){
        this->first = cell;
        this->last = cell;
    }
    else{
        cell->prev = this->last;
        this->last->next = cell;
        this->last = cell;
    }
    ++this->size;
}

template<class T>
T* Queue<T>::remove(){
    Cell<T>* cell = nullptr;
    T* object = nullptr;
    if(this->size <= 0){
        return nullptr;
    }
    else {
        cell = this->first;
        this->first = cell->next;
        if(size == 1){
            this->last = nullptr;
        }
    }
    --this->size;
    object = cell->object;
    delete cell;
    return object;
}

template<class T>
void Queue<T>::clear(){
    if(this->size > 0){
        this->first->cascade_clear(FORWARD);
        delete this->first;
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }
}

template<class T>
void Queue<T>::clear(int strategy){
    if(strategy == ITERATIVE){
        while(this->size > 0){
            delete this->remove();
        }
    }
    else if(strategy == RECURSIVE){
        if(this->size > 0){
            this->first->cascade_clear(FORWARD);
            delete this->first;
            this->first = nullptr;
            this->last = nullptr;
            this->size = 0;
        }
    }
}

template class Queue<Month>;