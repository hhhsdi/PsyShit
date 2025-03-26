#include "DepositAccount.h"
#include <ctime>
#include <stdexcept>

DepositAccount::DepositAccount(const std::string& accountId, Client* owner, double balance, double interestRate, time_t endDate)
    : Account(accountId, owner, balance), interestRate(interestRate), endDate(endDate) {
}

void DepositAccount::applyInterest() {
    if (!isDepositExpired()) {
        balance += balance * interestRate;
    }
}

void DepositAccount::chargeCommission() {
    // No commission for deposit accounts
}

bool DepositAccount::isDepositExpired() const {
    return std::time(nullptr) >= endDate;
}