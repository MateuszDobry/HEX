#include <iostream>
#include <string>
#include <vector>

#include "isBoardCorrect.h"
#include "isBoardPossible.h"
#include "isGameOver.h"
#include "ktorePytanie.h"
#include "pomocniczeFunkcje.h"
#include "CanWinIn1MoveWithNaiveOpponent.h"
#include "CanWinIn2MoveWithNaiveOpponent.h"

using namespace std;

int main()
{
	int counter = 0;
	char c = ' ';
pkt2:
	
	while (c = (char)getchar() != EOF) {
		static bool czyPierwszy = false;
		int red, blue;
		red = blue = 0;
		int size;
		if (czyPierwszy == false) {
			 size = 0;
			 czyPierwszy = true;
		}
		else {
			size = 1;
		}
		while (c != '-') {
			c = (char)getchar();
			size++;
		}
		//counter++;
		size /= 3;
		size++;

		while (getchar() != '\n');  // ZACZYNA WCZYTYWAC OD 2 ' - '
		
		char** board = new char* [size];
		for (int i = 0; i < size; i++) {
			board[i] = new char[size];
		}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				board[i][j] = '0';
			}
		}
		for (int i = 0; i < 2 * size - 1; i++) {
			//counter++;
			c = '0';
			int j = 0;
			while (c != '\n') {
				
				c = (char)getchar();

				if (c == '<') {
					c = (char)getchar();
					if (c == ' ') {
						c = (char)getchar();
						if (i < size) {
							board[j][i - j] = c;
						}
						else {
							board[i - size + 1 + j][size - 1 - j] = c;
						}

						if (c == 'r') {
							red++;
						}
						if (c == 'b') {
							blue++;
						}
					}
					j++;
				}
			}
		}
		transpose(board, size);
		while (getchar() != '\n'); /// TUTAJ KONCZY WCZYTYWAC PLANSZE
		//counter++;
		string pytanie = "";
		pytanie.reserve(45);
	pkt:

		while (pytanie[0] != '\n') {
			char z = '0';
			z = (char)getchar();
			if (z == ' ') {
				goto pkt2;
			}
			getline(cin, pytanie);
			//counter++;
			
			pytanie.insert(0,1,z);
		
			if (pytanie[0] == '\0') {
				pytanie[0] = '\n';
			}
			if (pytanie[0] == '\n') {
				goto pkt;
			}
			int nrPytania = ktorePytanie(pytanie);
			if (nrPytania == 1) {
				cout << size << endl;
			}
			else if (nrPytania == 2) {
				cout << red + blue << endl;
			}
			else if (nrPytania == 3) {
				if (IS_BOARD_CORRECT(red, blue)) {
					cout << "YES" << endl;
				}
				else
					cout << "NO" << endl;
			}
			else if (nrPytania == 4) {
				if (IS_BOARD_CORRECT(red, blue)) {


					if (IS_GAME_OVER(board, 'r', size)) {
						cout << "YES RED" << endl;
					}
					else if (IS_GAME_OVER(board, 'b', size)) {
						cout << "YES BLUE" << endl;
					}
					else {
						cout << "NO" << endl;
					}
				}
				else {
					cout << "NO" << endl;
				}

			}
			else if (nrPytania == 5) {
				if (IS_BOARD_POSSIBLE(board, size, red, blue)) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
			else if (nrPytania == 6) {
			if (CAN_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT(board,size, red, blue,'r')) {
					cout << "YES";
				}
				else {
					cout << "NO";
				}
			}
			else if (nrPytania == 7) {
				if (CAN_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT(board, size, red, blue, 'b')) {
					cout << "YES";
				}
				else {
					cout << "NO";
				}
			}
			else if (nrPytania == 8) {
				if (CAN_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT(board, size, red, blue, 'r')) {
					cout << "YES";
				}
				else {
					cout << "NO";
				}
			}
			else if(nrPytania == 9){
				counter++;
				if (CAN_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT(board, size, red, blue, 'b')) {
					cout << "YES" << endl;
				}
				else {
					cout << "NO" << endl;
				}
			}
			else if (nrPytania == 10) {
				continue;
			}
			else if (nrPytania == 11) {
				continue;
			}
			else if (nrPytania == 12) {
				continue;
			}
			else if (nrPytania == 13) {
				continue;
			}
			cout << endl;
			
		}
		//cout << counter;
		pytanie.resize(0);
		usunTablice(board, size);	
	}

	
	return 0;

}

