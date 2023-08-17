#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}

void printPopulation(std::array<std::array<int, 4>, 10> new_popul) {
    for (int i = 0; i < 10; i++) {
        std::cout << "Individual " << i << "   ";

        for (int j = 0; j < 4; j++) {
            printFormattedNumber(new_popul[i][j]);
        }

        std::cout << std::endl;
    }
}

// ��������� ��������� ��������� � ���������� ��������������
std::array<std::array<int, 4>, 10> initial_population() {
    std::array<std::array<int, 4>, 10> new_popul;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            new_popul[i][j] = rand() % 101;
        }
    }

    return new_popul;
}

//// ������ ����������������� ������ (� ������ ������ - �������� � �����)
//double fitness_evaluation(double coefficients[10][4], double target_root) {
//    double fitness[10];
//    for (int i = 0; i < 10; i++) {
//        double result = coefficients[i][0] + coefficients[i][1] * target_root +
//            coefficients[i][2] * target_root * target_root +
//            coefficients[i][3] * target_root * target_root * target_root;
//        fitness[i] = 1.0 / std::abs(result - target_root);
//    }
//    // ����� ����� ����� ������������� �����������������, ����� ����� ���� 1.
//    return fitness;
//}
//
//// ����� ������ ��� ���������� ���������
//void selection(double coefficients[10][4]) {
//    // ����� ���������� ������ ������ ��� �������� ���������� ���������
//    // ����� ������������ ������ ��������, ����� ��� ���������� ������ ��� ��������� ��������.
//    // sellist ����� ������� ������� ��������� ������.
//}

int main() {
    srand(time(NULL));
    
    int Generation_Number = 1;
    int sellist[4];

    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";
    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

    std::array<std::array<int, 4>, 10> new_popul = initial_population();

    printPopulation(new_popul);

    double target_root = 3.0; // ������, ������� �� ����� �����
    double coefficients[10][4]; // ������������ ����������� ���������

    //// �������� ���� ������������� ���������
    //while (/*������� ���������*/) {
    //    // ������ �����������������
    //    double fitness_values[10];
    //    fitness_values = fitness_evaluation(coefficients, target_root);

    //    // ����� ������ ��� ���������� ���������
    //    selection(coefficients);

    //    // �������� ����� ��������� �� ������ ��������� ������
    //    // ������� � ����������� ����� ���� ����������� �����

    //    Generation_Number++;
    //}

    // ����� ��������������� ���������
    // ����� ����� ����� ������ ����� ������������� � ������� ���������� ���������

    return 0;
}
