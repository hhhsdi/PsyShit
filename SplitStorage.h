#ifndef SPLIT_STORAGE_H
#define SPLIT_STORAGE_H

#include "IStorageAlgorithm.h"
#include <filesystem>

namespace fs = std::filesystem;

class SplitStorage : public IStorageAlgorithm {
public:
    std::string createStorage(const std::vector<std::shared_ptr<BackupObject>>& objects, 
                             const std::string& backupDir) override;
};

#endif // SPLIT_STORAGE_H