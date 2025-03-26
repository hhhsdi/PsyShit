#include "ConsoleInterface.h"
#include "Transaction.h"
#include "Client.h"
#include <iostream>
#include <limits>

ConsoleInterface::ConsoleInterface(Bank* bank, CentralBank* centralBank)
    : bank(bank), centralBank(centralBank) {
}

void ConsoleInterface::start() {
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            createClient();
            break;
        case 2:
            createAccount();
            break;
        case 3:
            performTransaction();
            break;
        case 4:
            cancelTransaction();
            break;
        case 5:
            viewAccounts(); // Новая опция
            break;
        case 6:
            return;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }
}

void ConsoleInterface::displayMenu() {
    std::cout << "1. Create Client\n"
        << "2. Create Account\n"
        << "3. Perform Transaction\n"
        << "4. Cancel Transaction\n"
        << "5. View Accounts\n" // Новая опция
        << "6. Exit\n"
        << "Enter your choice: ";
}

void ConsoleInterface::createClient() {
    std::string firstName, lastName;
    std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);

    Client* client = new Client(firstName, lastName);
    bank->addClient(client);
    std::cout << "Client created successfully.\n";
}

void ConsoleInterface::createAccount() {
    std::string clientName, accountId;
    double initialBalance;
    std::cout << "Enter client's full name: ";
    std::getline(std::cin, clientName);
    std::cout << "Enter account ID: ";
    std::getline(std::cin, accountId);
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    // Simplified: Assume the client exists
    bank->createAccount(nullptr, accountId, initialBalance); // Replace nullptr with actual client lookup
    std::cout << "Account created successfully.\n";
}

void ConsoleInterface::performTransaction() {
    std::string sourceAccountId, targetAccountId;
    double amount;
    std::cout << "Enter source account ID: ";
    std::getline(std::cin, sourceAccountId);
    std::cout << "Enter target account ID: ";
    std::getline(std::cin, targetAccountId);
    std::cout << "Enter amount: ";
    std::cin >> amount;

    // Simplified: Assume accounts exist
    Account* sourceAccount = nullptr; // Replace with actual account lookup
    Account* targetAccount = nullptr; // Replace with actual account lookup

    Transaction transaction("TXN001", sourceAccount, targetAccount, amount);
    transaction.execute();
    std::cout << "Transaction executed successfully.\n";
}

void ConsoleInterface::cancelTransaction() {
    std::string transactionId;
    std::cout << "Enter transaction ID: ";
    std::getline(std::cin, transactionId);

    // Simplified: Assume transaction exists
    Transaction transaction(transactionId, nullptr, nullptr, 0); // Replace with actual transaction lookup
    transaction.cancel();
    std::cout << "Transaction cancelled successfully.\n";
}

void ConsoleInterface::viewAccounts() {
    const std::vector<Account*>& accounts = bank->getAccounts();
    if (accounts.empty()) {
        std::cout << "No accounts found.\n";
        return;
    }

    std::cout << "Accounts:\n";
    for (const auto& account : accounts) {
        std::cout << "Account ID: " << account->getAccountId() << ", Balance: " << account->getBalance() << "\n";
    }
}