#ifndef BACKUP_JOB_H
#define BACKUP_JOB_H

#include <vector>
#include <memory>
#include <string>
#include "BackupObject.h"
#include "RestorePoint.h"
#include "IStorageAlgorithm.h"

class BackupJob {
private:
    std::vector<std::shared_ptr<BackupObject>> objects;
    std::vector<std::shared_ptr<RestorePoint>> restorePoints;
    std::unique_ptr<IStorageAlgorithm> storageAlgorithm;
    std::string backupDir;

public:
    BackupJob(std::unique_ptr<IStorageAlgorithm> algorithm, const std::string& dir);
    
    void addObject(const std::shared_ptr<BackupObject>& obj);
    void removeObject(const std::string& name);
    void createRestorePoint();
    void setStorageAlgorithm(std::unique_ptr<IStorageAlgorithm> algorithm);
    
    const std::vector<std::shared_ptr<BackupObject>>& getObjects() const;
    const std::vector<std::shared_ptr<RestorePoint>>& getRestorePoints() const;
    size_t getTotalBackupSize() const;
};

#endif // BACKUP_JOB_H