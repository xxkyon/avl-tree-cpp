#include "utils.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <cctype>

int readInt(const std::string& prompt){
    int value;
    while(true){
        std::cout << prompt;
        std::cin >> value;

        if(std::cin.fail()){
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please make sure to type a number.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

std::string normalizeSpaces(const std::string& input){
    std::string result;
    bool lastWasSpace = false;

    for(unsigned char c : input){
        if(c == ' '){
            if(!lastWasSpace && !result.empty()){
                result += c;
                lastWasSpace = true;
            }
        } else {
            result += c;
            lastWasSpace = false;
        }
    }

    if(!result.empty() && result.back() == ' '){
        result.pop_back();
    }

    return result;
}

bool isValidName(const std::string& name){
    for(unsigned char c : name){
        if(std::isdigit(c)){
            return false; // no numbers
        }
    }
    return !name.empty();
}

std::string readString(const std::string& prompt){
    std::string input;
    while(true){
        std::cout << prompt;
        std::getline(std::cin, input);

        //remove extra spaces
        input = normalizeSpaces(input);

        if(isValidName(input)){
            return input;
        } else{
            std::cout << "Invalid name. Use only letters and spaces (numbers not allowed).\n";
        }
    }
}