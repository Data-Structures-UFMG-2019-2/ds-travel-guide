#include "../include/cell.hpp"
#include "../include/month.hpp"

template<class T>
Cell<T>::Cell(T* object){
    this->object = object;
    this->next = nullptr;
    this->prev = nullptr;
}

template<class T>
Cell<T>::~Cell(){
}

template<class T>
Cell<T>* Cell<T>::operator++(){
    return this->next;
}

template<class T>
Cell<T>* Cell<T>::operator--(){
    return this->prev;
}

template<class T>
T* Cell<T>::get_object(){
    return this->object;
}

template<class T>
Cell<T>* Cell<T>::get_next(){
    return this->next;
}

template<class T>
Cell<T>* Cell<T>::get_prev(){
    return this->prev;
}

template<class T>
void Cell<T>::cascade_clear(int direction){
    if(direction == FORWARD){
        if(this->next != nullptr){
            this->next->cascade_clear(FORWARD);
            delete this->next;
        }
    }
    else if(direction == BACKWARD){
        if(this->prev != nullptr){
            this->prev->cascade_clear(BACKWARD);
            delete this->prev;
        }
    }
    delete this->object;
}

template class Cell<Month>;