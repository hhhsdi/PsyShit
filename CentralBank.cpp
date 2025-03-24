#include "CentralBank.h"

void CentralBank::registerBank(Bank* bank) {
    banks.push_back(bank);
}

void CentralBank::processGlobalTransactions() {
    for (auto bank : banks) {
        // Process transactions for each bank
    }
}

void CentralBank::notifyBanks(const std::string& message) {
    for (auto bank : banks) {
        // Notify each bank
    }
}