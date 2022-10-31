//
// Created by 杨丰 on 2022/10/30.
//

#ifndef SOLVER_SOLVER_H
#define SOLVER_SOLVER_H

#include <vector>
#include <string>
#include <array>

// todo description
class Solver {
public:
    explicit Solver(int total) : total(total) {}

    void solve();

    void generator(uint32_t index, uint32_t &bits, std::string &expression);

    void print();

    static int calculate(const std::string &expression);

private:
    std::vector<std::string> result;
    int total;
};


#endif //SOLVER_SOLVER_H
