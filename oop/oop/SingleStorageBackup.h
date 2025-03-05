#pragma once
#include "IBackupStrategy.h"
#include <iostream>

class SingleStorageBackup : public IBackupStrategy {
public:
    void CreateBackup(std::vector<std::shared_ptr<BackupObject>> objects, IStorage& storage) override {
        std::string backupData = "Single Backup: ";
        for (const auto& obj : objects) {
            backupData += obj->GetFilePath() + " ";
        }
        storage.SaveBackup(backupData);
    }
};