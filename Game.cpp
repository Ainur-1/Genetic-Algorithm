#include "Header.h"

// � ������ ���� ������ ��������� �� ������� ��������� ����� � ����� 4 �������� 
// 1 ���� �������� 2 �������� 

int players[10][3];   // ������ �� �������
int turn_list[10], check_list[10]; // ������� � ������������ ����������� �������� ��� ������ �����
int game_board[100]; // ������ ��� ������� �����. � ��� 2 �������: 0 - ������ �����, 1 - � ������ ����
int mine_number = 10; // ���������� ���������� ��� 
int death_toll = 0; // ���������� �������
int min_pos[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; // ������� ��� �� �����
// ������� �����. ������� (10*10). ���� (10). 
int map_initialization() {
	
	int mine; // ��� ����������� ���� ��������� ����

	// �������������� ���������� ������
	for (int i = 0; i < 100; i++) {
		game_board[i] = 0;
	}

	// ����������� ��� 
	int m = 0;
	while (m < 10) {
		mine = rand() % 100;
		if (mine % 11 != 0 && game_board[mine] != 1) {
			game_board[mine] = 1;
			min_pos[m] = mine;
			m++;
		}
	}

	// ����� ������� (����� ���) �� ������� (��� ������)
	/*cout << "\n" << "Mine map:" << endl;
	for (int i = 1; i < 101; i++) {
		cout << game_board[i-1] << " ";
		if (i % 10 == 0) cout << endl;
	}*/
	
	return 0;
}

// ������� ���������� ���������� ������ �� ������ �������� � ����.
int player_initialization() {

	// ��������������� ���������� ������ �� �������
	for (int i = 0; i <10; i++) {
		players[i][0] = 4; // ������ ������� �������� (4 ������)
		players[i][1] = i * 11; // ������ - ��������� �� �����
		players[i][2] = 0; // ������ - ���������� ���������� �����
	}

	// ����� �������� �� �������
	/*cout << "\n" << "Player information:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Player" << i << "  ";
		for (int j = 0; j < 3; j++) {
			cout << players[i][j] << " ";
		}
		cout << endl;
	}*/

	return 0;
}

// ���������� ���������� �������� ������. ��������� ��������� � turn_list[10] � check_list[10]
int player_turn(int new_popul[10][8]) {
	
	int i, j, sum_turn[10], sum_check[10];
	
	// ��������������� ���������� / ������
	for (i = 0; i < 10; i++) {
		sum_turn[i] = 0;
		sum_check[i] = 0;
		turn_list[i] = 0;
		check_list[i] = 0;

	}

	// ���������� ����� ��� ������������ ������ � ������� �������������
	for (j = 0; j < 10; j++) {

		// ��� ����.
		for (i = 0; i < 4; i++) {
			sum_turn[j] += new_popul[j][i];
		}

		// ��� ��������.
		for (i = 4; i < 8; i++) {
			sum_check[j] += new_popul[j][i];
		}
	}

	// ����� �������� � ������ (��� ������)
	/*cout << "\n" << "sum:" << endl;
	cout << "   t" << "   ch" << endl;
	for (i = 0; i < 10; i++) {
		cout << i << " " << sum_turn[i] << " " << sum_check[i] << endl;
	}*/

	// ��������� ����� ������� ���� � ������� �������� �� ���� � ������� ��������c����

	// ����� ����������� ���� ��� ���� ������
	for (i = 0; i < 10; i++) {

		// �������� � ������ % ��������� ���������� ������� 
		int fortune_turn = rand() % sum_turn[i] + 1;
		int accumulation_turn = new_popul[i][0];

		// ����� ������ ������� ��������� � ������ � ������������ ��� ������ ����� turn_list[10]
		if (fortune_turn <= new_popul[i][0]) {
			turn_list[i] = 0;
		}

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= accumulation_turn + new_popul[i][1]) {
			turn_list[i] = 1;
		}
		accumulation_turn += new_popul[i][1];

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= accumulation_turn + new_popul[i][2]) {
			turn_list[i] = 2;
		}
		accumulation_turn += new_popul[i][2];

		if (accumulation_turn + 1 <= fortune_turn && fortune_turn <= sum_turn[i]) {
			turn_list[i] = 3;
		}
	
	}

	// ����� ����������� �������� �� ���������� ���� ��� ���� ������
	for (i = 0; i < 10; i++) {

		// �������� � ������ % ��������� ���������� ������� 
		int fortune_check = rand() % sum_check[i] + 1;
		int accumulation_check = new_popul[i][4];

		// ����� ������ ������� ��������� � ������ � ������������ ��� ������ ����� check_list[10]
		if (fortune_check <= new_popul[i][4]) {
			check_list[i] = 0;
		}

		if (accumulation_check + 1 <= fortune_check && fortune_check <= accumulation_check + new_popul[i][5]) {
			check_list[i] = 1;
		}
		accumulation_check += new_popul[i][5];

		if (accumulation_check + 1 <= fortune_check && fortune_check <= accumulation_check + new_popul[i][6]) {
			check_list[i] = 2;
		}
		accumulation_check += new_popul[i][6];

		if (accumulation_check + 1 <= fortune_check && fortune_check <= sum_check[i]) {
			check_list[i] = 3;
		}

	}

	// ����� �������� � ������������ �������� (��� ������)
	/*cout << "\n" << "Individual actions:" << endl;
	cout << "   Turn" << "  Cheeck" << endl;
	for (i = 0; i < 10; i++) {
		cout << i << "     " << turn_list[i] << "       " << check_list[i] << endl;
	}*/

	return 0;
}

// ���������� �������� ������
int turn(int players[10][3], int turn_list[10], int check_list[10], int game_board[100]) {

	// ����� ��������� ��������� �����
	cout << "\n" << "Map:" << endl;
	for (int j = 0; j < 100; j++) {  // �������� �� ���� ������� �����
		bool is_written = false; // �������� �� �����?
		bool occupied = false; // ����� ��� ������ �������?

		// �������� �� ���� �����
		for (int i = 0; i < 10; i++) {
			bool on_a_mine = false; // ����� ����� �� ���� i?
			bool re_on_a_mine = false; // ���� � ����� i �� ����� ������?

			// �������� ����� �� ����� �� ���� i
			for (int k = 0; k < 10; k++) {
				if (min_pos[i] == players[k][1]) on_a_mine = true;
				if (players[i][1] == min_pos[k]) re_on_a_mine = true;
			}

			// 1 - ����
			if (j == min_pos[i] && on_a_mine == false) {
				cout << "1 ";
				is_written = true;
			}

			// 2 - ������
			if (j == players[i][1] && occupied == false && re_on_a_mine == false) {
				cout << "2 ";
				occupied = true;
				is_written = true;
			}

			// 3 - ����� �������� �� ����
			if (j == min_pos[i] && on_a_mine == true) {
				cout << "3 "; 
				is_written = true;
			}

			on_a_mine = false;
			re_on_a_mine = false;
		}

		if (is_written != true) cout << "0 "; // 0 - ������ ������
		if (j % 10 == 9) cout << endl;
		is_written = false;
		occupied = false;
	}
	
	int there_is_mine[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // ���� �� ���� �� �������, ������� �����������? (0 - ���/1 - ��)

	// 0 - ����� (-10); 1 - ������ (+1);  2 - ���� (+10); 3 - ����� (-1)
	// �������� �� ����
	for (int i = 0; i < 10; i++) {

		// 0 - ����� (-10)
		if (check_list[i] == 0) {
			if (game_board[players[i][1] - 10] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 1 - ������ (+1)
		if (check_list[i] == 1) {
			if (game_board[players[i][1] + 1] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 2 - ���� (+10)
		if (check_list[i] == 2) {
			if (game_board[players[i][1] + 10] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}

		// 3 - ����� (-1)
		if (check_list[i] == 3) {
			if (game_board[players[i][1] - 1] == 1) {
				there_is_mine[i] = 1;
				mine_number -= 1;
			}
		}
	}

	// ����� ���������� �������� (��� ������)
	/*for (int i = 0; i < 10; i++) {
		cout << i << " " << there_is_mine[i] << endl;
	}*/
	
	// ����������� ������ �� ����. 
	for (int i = 0; i < 10; i++) {
		// ���� �� �����, ��� � ����� ���������� ����, ��� ��� �� ������� �������� ����, �� ������� �� �����.

		// 0 - ����� (-10)
		if (turn_list[i] == 0 && players[i][1] > 9) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] -= 10;
			}
			players[i][2] += 1; // +1 � �-�� �����
		}

		// 1 - ������ (+1)
		if (turn_list[i] == 1 && players[i][1] % 10 != 9) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] += 1;
			}
			players[i][2] += 1; // +1 � �-�� �����
		}

		// 2 - ���� (+10)
		if (turn_list[i] == 2 && players[i][1] < 90) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] += 10;
			}
			players[i][2] += 1; // +1 � �-�� �����
		}

		// 3 - ����� (-1)
		if (turn_list[i] == 3 && players[i][1] % 10 != 0) {
			if (!(there_is_mine[i] == 1 && check_list[i] == turn_list[i])) {
				players[i][1] -= 1;
			}
			players[i][2] += 1; // +1 � �-�� �����
		}
	}

	// ����������� ��������� �� ����.
	for (int i = 0; i < 10; i++) {
		if (game_board[players[i][1]] == 1) {
			mine_number -= 1; // ��������� �������� �������� �������� ��� 
			players[i][0] -= 2; // �������� �����
			game_board[players[i][1]] = 0; // ������� ���� � ����

			// ���� ����� ��������� �� ����� ������������ � ������ ����� - 1
			if (players[i][0] <= 0) {
				players[i][1] = -1;
				death_toll += 1;
			}
		}
	}

	// ���� ���� ���������, �� �������� ������ ����������� �� ��������� �������
	if (mine_number == 0) {
		for (int i = 0; i < 10; i++) {
			if (players[i][1] != -1) {
				players[i][1] == i * 11;
			}
		}
	}

	return 0;
}

// �������� ������� �������
int game() {

	map_initialization();
	player_initialization();

	while (death_toll < 10) {
		if (mine_number == 0)  map_initialization();
		player_turn(new_popul);
		turn(players, turn_list, check_list, game_board);
	}

	return 0;
}