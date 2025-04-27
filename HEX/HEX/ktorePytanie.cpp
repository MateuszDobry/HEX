#include "ktorePytanie.h"

int ktorePytanie(std::string tab) {
	if (tab[0] == 'B') {
		return 1;
	}
	else if (tab[0] == 'P') {
		return 2;
	}
	else if (tab[0] == 'I') {
		if (tab[3] == 'B') {
			if (tab[9] == 'C') {
				return 3;
			}
			else {
				return 5;
			}
		}
		else {
			return 4;
		}
	}
	else {
		if (tab[4] == 'R') {
			if (tab[15] == '1') {
				if (tab[27] == 'N') {
					return 6;
				}
				else {
					return 10;
				}
			}
			else {
				if (tab[28] == 'N') {
					return 8;
				}
				else {
					return 12;
				}
			}
		}
		else {
			if (tab[16] == '1') {
				if (tab[28] == 'N') {
					return 7;
				}
				else {
					return 11;
				}
			}
			else {
				if (tab[29] == 'N') {
					return 9;
				}
				else {
					return 13;
				}
			}
		}
	}
}