#include <iostream>
#include "calculator.h"
using namespace std;

// TODO: Define default constructor
		
// TODO: Define member functions - 
//       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()


void Calculator::Add(double val) {
    value += val;
}

void Calculator::Subtract(double val) {
    value -= val;
}

void Calculator::Multiply(double val) {
    value = value * val;
}

void Calculator::Divide(double val) {
    value = value / val;
}

void Calculator::Clear() {
    value = 0.0;
}

double Calculator::GetValue() {
    return value;
}