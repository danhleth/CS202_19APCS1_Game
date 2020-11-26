#include "includePath.h"

bool IS_RUNNING = 1;

void exitGame(thread* t) {
	system("CLS");
	IS_RUNNING = false;
	t->join();
}

void ThreadFunc1() {
	while (IS_RUNNING) {
		system("PAUSE");
	}
}

