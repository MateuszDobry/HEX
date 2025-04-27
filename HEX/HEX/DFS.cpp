#include "DFS.h"

bool DFS(char**& board, int row, int col, char pionek, bool**& visited, int size) {

	visited[row][col] = true;
	//cout << endl;
	//cout << row << ";" << col <<";"<< pionek << endl;

	//for (int i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) {
	//		cout << visited[i][j];
	//	}
	//	cout << endl;
	//}
	//cout << endl;

	if (col == size - 1 && pionek == 'r') {
		return true;
	}
	if (row == size - 1 && pionek == 'b') {
		return true;
	}
	bool wynik = false;

	if (row + 1 < size && board[row + 1][col] == pionek && visited[row + 1][col] == false)
		wynik = wynik || DFS(board, row + 1, col, pionek, visited, size);
	if (col + 1 < size && board[row][col + 1] == pionek && visited[row][col + 1] == false)
		wynik = wynik || DFS(board, row, col + 1, pionek, visited, size);
	if (row + 1 < size && col + 1 < size && board[row + 1][col + 1] == pionek && visited[row + 1][col + 1] == false)
		wynik = wynik || DFS(board, row + 1, col + 1, pionek, visited, size);
	if (row - 1 >= 0 && board[row - 1][col] == pionek && visited[row - 1][col] == false)
		wynik = wynik || DFS(board, row - 1, col, pionek, visited, size);
	if (col - 1 >= 0 && board[row][col - 1] == pionek && visited[row][col - 1] == false)
		wynik = wynik || DFS(board, row, col - 1, pionek, visited, size);
	if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == pionek && visited[row - 1][col - 1] == false)
		wynik = wynik || DFS(board, row - 1, col - 1, pionek, visited, size);

	return wynik;
}
