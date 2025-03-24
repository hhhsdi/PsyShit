#include "CreditAccount.h"
#include <stdexcept>

CreditAccount::CreditAccount(const std::string& accountId, Client* owner, double balance, double creditLimit, double commissionRate)
    : Account(accountId, owner, balance), creditLimit(creditLimit), commissionRate(commissionRate) {
}

void CreditAccount::applyInterest() {
    // No interest for credit accounts
}

void CreditAccount::chargeCommission() {
    if (balance < 0) {
        balance -= commissionRate;
    }
}