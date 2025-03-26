#include "Client.h"

Client::Client(const std::string& firstName, const std::string& lastName)
    : firstName(firstName), lastName(lastName) {
}

std::string Client::getFullName() const {
    return firstName + " " + lastName;
}