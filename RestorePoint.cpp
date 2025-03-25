#include "RestorePoint.h"
#include <ctime>

RestorePoint::RestorePoint(const std::vector<std::shared_ptr<BackupObject>>& objs, 
                         const std::string& storage)
    : objects(objs), storagePath(storage) {
    creationTime = std::time(nullptr);
}

std::time_t RestorePoint::getCreationTime() const {
    return creationTime;
}

std::string RestorePoint::getStoragePath() const {
    return storagePath;
}

const std::vector<std::shared_ptr<BackupObject>>& RestorePoint::getObjects() const {
    return objects;
}

size_t RestorePoint::getTotalSize() const {
    size_t total = 0;
    for (const auto& obj : objects) {
        total += obj->getSize();
    }
    return total;
}