#include "pomocniczeFunkcje.h"

#include<iostream>
#include<string>

char** kopiaTab(char**& board, int size, char kolor) {
	char** kopia = new char* [size];
	for (int i = 0; i < size; i++) {
		kopia[i] = new char[size];
		for (int j = 0; j < size; j++) {
			if (board[i][j] == kolor) {
				kopia[i][j] = kolor;
			}
			else
			{
				kopia[i][j] = ' ';
			}
		}
	}
	return kopia;
}

char** kopiaCalejTab(char**& board, int size) {
	char** kopia = new char* [size];
	for (int i = 0; i < size; i++) {
		kopia[i] = new char[size];
		for (int j = 0; j < size; j++) {
			kopia[i][j] = board[i][j];
		}
	}
	return kopia;
}

void usunPionek(char**& board, int numer, int size) {
	int counterP = 0;
	for (int row = 0; row < size; row++) {
		for (int col = 0; col < size; col++) {
			if (board[row][col] != ' ') {
				if (counterP == numer) {
					board[row][col] = ' ';
					return;
				}
				counterP++;
			}
		}
	}
}

void transpose(char** arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			std::swap(arr[i][j], arr[j][i]);
		}
	}
}

void usunTablice(char* tab[], int size) {
	for (int i = 0; i < size; i++) {
		delete[] tab[i];
	}
	delete[] tab;
}


int ileSpacji(char**& board, int size)
{
	int counter = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == ' ') {
				counter++;
			}
		}
	}
	return counter;
}
