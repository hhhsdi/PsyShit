#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Account.h"

class Transaction {
public:
    Transaction(const std::string& transactionId, Account* sourceAccount, Account* targetAccount, double amount);
    void execute();
    void cancel();

private:
    std::string transactionId;
    Account* sourceAccount;
    Account* targetAccount;
    double amount;
    bool isCancelled = false;
};

#endif // TRANSACTION_H