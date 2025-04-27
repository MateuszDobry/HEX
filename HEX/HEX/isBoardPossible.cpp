#pragma once

#include "isBoardPossible.h"

#include <iostream>

#include "isBoardCorrect.h"
#include "isGameOver.h"
#include "pomocniczeFunkcje.h"

bool IS_BOARD_POSSIBLE(char**& board, const int size, const int red, const int blue) {
	//debugPrintBoard(board, size);
	if (IS_BOARD_CORRECT(red, blue)) {
		if (IS_GAME_OVER(board, 'r', size)) {
			if (red - 1 == blue) {
				bool czyRazPrzegral = false;
				for (int i = 0; i < red && !czyRazPrzegral; i++) {
					char** kopia = kopiaTab(board, size, 'r');
					usunPionek(kopia, i, size);
					if (!IS_GAME_OVER(kopia, 'r', size)) {
						czyRazPrzegral = true;
					}
					usunTablice(kopia, size);
				}
				return czyRazPrzegral;
			}
			else {
				return false;
			}
		}
		else if (IS_GAME_OVER(board, 'b', size)) {
			if (red == blue) {
				bool czyRazPrzegral = false;
				for (int i = 0; i < blue && !czyRazPrzegral; i++) {
					char** kopia = kopiaTab(board, size, 'b');
					//std::cout << "[DEBUG]\ttestowanie kopii nr: " << i + 1 << "\n";
					//debugPrintBoard(kopia, size);
					usunPionek(kopia, i, size);
					//debugPrintBoard(kopia, size);
					if (!IS_GAME_OVER(kopia, 'b', size)) {
						czyRazPrzegral = true;
					}
					usunTablice(kopia, size);
				}
				return czyRazPrzegral;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	}
	else {
		return false;
	}
}