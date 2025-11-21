#include "Generator.h"
#include <random>

int Generator::generate(int start, int end) {
    //uses <random>
    //creates random device and a unifrom distribution
    std::random_device rd;
    std::uniform_int_distribution<int> dist(start, end);
    int randomNum = dist(rd);

    return randomNum;
}
