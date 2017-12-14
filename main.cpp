#include <iostream>
#include <string>
#include <sstream>
#include "options.h"

int main() {
    std::string input = "";
    std::cout << "Welcome to our Parking Garage!" << std::endl;
    while(input!="d" && input !="D") {
        printOptions(); //this will print the options as well as ask them which option they would like
        std::cin >> input;
        checkOption(input);
        selectOption(input);
    }

    return 0;
}