#include "CanWinIn2MoveWithNaiveOpponent.h"
#include <iostream>
#include "isBoardCorrect.h"
#include "isGameOver.h"
#include "pomocniczeFunkcje.h"
#include "isBoardPossible.h"


bool CAN_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT(char**& board, int size, int red, int blue, char kolor)
{
	int wolne_miejsca = size * size - (red + blue);
	if (wolne_miejsca <= 2
		|| !IS_BOARD_POSSIBLE(board, size, red, blue)
		|| !IS_BOARD_CORRECT(red, blue)
		|| IS_GAME_OVER(board, 'r', size)
		|| IS_GAME_OVER(board, 'b', size))
	{
		return false;
	}

	int wymagane_wolne_miejsca;
	if ((kolor == 'r') == (red == blue))
	{
		wymagane_wolne_miejsca = 3;
	}
	else
	{
		wymagane_wolne_miejsca = 4;
	}

	if (wolne_miejsca < wymagane_wolne_miejsca) {
		return false;
	}

	char** kopia = kopiaCalejTab(board, size);
	for (int row_1 = 0; row_1 < size; row_1++) {
		for (int col_1 = 0; col_1 < size; col_1++) {
			if (kopia[row_1][col_1] == ' ') {
				kopia[row_1][col_1] = kolor;
				for (int row_2 = 0; row_2 < size; row_2++) {
					for (int col_2 = 0; col_2 < size; col_2++) {
						if (kopia[row_2][col_2] == ' ') {
							kopia[row_2][col_2] = kolor;
							if (IS_GAME_OVER(kopia, kolor, size)) {
								kopia[row_1][col_1] = ' ';
								if (!IS_GAME_OVER(kopia, kolor, size)) {
									usunTablice(kopia, size);
									return true;
								}
								kopia[row_1][col_1] = kolor;
								kopia[row_2][col_2] = ' ';
								if (!IS_GAME_OVER(kopia, kolor, size)) {
									usunTablice(kopia, size);
									return true;
								}
							}
							kopia[row_2][col_2] = ' ';
						}
					}
				}
				kopia[row_1][col_1] = ' ';
			}
		}
	}

	usunTablice(kopia, size);
	return false;
}

