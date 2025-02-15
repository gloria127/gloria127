#include <iostream>

#include "menu.hpp"
#include "menu_functions.hpp"
#include "menu_items.hpp"    

int main(){
    std::cout << "Здравстввуйте! Выберите, где вы хотели бы провести выходные." << std::endl;

    const IBusko::MenuItem* current = &IBusko::MAIN;
    do {
        current = current->func(current);
    } while (true);

    return 0;
}
