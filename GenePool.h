#pragma once

#include <array>

class GenePool {
public:
    GenePool(); // �����������
    ~GenePool(); // ����������

    void initialize(); // ������������� ��������� ���������
    void evolve(int maxGenerations); // ������ ������������� ���������

private:
    // ����� �� ������ �������� ��������� ������ � ����� ������, ���� ����������
};
