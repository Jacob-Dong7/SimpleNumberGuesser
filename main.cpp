#include <iostream>
#include "Generator.h"
//Simple number generator
//Generates a random number within user specified ranges
//ranges cannot be smaller than 0

int main() {
    int start, end, guess, rand;
    bool quit = 0;
    Generator gen;
    std::cout << "Please enter the start and end range, the number has to be larger than or equal to 0 \n";
    std::cin >> start >> end;
    rand = gen.generate(start, end);

    //Main guess loop
    //Loop until the user quits or the user finds the correct number
    while (quit != 1) {
        std::cout << "Please enter your guess, enter -1 to quit \n";
        std::cin >> guess;
        if (guess == rand) break;
        if (guess < 0) quit = 1;
        if (guess < rand) std::cout << "The random number is larger \n";
        if (guess > rand) std::cout << "The random number is smaller \n";
    }

    if (quit == 1) {
        std::cout << "The random number was " << rand << " better luck next time \n";
    } else {
        std::cout << "Good job \n";
    }
    return 0;
}