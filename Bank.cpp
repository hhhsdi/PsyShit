#include "Bank.h"
#include "DebitAccount.h"

Bank::Bank(const std::string& name) : name(name) {}

void Bank::addClient(Client* client) {
    clients.push_back(client);
}

void Bank::createAccount(Client* client, const std::string& accountId, double initialBalance) {
    accounts.push_back(new DebitAccount(accountId, client, initialBalance, 0.01));
}

const std::vector<Account*>& Bank::getAccounts() const {
    return accounts;
}