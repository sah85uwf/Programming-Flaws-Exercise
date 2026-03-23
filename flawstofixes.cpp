/** 
COP 4078 Exercise: Programming Flaws  
File Name: flawstofixes.cpp 
The flawstofixes class takes two common coding flaws
and corrects them using secure practices. 
@author Sophia Herrmann 
@version 1.0 
*/

#include <iostream>
#include <string>
#include <limits>

class flawstofixes {
public:
    // Flaw 1: Unvalidated Input (Input Validation kingdom)
    
    void flawedUnvalidatedInput() {
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("Input error.");
        }
        
        std::cout << "Age recorded: " << age << std::endl;
    }
    
    void fixedUnvalidatedInput() {
        int age;
        while (true) {
            std::cout << "Enter your age (0-120): ";
            std::cin >> age;
            
            if (std::cin.fail() || age < 0 || age > 120) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid age. Try again." << std::endl;
            } else {
                std::cout << "Valid age recorded." << std::endl;
                break;
            }
        }
    }
    
    // Flaw 2: Weak Password-Based Systems (Security Features kingdom)
    
    void flawedWeakPasswordSystem() {
        std::string password = "1234";  // Hardcoded weak password
        
        std::string input;
        std::cout << "Enter admin password: ";
        std::cin >> input;
        
        if (input == password) {
            std::cout << "Access granted!" << std::endl;
        } else {
            throw std::runtime_error("Access denied.");
        }
    }
    
    void fixedPasswordSystem() {
        std::string password;
        std::cout << "Enter password (8+ chars): ";
        std::cin >> password;
        
        if (password.length() < 8) {
            throw std::runtime_error("Password too short.");
        }
        
        std::cout << "Password accepted." << std::endl;
    }
};

int main() {
    flawstofixes demo;
    
    // Test flawed methods
    try {
        demo.flawedUnvalidatedInput();
    } catch (...) {
        std::cout << "Error handled securely." << std::endl;
    }
    
    try {
        demo.flawedWeakPasswordSystem();
    } catch (...) {
        std::cout << "Error handled securely." << std::endl;
    }
    
    // Test fixed methods
    demo.fixedUnvalidatedInput();
    demo.fixedPasswordSystem();
    
    return 0;
}
