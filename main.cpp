#include "Bank.h"
#include "CentralBank.h"
#include "ConsoleInterface.h"

int main() {
    Bank bank("MyBank");
    CentralBank centralBank;
    centralBank.registerBank(&bank);

    ConsoleInterface console(&bank, &centralBank);
    console.start();

    return 0;
}