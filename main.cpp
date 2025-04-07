#include <iostream>
#include <string>

int main() {
    Stack s;
    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);
        if (line == "exit") break;
        else if (line == "pop") std::cout << "Popped " << s.pop() << "\n";
        else if (line == "top") std::cout << "Top value: " << s.top() << "\n";
        else if (line.starts_with("push ")) {
            int val = std::stoi(line.substr(5));
            s.push(val);
        } else if (line == "print") {
            Stack copy = s;
            while (copy.size() > 0) {
                std::cout << copy.pop() << " ";
            }
            std::cout << "\n";
        } else {
            std::cout << "Commands: push <n>, pop, top, exit\n";
        }
    }
}