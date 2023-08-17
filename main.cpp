#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <cmath>

void printFormattedNumber(int num) {
    if (num == 100)
        std::cout << num << " ";
    else if (num < 10)
        std::cout << "  " << num << " ";
    else if (num >= 10 && num < 100)
        std::cout << " " << num << " ";
}

void printPopulation(int Generation_Number, std::array<std::array<int, 4>, 10> new_popul) {

    std::cout << "\nGeneration " << Generation_Number << std::endl;
    std::cout << " Chromosome " << "     a   b   c   d " << "\n\n";

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

    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";

    std::array<int, 4> coefficients; // ������������ ����������� ���������

    // ���� �������������
    std::cout << "Enter the coefficients a, b, c, and d: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cin >> coefficients[i];
    }

    std::array<double, 3> roots; // ����� ����������� ���������

    // ���� ������
    std::cout << std::endl << "Enter the roots a, b, and c: " << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cin >> roots[i];
    }

    std::cout << std::endl << "Cubic Equation: " << coefficients[0] << "x^3 + "
        << coefficients[1] << "x^2 + " << coefficients[2] << "x + " << coefficients[3] << " = 0" << std::endl;

    std::cout << "Equation Roots: " << roots[0] << ", " << roots[1] << ", " << roots[2] << std::endl;
    
    int Generation_Number = 1;
    int sellist[4];

    std::array<std::array<int, 4>, 10> new_popul = initial_population();
    printPopulation(Generation_Number, new_popul);

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