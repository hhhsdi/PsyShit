#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    Client(const std::string& firstName, const std::string& lastName);
    std::string getFullName() const;

private:
    std::string firstName;
    std::string lastName;
    std::string passportData;
    std::string address;
};

#endif 