﻿#include <iostream>
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

// Генерация начальной популяции с случайными коэффициентами
std::array<std::array<int, 4>, 10> initial_population() {
    std::array<std::array<int, 4>, 10> new_popul;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            new_popul[i][j] = rand() % 101;
        }
    }

    return new_popul;
}

std::array<double, 3> solveCubicEquation(const std::array<int, 4>& coefficients) {
    double a = coefficients[0];
    double b = coefficients[1];
    double c = coefficients[2];
    double d = coefficients[3];

    // Calculate discriminants and intermediate values
    double discriminant = 18 * a * b * c * d - 4 * b * b * b * d + b * b * c * c - 4 * a * c * c * c - 27 * a * a * d * d;
    double delta0 = b * b - 3 * a * c;
    double delta1 = 2 * b * b * b - 9 * a * b * c + 27 * a * a * d;

    // Calculate roots
    std::array<double, 3> roots;

    if (discriminant > 0) {
        double C = cbrt((delta1 + sqrt(discriminant)) / 2.0);
        double D = cbrt((delta1 - sqrt(discriminant)) / 2.0);
        roots[0] = (-b + C + D) / (3 * a);
    }
    else if (discriminant == 0) {
        roots[0] = -b / (3 * a);
    }
    else {
        double phi = acos(delta1 / (2 * sqrt(-delta0 * delta0 * delta0)));
        double magnitude = 2 * sqrt(-delta0);
        const double pi = 3.14159265358979323846; // Число π
        roots[0] = magnitude * cos(phi / 3) - b / (3 * a);
        roots[1] = magnitude * cos((phi + 2 * pi) / 3) - b / (3 * a);
        roots[2] = magnitude * cos((phi + 4 * pi) / 3) - b / (3 * a);
    }

    return roots;
}

// Оценка приспособленности особей (близость к корням)
std::array<double, 10> fitness_evaluation(const std::array<std::array<int, 4>, 10>& population,
    const std::array<double, 3>& target_roots) {
    std::array<double, 10> fitness;

    for (int i = 0; i < 10; i++) {
        double total_distance = 0.0;

        for (int j = 0; j < 3; j++) {
            std::array<double, 3> roots = solveCubicEquation(population[i]);
            for (int k = 0; k < 3; k++) {
                double distance = std::abs(roots[k] - target_roots[j]);
                total_distance += distance;
            }
        }

        fitness[i] = 1.0 / total_distance;
    }

    return fitness;
}

//// Выбор особей для следующего поколения
//void selection(double coefficients[10][4]) {
//    // Здесь реализация выбора особей для создания следующего поколения
//    // Можно использовать методы селекции, такие как рулеточное колесо или турнирная селекция.
//    // sellist будет хранить индексы выбранных особей.
//}

int main() {
    srand(time(NULL));

    std::cout << "New Genetic Algorithm for Cubic Equation\n\n";

    std::array<int, 4> coefficients; // Коэффициенты кубического уравнения

    // Ввод коэффициентов
    std::cout << "Enter the coefficients a, b, c, and d: " << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cin >> coefficients[i];
    }

    std::array<double, 3> roots; // Корни кубического уравнения

    // Ввод корней
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

    std::array<double, 3> roots = solveCubicEquation(coefficients);

    // Основной цикл генетического алгоритма
    while (true) {
        // Оценка приспособленности
        std::array<double, 10> fitness_values = fitness_evaluation(new_popul, roots);

        // Выбор особей для следующего поколения
        //selection(coefficients);

        // Создание новой популяции на основе выбранных особей
        // Мутация и скрещивание могут быть реализованы здесь

        Generation_Number++;
    }

    // Вывод результирующего уравнения
    // Здесь можно взять лучший набор коэффициентов и вывести полученное уравнение

    return 0;
}