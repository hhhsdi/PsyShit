#include "SingleStorage.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace fs = std::filesystem;

std::string SingleStorage::createStorage(const std::vector<std::shared_ptr<BackupObject>>& objects, 
                                       const std::string& backupDir) {
    auto now = std::time(nullptr);
    std::tm tm = *std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y%m%d_%H%M%S");
    std::string timestamp = oss.str();
    
    fs::path restorePointDir = fs::path(backupDir) / ("backup_" + timestamp);
    fs::create_directories(restorePointDir);
    
    fs::path commonDir = restorePointDir / "common";
    fs::create_directories(commonDir);
    
    for (const auto& obj : objects) {
        fs::path destPath = commonDir / obj->getName();
        
        if (fs::is_directory(obj->getSourcePath())) {
            fs::create_directories(destPath);
            for (const auto& entry : fs::recursive_directory_iterator(obj->getSourcePath())) {
                if (entry.is_regular_file()) {
                    fs::path relative = fs::relative(entry.path(), obj->getSourcePath());
                    fs::path destFile = destPath / relative;
                    fs::create_directories(destFile.parent_path());
                    fs::copy_file(entry.path(), destFile);
                }
            }
        } else {
            fs::copy_file(obj->getSourcePath(), destPath);
        }
    }
    
    return restorePointDir.string();
}