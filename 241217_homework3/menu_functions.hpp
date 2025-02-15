#pragma once

#include "menu.hpp"


namespace IBusko {
	const MenuItem* show_menu(const MenuItem* current);

	const MenuItem* exit(const MenuItem* current);
	
	const MenuItem* writer_pushkin(const MenuItem* current);
	const MenuItem* writer_lermontov(const MenuItem* current);
	const MenuItem* writer_krilov(const MenuItem* current);
	const MenuItem* writer_go_back(const MenuItem* current);

	const MenuItem* pushkin_dubrovsky(const MenuItem* current);
	const MenuItem* pushkin_eugene_onegin(const MenuItem* current);
	const MenuItem* pushkin_winter_evening(const MenuItem* current);
}
