#pragma once

#include "isGameOver.h"

#include "DFS.h"

bool IS_GAME_OVER(char**& board, char player, int size) {
	bool** visited = new bool* [size];
	for (int i = 0; i < size; i++) {
		visited[i] = new bool[size];
		for (int j = 0; j < size; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < size; ++i) {
		if (player == 'b' && board[0][i] == 'b' && !visited[0][i]) {
			if (DFS(board, 0, i, 'b', visited, size)) {
				for (int j = 0; j < size; j++) {
					delete[] visited[j];
				}
				delete[] visited;
				return true;
			}


		}
		else if (player == 'r' && board[i][0] == 'r' && !visited[i][0]) {
			if (DFS(board, i, 0, 'r', visited, size)) {
				for (int j = 0; j < size; j++) {
					delete[] visited[j];
				}
				delete[] visited;
				return true;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		delete[] visited[i];
	}
	delete[] visited;
	return false;
}