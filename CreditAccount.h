
#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "Account.h"

class CreditAccount : public Account {
public:
    CreditAccount(const std::string& accountId, Client* owner, double balance, double creditLimit, double commissionRate);
    void applyInterest() override;
    void chargeCommission() override;

private:
    double creditLimit;
    double commissionRate;
};

#endif // CREDITACCOUNT_H