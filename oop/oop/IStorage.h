
#pragma once
#include <string>

class IStorage {
public:
    virtual void SaveBackup(const std::string& backupData) = 0;
    virtual ~IStorage() = default;
};

