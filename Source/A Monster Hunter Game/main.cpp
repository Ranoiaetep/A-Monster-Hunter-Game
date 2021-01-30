#include <iostream>
#include <ctime>

#include "MainMenu.h"

int main(int argc, const char * argv[]) {
    std::srand((unsigned int)(std::time(nullptr)));
    MainMenu menu;
    while (menu.Proceed());
    return 0;
}
