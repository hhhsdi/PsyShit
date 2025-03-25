#ifndef RESTORE_POINT_H
#define RESTORE_POINT_H

#include <vector>
#include <string>
#include <chrono>
#include <memory>
#include "BackupObject.h"

class RestorePoint {
private:
    std::vector<std::shared_ptr<BackupObject>> objects;
    std::time_t creationTime;
    std::string storagePath;

public:
    RestorePoint(const std::vector<std::shared_ptr<BackupObject>>& objs, const std::string& storage);
    
    std::time_t getCreationTime() const;
    std::string getStoragePath() const;
    const std::vector<std::shared_ptr<BackupObject>>& getObjects() const;
    size_t getTotalSize() const;
};

#endif // RESTORE_POINT_H