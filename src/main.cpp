#include <iostream>
#include <cpp3ds/Graphics.hpp>
#include "Fumaroos.hpp"

using namespace cpp3ds;

int main(int argc, char** argv) {
    Console::enable(TopScreen);
    std::cout << "TESTING";
    if (!Service::enable(Network))
        std::cout << "SERVICE FAILURE!" << std::endl;
    Fumaroos::Fumaroos game;
//    game.console(TopScreen); // Console for reading stdout
    game.run();
    return 0;
}