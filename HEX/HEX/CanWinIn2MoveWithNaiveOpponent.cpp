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











//bool CAN_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT(char**& board, int size, int red, int blue, char kolor)
//{
//	int ogr1 = 0, ogr2 = 0;
//	switch (kolor) {
//	case 'r':
//		ogr1 = 3;
//		ogr2 = 4;
//		break;
//		case 'b':
//		ogr1 = 4;
//		ogr2 = 3;
//		break;
//	}
//	
//	if (IS_BOARD_POSSIBLE(board, size, red, blue)) {
//		if (!IS_GAME_OVER(board, 'r', size) && !IS_GAME_OVER(board,'b',size)) {
//			char** kopia = kopiaCalejTab(board, size);
//			int wolneMiejsca = ileSpacji(board, size);
//			if (red == blue) {
//				if (wolneMiejsca < ogr1) {
//					usunTablice(kopia, size);
//					return false;
//			}
//				else {
//					for (int i = 0; i < size; i++) {
//						for (int j = 0; j < size; j++) {
//							if (kopia[i][j] == ' ') {
//								kopia[i][j] = kolor;
//								if (!IS_GAME_OVER(kopia, kolor, size)) {
//									for (int k = 0; k < size; k++) {
//										for (int l = 0; l < size; l++) {
//											if (kopia[k][l] == ' ') {
//												kopia[k][l] = kolor;
//												if (IS_GAME_OVER(kopia, kolor, size)) {
//													usunTablice(kopia, size);
//													return true;
//												}
//												else {
//													kopia[k][l] = ' ';
//												}
//											}
//										}
//									}
//									
//								}
//								kopia[i][j] = ' ';
//							}
//						}
//					}
//				}
//
//			}
//			else {
//				if (wolneMiejsca < ogr2) {
//					usunTablice(kopia, size);
//					return false;
//				}
//				else {
//					for (int i = 0; i < size; i++) {
//						for (int j = 0; j < size; j++) {
//							if (kopia[i][j] == ' ') {
//								kopia[i][j] = kolor;
//								if (!IS_GAME_OVER(kopia, kolor, size)) {
//									for (int k = 0; k < size; k++) {
//										for (int l = 0; l < size; l++) {
//											if (kopia[k][l] == ' ') {
//												kopia[k][l] = kolor;
//												if (IS_GAME_OVER(kopia, kolor, size)) {
//													usunTablice(kopia, size);
//													return true;
//												}
//												else {
//													kopia[k][l] = ' ';
//												}
//											}
//										}
//									}
//									
//								}
//								kopia[i][j] = ' ';
//							}
//						}
//					}
//				}
//			}
//			usunTablice(kopia, size);
//		}
//		return false;
//	}
//	return false;
//
//
//
//}
