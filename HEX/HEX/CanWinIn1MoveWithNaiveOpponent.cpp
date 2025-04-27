#include "CanWinIn1MoveWithNaiveOpponent.h"
#include <iostream>
#include "isBoardCorrect.h"
#include "isGameOver.h"
#include "pomocniczeFunkcje.h"
#include "isBoardPossible.h"
#include "isBoardCorrect.h"

bool CAN_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT(char**& board, int size, int red, int blue, char kolor)
{
	int wolne_miejsca = size * size - (red + blue);
	if (wolne_miejsca == 0
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
		wymagane_wolne_miejsca = 1;
	}
	else
	{
		wymagane_wolne_miejsca = 2;
	}

	if (wolne_miejsca < wymagane_wolne_miejsca) {
		return false;
	}

	char** kopia = kopiaCalejTab(board, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (kopia[i][j] == ' ') {
				kopia[i][j] = kolor;
				if (IS_GAME_OVER(kopia, kolor, size)) {
					usunTablice(kopia, size);
					return true;
				}
				else {
					kopia[i][j] = ' ';
				}
			}
		}
	}

	usunTablice(kopia, size);
	return false;
}








//bool CAN_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT(char**& board, int size, int red, int blue, char kolor) {
//
//	int ogr1 = 0, ogr2 = 0;
//	switch (kolor) {
//	case 'r':
//		ogr1 = 1;
//		ogr2 = 2;
//		break;
//	case 'b':
//		ogr1 = 2;
//		ogr2 = 1;
//		break;
//	}
//		
//	if (IS_BOARD_POSSIBLE(board, size, red, blue)) {
//		if (IS_BOARD_CORRECT(red, blue)) {
//			if (!IS_GAME_OVER(board, 'r', size) && !IS_GAME_OVER(board, 'b', size)) {
//				char** kopia = kopiaCalejTab(board, size);
//				int wolneMiejsca = ileSpacji(board, size); // size*size - (red+blue);
//				if (red == blue) {
//					if (wolneMiejsca < ogr1) {
//						usunTablice(kopia, size);
//						return false;
//					}
//					else {
//						for (int i = 0; i < size; i++) {
//							for (int j = 0; j < size; j++) {
//								if (kopia[i][j] == ' ') {
//									kopia[i][j] = kolor;
//									if (IS_GAME_OVER(kopia, kolor, size)) {
//										usunTablice(kopia, size);
//										return true;
//									}
//									else {
//										kopia[i][j] = ' ';
//									}
//								}
//							}
//						}
//					}
//				}
//				else {
//					if (wolneMiejsca < ogr2) {
//						usunTablice(kopia, size);
//						return false;
//					}
//					else {
//						for (int i = 0; i < size; i++) {
//							for (int j = 0; j < size; j++) {
//								if (kopia[i][j] == ' ') {
//									kopia[i][j] = kolor;
//									if (IS_GAME_OVER(kopia, kolor, size)) {
//										usunTablice(kopia, size);
//										return true;
//									}
//									else {
//										kopia[i][j] = ' ';
//									}
//								}
//							}
//						}
//					}
//				}
//				usunTablice(kopia, size);
//			}
//			return false;
//		}
//		return false;
//	}
//	return false;
//}
