#include "calculator.h"
#include <stdexcept>
#include <climits>

int Calculator::add(int a, int b) {
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        throw std::overflow_error("Overflow in add");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
        throw std::overflow_error("Overflow in sub");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0 && b > 0 && a > INT_MAX / b) {
        throw std::overflow_error("Overflow in mul");
    }
    if (a > 0 && b < 0 && b < INT_MIN / a) {
        throw std::overflow_error("Underflow in mul");
    }
    if (a < 0 && b > 0 && a < INT_MIN / b) {
        throw std::overflow_error("Underflow in mul");
    }
    if (a < 0 && b < 0 && a < INT_MAX / b) {
        throw std::overflow_error("Overflow in mul");
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == INT_MIN && b == -1) {
        throw std::overflow_error("Overflow in div");
    }
    return a / b;
}