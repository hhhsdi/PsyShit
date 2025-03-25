#pragma once
#include "IBackupStrategy.h"
#include "RestorePoint.h"
#include <vector>
#include <memory>
#include <algorithm>

class BackupJob {
private:
    std::vector<std::shared_ptr<BackupObject>> objects;
    std::vector<std::shared_ptr<RestorePoint>> restorePoints;
    IBackupStrategy& strategy;
    IStorage& storage;
public:
    BackupJob(IBackupStrategy& strat, IStorage& stor) : strategy(strat), storage(stor) {}
    void AddObject(const std::shared_ptr<BackupObject>& obj) {
        objects.push_back(obj);
    }
    void RemoveObject(const std::shared_ptr<BackupObject>& obj) {
        objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
    }
    void CreateRestorePoint() {
        strategy.CreateBackup(objects, storage);
        restorePoints.push_back(std::make_shared<RestorePoint>(objects));
    }
};
