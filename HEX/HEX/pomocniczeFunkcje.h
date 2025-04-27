#pragma once

char** kopiaTab(char**& board, int size, char kolor);
char** kopiaCalejTab(char**& board, int size);
void usunPionek(char**& board, int numer, int size);
void transpose(char** arr, int size);
void usunTablice(char* tab[], int size);
void debugPrintBoard(char* tab[], int size);
int ileSpacji(char**& board, int size);
