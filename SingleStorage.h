#ifndef SINGLE_STORAGE_H
#define SINGLE_STORAGE_H

#include "IStorageAlgorithm.h"
#include <filesystem>

namespace fs = std::filesystem;

class SingleStorage : public IStorageAlgorithm {
public:
    std::string createStorage(const std::vector<std::shared_ptr<BackupObject>>& objects, 
                             const std::string& backupDir) override;
};

#endif // SINGLE_STORAGE_H