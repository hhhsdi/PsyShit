#ifndef BACKUP_OBJECT_H
#define BACKUP_OBJECT_H

#include <string>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

class BackupObject {
private:
    fs::path sourcePath;
    std::string name;

public:
    BackupObject(const std::string& path);
    
    std::string getName() const;
    fs::path getSourcePath() const;
    bool exists() const;
    size_t getSize() const;
};

#endif // BACKUP_OBJECT_H