#include "stack-smart_pointers.h"
#include <iostream>
#include <memory>

Stack::Stack() {
    capacity = 4;
    number_of_items = 0;
    buffer = std::make_unique<int[]>(capacity) ;
}

Stack::Stack(const Stack& o) 
{
    capacity =  o.capacity;
    number_of_items = o.number_of_items;
    buffer = std::make_unique<int[]>(o.capacity) ;
    for (int i = 0; i < number_of_items; ++i) {
        buffer[i] = o.buffer[i]; 
    }
    
}

Stack::Stack(Stack&& o) 
{
    buffer = std::move(o.buffer);
    capacity = o.capacity;
    number_of_items = o.number_of_items;
    o.capacity = 0;
    o.number_of_items = 0;
}

Stack& Stack::operator=(Stack&& o)  {
    if (this != &o) {
        buffer = std::move(o.buffer);
        capacity = o.capacity;
        number_of_items = o.number_of_items;

        o.capacity = 0;
        o.number_of_items = 0;
    }
    return *this;
}

void Stack::push(int value) {
    if (number_of_items < capacity) {
        buffer[number_of_items++] = value;
    } else {
        int new_capacity = capacity * 2;
        auto new_buffer = std::make_unique<int[]>(new_capacity);

        for (int i = 0; i < number_of_items; ++i) {
            new_buffer[i] = buffer[i];
        }

        buffer = std::move(new_buffer); 
        capacity = new_capacity;

        buffer[number_of_items++] = value;
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



