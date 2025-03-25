#ifndef ISTORAGE_ALGORITHM_H
#define ISTORAGE_ALGORITHM_H

#include <vector>
#include <memory>
#include "BackupObject.h"
#include <string>

class IStorageAlgorithm {
public:
    virtual ~IStorageAlgorithm() = default;
    virtual std::string createStorage(const std::vector<std::shared_ptr<BackupObject>>& objects, 
                                     const std::string& backupDir) = 0;
};

#endif // ISTORAGE_ALGORITHM_H