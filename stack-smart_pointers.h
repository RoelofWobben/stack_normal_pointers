#pragma once

#include <memory>

class Stack {
    public:
        // Creates an empty stack with capacity 4
        Stack();
        
        
        // Creates a copy of your stack
        Stack(const Stack& o);
            
         
        // Assignment operator
        Stack& Stack::operator=(Stack&& o);
 
   

              
        // We'll ignore move constructor and move assignment.

        Stack(Stack&& o) ;  
                  
       
        // Adds a new value to the stack
        void push(int value);

       
        
        // Checks the value at the top of the stack
        int top();

        // Removes the value at the top of the stack (returning it)
        int pop();
        
        // Returns the number of elements in the stack
        int size();
    
    private: 
        std::unique_ptr<int[]> buffer; 
        int capacity;
        int number_of_items;
    
     
}; 