#pragma once
#include "IBackupStrategy.h"
#include <iostream>

class SplitStorageBackup : public IBackupStrategy {
public:
    void CreateBackup(std::vector<std::shared_ptr<BackupObject>> objects, IStorage& storage) override {
        for (const auto& obj : objects) {
            storage.SaveBackup("Split Backup: " + obj->GetFilePath());
        }
    }
};
