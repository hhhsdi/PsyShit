#ifndef CENTRALBANK_H
#define CENTRALBANK_H

#include <vector>
#include <string>
#include "Bank.h"

class CentralBank {
public:
    void registerBank(Bank* bank);
    void processGlobalTransactions();
    void notifyBanks(const std::string& message);

private:
    std::vector<Bank*> banks;
};

#endif // CENTRALBANK_H