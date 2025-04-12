#include "stack.h"
#include <memory>

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
        ++number_of_items; 
        buffer[number_of_items] = value;
    } else {
        capacity = capacity * 2 ; 
        int* new_buffer = new int[capacity];
        for (int i {}; i < number_of_items; i++) {
            new_buffer[i] = buffer[i];  
        }; 
        delete[] buffer;
        buffer = new_buffer;
        buffer[number_of_items] = value; 
    }
}

int Stack::top()  {
    return buffer[number_of_items -1]; 
}


int Stack::pop() {
    --number_of_items;
    return buffer[number_of_items];
}


int Stack::size() {
    return number_of_items; 
}



