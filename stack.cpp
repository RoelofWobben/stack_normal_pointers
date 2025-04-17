#include "stack.h"
#include <memory>
#include <iostream>

Stack::Stack() {
    capacity = 4;
    buffer = new int[capacity]; 
    number_of_items = 0;
}

Stack::Stack(const Stack& o){
    capacity = o.capacity; 
    number_of_items = o.number_of_items; 
    buffer = new int[capacity];
    for (int i {}; i < number_of_items; i++) {
        buffer[i] = o.buffer[i];  
     }  
}


Stack& Stack::operator =(const Stack& o) {
    capacity = o.capacity;   
    number_of_items = o.number_of_items;
    delete[] buffer;  
    buffer = new int[capacity];
    for (int i {}; i < number_of_items; i++) {
        buffer[i] = o.buffer[i];  
    }
    
    return *this; 
}

Stack::~Stack(){
    delete[] buffer;  
}

void Stack::push(int value){
    if (number_of_items <= capacity) {
        buffer[number_of_items] = value;
        ++number_of_items; 
    } else {
        capacity = capacity * 2 ; 
        int* new_buffer = new int[capacity];
        for (int i {}; i < number_of_items; i++) {
            new_buffer[i] = buffer[i];  
        }; 
        delete[] buffer;
        buffer = new_buffer;
        buffer[number_of_items] = value;
        ++number_of_items;  
    }
}

int Stack::top()  {
    if (number_of_items <= 0) {
        std::cout << "Cannot read from a empty stack";
        return -1 ;  
    }
    return buffer[number_of_items -1]; 
}


int Stack::pop() {
    --number_of_items;
    if (number_of_items < 0) {
        number_of_items = 0; 
        std::cout << "Cannot read from a empty stack";
        return -1 ;  
    }
    return buffer[number_of_items];
}


int Stack::size() {
    return number_of_items; 
}



