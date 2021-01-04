#include "Header.h"

int Generation_Number = 1; // ������ ���������.
int sellist[4];  // ������ � ��������� ������ �������� ���������������

// ������ ����� ���������. 
// ������ ����� ������� �� 8 �����: [a][b][c][d]. ��� ���� � ��� �������� ������
// [a] - �����, [b] - ����, [c] - ������, [d] - �����
int new_popul[10][8]; 

// ������� ���������� ��������� ��������� �� ���������� ������
int initial_population() {

	// ����� ������� �� 8 �����, � ��������� 10 ������.
	cout << "New Genetic Algorithm " << "\n" << endl;

	int i, j;

	// ������� ��������� ���������.
	cout << "\n" << "Generation " << Generation_Number << endl;
	cout << "                      Move           Check" << "\n";
	cout << " Chromosome " << "     a   b   c   d " << "   a   b   c   d " << "\n" << "\n";
	for (i = 0; i < 10; i++) {

		cout << "Individual " << i << "   ";

		for (j = 0; j < 8; j++) {

			new_popul[i][j] = rand() % 101;

			if (new_popul[i][j] == 100)
				cout << new_popul[i][j] << " ";

			if (new_popul[i][j] < 10)
				cout << "  " << new_popul[i][j] << " ";

			if (new_popul[i][j] > 9 && new_popul[i][j] < 100)
				cout << " " << new_popul[i][j] << " ";

			if (j == 3)
				cout << '|';
		}

		cout << endl;
	}

	return 0;
}

// ������� ����������������� ������
int selection(int players[10][3]) {

	int i;
	int sum = 0; // ������ ����� ���� ����� (�������� players[i][2])
	int fitness[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };; // ���������������� ������ �����

	// ��������� ����� �����
	for (i = 0; i < 10; i++) {
		sum += players[i][2];
	}

	int accumulation = players[0][2];
	int winning_individual; // ������ ���������� �����.
	int winner = 0; // ���������� ������������ ������

	while (winner != 4) {
		int fortune = rand() % sum + 1; // ��������� ���������� ������ 

		if (fortune <= players[0][2]) {
			winning_individual = 0;
		}
		else {
			for (i = 1; i < 9; i++) {
				if (accumulation + 1 <= fortune && fortune <= accumulation + players[i][2]) {
					winning_individual = i;
				}
				accumulation += players[i][2];
			}
			if (accumulation + 1 <= fortune && fortune <= 10000) {
				winning_individual = 9;
			}
		}
		sellist[winner] = winning_individual;
		accumulation = players[0][2];
		winner += 1;
	}

	return 0;
}