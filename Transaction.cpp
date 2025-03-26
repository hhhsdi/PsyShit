#include "Transaction.h"
#include <stdexcept>

Transaction::Transaction(const std::string& transactionId, Account* sourceAccount, Account* targetAccount, double amount)
    : transactionId(transactionId), sourceAccount(sourceAccount), targetAccount(targetAccount), amount(amount) {
}

void Transaction::execute() {
    if (isCancelled) {
        throw std::runtime_error("Transaction is already cancelled");
    }
    sourceAccount->transfer(targetAccount, amount);
}

void Transaction::cancel() {
    if (isCancelled) {
        throw std::runtime_error("Transaction is already cancelled");
    }
    targetAccount->transfer(sourceAccount, amount);
    isCancelled = true;
}