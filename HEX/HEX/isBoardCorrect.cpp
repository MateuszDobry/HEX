#include "isBoardCorrect.h"

bool IS_BOARD_CORRECT(int red, int blue) {
	if (red == blue || red == blue + 1) {
		return true;
	}
	else {
		return false;
	}
}