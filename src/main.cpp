#include <iostream>
#include <cpp3ds/Graphics.hpp>
#include "Fumaroos.hpp"

using namespace cpp3ds;

int main(int argc, char** argv) {
    Console::enable(TopScreen);
    Fumaroos::Fumaroos game;
    game.run();
    return 0;
}