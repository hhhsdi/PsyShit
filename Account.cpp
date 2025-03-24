#include "Account.h"
#include "Client.h"
Account::Account(const std::string& accountId, Client* owner, double balance)
    : accountId(accountId), owner(owner), balance(balance) {
}

void Account::deposit(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Deposit amount cannot be negative");
    }
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount < 0) {
        throw std::invalid_argument("Withdrawal amount cannot be negative");
    }
    if (balance < amount) {
        throw std::runtime_error("Insufficient funds");
    }
    balance -= amount;
}

void Account::transfer(Account* target, double amount) {
    withdraw(amount);
    target->deposit(amount);
}

std::string Account::getAccountId() const {
    return accountId;
}

double Account::getBalance() const {
    return balance;
}