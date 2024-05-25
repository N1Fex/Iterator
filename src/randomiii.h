#pragma once
#include "List.h"
#include "Man.h"
#include <ctime>

Man getRandomMan() {
	Man m("Man", "Manov", rand() % 60 + 10, rand() % 50 + 40);
	return m;
}

void randomlyFill(Container<int>& con, int count) {
	for (int i = 0; i < count; i++) {
		con.addElement(rand() % 100);
	}
}

void randomlyFillMan(Container<Man>& con, int count) {
	for (int i = 0; i < count; i++) {
		con.addElement(getRandomMan());
	}
}