#pragma once

#include <array>

class Entity {
public:
    Entity(); // ����������� �� ���������
    Entity(const std::array<int, 4>& coefficients); // ����������� � ��������������

    // ������ ��� �������� � Entity
    std::array<int, 4> getCoefficients() const;
    void mutate();
    Entity crossover(const Entity& other) const;

private:
    std::array<int, 4> coefficients;
};

