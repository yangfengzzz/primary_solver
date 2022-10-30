//
// Created by 杨丰 on 2022/10/30.
//

#include "Solver.h"
#include <cmath>
#include <iostream>

void Solver::solve() {
    for (int i = 0; i < std::pow(3, 8); ++i) {
        std::string expression = "1 2 3 4 5 6 7 8 9";
        uint32_t bits = i;
        generator(0, bits, expression);
        if (Solver::calculate(expression) == total) {
            result.push_back(expression);
        }
    }
}

void Solver::generator(uint32_t index, uint32_t &bits, std::string &expression) {
    uint32_t type = bits % 3;
    if (type == 0) {
        expression[index * 2 + 1] = ' ';
    } else if (type == 1) {
        expression[index * 2 + 1] = '+';
    } else if (type == 2) {
        expression[index * 2 + 1] = '-';
    }

    if (index != 7) {
        bits /= 3;
        generator(index + 1, bits, expression);
    }
}

int Solver::calculate(const std::string &expression) {
    assert(expression.size() == 17);
    int totalCount = 0;
    int current = 0;
    char lastExpression = '+';
    for (const char &c: expression) {
        switch (c) {
            case '+':
                if (lastExpression == '+') {
                    totalCount += current;
                } else {
                    totalCount -= current;
                }
                current = 0;
                lastExpression = '+';
                break;
            case '-':
                if (lastExpression == '+') {
                    totalCount += current;
                } else {
                    totalCount -= current;
                }
                current = 0;
                lastExpression = '-';
                break;
            case ' ':
                break;
            case '1':
                current = current * 10 + 1;
                break;
            case '2':
                current = current * 10 + 2;
                break;
            case '3':
                current = current * 10 + 3;
                break;
            case '4':
                current = current * 10 + 4;
                break;
            case '5':
                current = current * 10 + 5;
                break;
            case '6':
                current = current * 10 + 6;
                break;
            case '7':
                current = current * 10 + 7;
                break;
            case '8':
                current = current * 10 + 8;
                break;
            case '9':
                current = current * 10 + 9;
                break;
            default:
                break;
        }
    }
    if (lastExpression == '+') {
        totalCount += current;
    } else {
        totalCount -= current;
    }

    return totalCount;
}

void Solver::print() {
    for (const auto &e: result) {
        for (const auto &c: e) {
            if (c == '+') {
                std::cout << " + ";
            } else if (c == '-') {
                std::cout << " - ";
            } else if (c == ' ') {
            } else {
                std::cout << c;
            }
        }
        std::cout << std::endl;
    }
}