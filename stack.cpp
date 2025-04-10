#include "stack.h"
#include <memory>

Stack::Stack() {
    capacity = 4;
    buffer = new int[capacity]; 
    size = 0;
}

Stack::Stack(const Stack& o){
    capacity = o.capacity; 
    size = o.size; 
    buffer = new int[capacity];
    for (int i {}; i < size; i++) {
        buffer[i] = o.buffer[i];  
     }  
}


Stack& Stack::operator =(const Stack& o) {
    capacity = o.capacity;   
    size = o.size;
    delete[] buffer;  
    buffer = new int[capacity];
    for (int i {}; i < size; i++) {
        buffer[i] = o.buffer[i];  
    }
    
    return *this; 
}

Stack::~Stack(){
    delete[] buffer;  
}








