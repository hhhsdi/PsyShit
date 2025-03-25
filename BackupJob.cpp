#include "BackupJob.h"
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

BackupJob::BackupJob(std::unique_ptr<IStorageAlgorithm> algorithm, const std::string& dir)
    : storageAlgorithm(std::move(algorithm)), backupDir(dir) {
    if (!fs::exists(backupDir)) {
        fs::create_directories(backupDir);
    }
}

void BackupJob::addObject(const std::shared_ptr<BackupObject>& obj) {
    for (const auto& existingObj : objects) {
        if (existingObj->getName() == obj->getName()) {
            throw std::runtime_error("Object with name " + obj->getName() + " already exists");
        }
    }
    objects.push_back(obj);
}

void BackupJob::removeObject(const std::string& name) {
    auto it = std::remove_if(objects.begin(), objects.end(), 
        [&name](const std::shared_ptr<BackupObject>& obj) {
            return obj->getName() == name;
        });
    
    if (it == objects.end()) {
        throw std::runtime_error("Object with name " + name + " not found");
    }
    
    objects.erase(it, objects.end());
}

void BackupJob::createRestorePoint() {
    if (objects.empty()) {
        throw std::runtime_error("Cannot create restore point: no objects added");
    }
    
    std::string storagePath = storageAlgorithm->createStorage(objects, backupDir);
    restorePoints.push_back(std::make_shared<RestorePoint>(objects, storagePath));
}

void BackupJob::setStorageAlgorithm(std::unique_ptr<IStorageAlgorithm> algorithm) {
    storageAlgorithm = std::move(algorithm);
}

const std::vector<std::shared_ptr<BackupObject>>& BackupJob::getObjects() const {
    return objects;
}

const std::vector<std::shared_ptr<RestorePoint>>& BackupJob::getRestorePoints() const {
    return restorePoints;
}

size_t BackupJob::getTotalBackupSize() const {
    size_t total = 0;
    for (const auto& rp : restorePoints) {
        total += rp->getTotalSize();
    }
    return total;
}