#include <iostream>
#include <cstdlib>
#include <cmath>

int Generation_Number = 1;
int sellist[4];
int new_popul[10][4]; // �������� ������ ������� ��� �������� �������������

// ��������� ��������� ��������� � ���������� ��������������
int initial_population() {
    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";
    int i, j;

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";
    for (i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";
        for (j = 0; j < 4; j++) {
            new_popul[i][j] = rand() % 101;
            if (new_popul[i][j] == 100)
                std::cout << new_popul[i][j] << " ";
            if (new_popul[i][j] < 10)
                std::cout << "  " << new_popul[i][j] << " ";
            if (new_popul[i][j] > 9 && new_popul[i][j] < 100)
                std::cout << " " << new_popul[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}

// ������ ����������������� ������ (� ������ ������ - �������� � �����)
double fitness_evaluation(double coefficients[10][4], double target_root) {
    double fitness[10];
    for (int i = 0; i < 10; i++) {
        double result = coefficients[i][0] + coefficients[i][1] * target_root +
            coefficients[i][2] * target_root * target_root +
            coefficients[i][3] * target_root * target_root * target_root;
        fitness[i] = 1.0 / std::abs(result - target_root);
    }
    // ����� ����� ����� ������������� �����������������, ����� ����� ���� 1.
    return fitness;
}

// ����� ������ ��� ���������� ���������
void selection(double coefficients[10][4]) {
    // ����� ���������� ������ ������ ��� �������� ���������� ���������
    // ����� ������������ ������ ��������, ����� ��� ���������� ������ ��� ��������� ��������.
    // sellist ����� ������� ������� ��������� ������.
}

int main() {
    srand(time(NULL));

    double target_root = 3.0; // ������, ������� �� ����� �����
    double coefficients[10][4]; // ������������ ����������� ���������

    initial_population();

    // �������� ���� ������������� ���������
    while (/*������� ���������*/) {
        // ������ �����������������
        double fitness_values[10];
        fitness_values = fitness_evaluation(coefficients, target_root);

        // ����� ������ ��� ���������� ���������
        selection(coefficients);

        // �������� ����� ��������� �� ������ ��������� ������
        // ������� � ����������� ����� ���� ����������� �����

        Generation_Number++;
    }

    // ����� ��������������� ���������
    // ����� ����� ����� ������ ����� ������������� � ������� ���������� ���������

    return 0;
}
