#ifndef DEBITACCOUNT_H
#define DEBITACCOUNT_H

#include "Account.h"

class DebitAccount : public Account {
public:
    DebitAccount(const std::string& accountId, Client* owner, double balance, double interestRate);
    void applyInterest() override;
    void chargeCommission() override;

private:
    double interestRate;
};

#endif // DEBITACCOUNT_H