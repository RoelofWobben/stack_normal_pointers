#pragma once

class Stack {
    public:
        // Creates an empty stack with capacity 4
        Stack();
        
        
        // Creates a copy of your stack
        Stack(const Stack& o);
            
         
        // Assignment operator
        Stack& operator=(const Stack& o);

         /** this has to be worked on
        
        // Destructor
        ~Stack();
        
        // We'll ignore move constructor and move assignment.
        
        // Adds a new value to the stack
        void push(int value);
        
        // Checks the value at the top of the stack
        int top();
        
        // Removes the value at the top of the stack (returning it)
        int pop();
        
        // Returns the number of elements in the stack
        int size();
    **/ 

    private: 
        int* buffer;
        int capacity;
        int size;
    
     
}; 