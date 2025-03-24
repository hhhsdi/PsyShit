#ifndef BANK_H
#define BANK_H

#include <vector>
#include <string>
#include "Account.h"

class Client;

class Bank {
public:
    Bank(const std::string& name);
    void addClient(Client* client);
    void createAccount(Client* client, const std::string& accountId, double initialBalance);
    const std::vector<Account*>& getAccounts() const; // Новый метод

private:
    std::string name;
    std::vector<Client*> clients;
    std::vector<Account*> accounts;
};

#endif // BANK_H