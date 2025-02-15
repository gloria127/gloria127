#include "menu_functions.hpp"

#include <cstdlib>
#include <iostream>

const IBusko::MenuItem* IBusko::show_menu(const MenuItem* current) {
	std::cout << "Литературная обучайка приветствует тебя, мой юный друг!" << std::endl;
	for (int i = 1; i < current->children_count; i++) {
		std::cout << current->children[i]->title << std::endl;
	}
	std::cout << current->children[0]->title << std::endl;
	std::cout << "Литературная Обучайка > ";

	int user_input;
	std::cin >> user_input;

	std::cout << std::endl;

	return current->children[user_input];
}

const IBusko::MenuItem* IBusko::exit(const MenuItem* current) {
    std::exit(0);
}

const IBusko::MenuItem* IBusko::writer_pushkin(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const IBusko::MenuItem* IBusko::writer_lermontov(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const IBusko::MenuItem* IBusko::writer_krilov(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent;
}

const IBusko::MenuItem* IBusko::writer_go_back(const MenuItem* current) {
    // TODO
    std::cout << current->title << std::endl << std::endl;
    return current->parent->parent;
}

const IBusko::MenuItem* IBusko::pushkin_dubrovsky(const MenuItem * current) {
	// TODO
	std::cout << "Вы выбрали: Дубровский" << std::endl;
	return current->parent->parent;
}

const IBusko::MenuItem* IBusko::pushkin_eugene_onegin(const MenuItem * current) {
	// TODO
	std::cout << "Вы выбрали: Евгений Онегин" << std::endl;
	return current->parent->parent;
}
const IBusko::MenuItem* IBusko::pushkin_winter_evening(const MenuItem* current) {
	// TODO
	std::cout << "Вы выбрали: Зимний вечер" << std::endl;
	return current->parent;
}

