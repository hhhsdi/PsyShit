#pragma once
#include "BackupObject.h"
#include "IStorage.h"
#include <vector>
#include <memory>

class IBackupStrategy {
public:
    virtual void CreateBackup(std::vector<std::shared_ptr<BackupObject>> objects, IStorage& storage) = 0;
    virtual ~IBackupStrategy() = default;
};