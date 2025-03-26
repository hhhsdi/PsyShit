#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H

#include "Account.h"
#include <ctime>

class DepositAccount : public Account {
public:
    DepositAccount(const std::string& accountId, Client* owner, double balance, double interestRate, time_t endDate);
    void applyInterest() override;
    void chargeCommission() override;
    bool isDepositExpired() const;

private:
    double interestRate;
    time_t endDate;
};

#endif // DEPOSITACCOUNT_H