#include <iostream>
#include <string>
#include "stack.h"


int main() {
    Stack s;
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "exit") break;
        else if (line == "pop") std::cout << "Popped " << s.pop() << "\n";
        else if (line == "top") std::cout << "Top value: " << s.top() << "\n";
        else if (line.compare(0, 4, "push") == 0) {
           int val = std::stoi(line.substr(5));
            s.push(val);
        } else if (line == "print") {
            Stack copy = s;
            std::cout << copy.size();
            while (copy.size() > 0) {
                std::cout << copy.pop() << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Commands: push <n>, pop, top, exit\n";
        }
    
    }
}