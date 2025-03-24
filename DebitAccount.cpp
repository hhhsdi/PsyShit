#include "DebitAccount.h"

DebitAccount::DebitAccount(const std::string& accountId, Client* owner, double balance, double interestRate)
    : Account(accountId, owner, balance), interestRate(interestRate) {
}

void DebitAccount::applyInterest() {
    balance += balance * interestRate;
}

void DebitAccount::chargeCommission() {
    // No commission for debit accounts
}