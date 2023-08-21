#pragma once

#include <array>

class Entity {
public:
    // ������������
    Entity(); 
    Entity(const std::array<int, 4>& coefficients); 

    //�������
    std::array<int, 4> getCoefficients() const;
    std::array<double, 3> getRoots() const;
    
    // ������
    void mutate();
    Entity crossover(const Entity& other) const;
    void printEquation();

private:
    std::array<int, 4> coefficients;
    std::array<double, 3> roots;
};

