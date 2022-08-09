#include <iostream>
#include "BankAccount.h"
using namespace std;

// TODO: Define public member functions

void BankAccount::SetName(string newName) {
    name = newName;
}

string BankAccount::GetName() {
    return name;
}

void BankAccount::SetChecking(double amt) {
    checkBal = amt;
}
double BankAccount::GetChecking() {
    return checkBal;
}

void BankAccount::SetSavings(double amt) {
    saveBal = amt;
}

double BankAccount::GetSavings() {
    return saveBal;
}

void BankAccount::DepositChecking(double amt) {
    if (amt > 0) {
        checkBal += amt;
    }
}

void BankAccount::DepositSavings(double amt) {
    if (amt > 0) { saveBal += amt; }
}

void BankAccount::WithdrawChecking(double amt) {
    if (amt > 0) { checkBal -= amt; }
}

void BankAccount::WithdrawSavings(double amt) {
    if (amt > 0) { saveBal -= amt; }
}

void BankAccount::TransferToSavings(double amt) {
    if (amt > 0) { 
        checkBal -= amt;
        saveBal += (amt); 
        }
}