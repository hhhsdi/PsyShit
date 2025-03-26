#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <stdexcept>
#include "Client.h" 
class Client;

class Account {
public:
    Account(const std::string& accountId, Client* owner, double balance);
    virtual ~Account() = default;

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void transfer(Account* target, double amount);
    virtual void applyInterest() = 0;
    virtual void chargeCommission() = 0;

    std::string getAccountId() const; // Новый метод
    double getBalance() const; // Новый метод

protected:
    std::string accountId;
    double balance;
    Client* owner;
};

#endif // ACCOUNT_H