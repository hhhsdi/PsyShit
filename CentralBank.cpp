#include "CentralBank.h"
#include "Bank.h"
#include "Account.h"
#include <iostream>

// Реализация метода для обработки глобальных транзакций )
void CentralBank::processGlobalTransactions() {
    for (Bank* bank : banks) {
        // 1. Начисляем проценты на все счета
        for (Account* account : bank->getAccounts()) {
            account->applyInterest(); // Полиморфный вызов (для дебетовых, депозитных и т.д.)
        }

        // 2. Списание комиссий 
        for (Account* account : bank->getAccounts()) {
            account->chargeCommission();
        }
    }
    std::cout << "[Central Bank] Processed global transactions (interest/commissions).\n";
}

// Реализация уведомления всех банков (например, о изменении ставок)
void CentralBank::notifyBanks(const std::string& message) {
    for (Bank* bank : banks) {
        bank->update(message); // Вызываем метод update у каждого банка
    }
    std::cout << "[Central Bank] Notified all banks: " << message << "\n";
}

// Регистрация банка в системе
void CentralBank::registerBank(Bank* bank) {
    banks.push_back(bank);
    std::cout << "[Central Bank] Bank registered: " << bank->getName() << "\n";
}
