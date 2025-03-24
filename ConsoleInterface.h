#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include "Bank.h"
#include "CentralBank.h"

class ConsoleInterface {
public:
    ConsoleInterface(Bank* bank, CentralBank* centralBank);
    void start();

private:
    Bank* bank;
    CentralBank* centralBank;

    void displayMenu();
    void createClient();
    void createAccount();
    void performTransaction();
    void cancelTransaction();
    void viewAccounts(); // Новый метод
};

#endif // CONSOLEINTERFACE_H