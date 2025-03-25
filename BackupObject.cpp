#include "BackupObject.h"
#include <filesystem>

namespace fs = std::filesystem;

BackupObject::BackupObject(const std::string& path) : sourcePath(path) {
    if (!fs::exists(sourcePath)) {
        throw std::runtime_error("Source path does not exist: " + path);
    }
    name = sourcePath.filename().string();
}

std::string BackupObject::getName() const {
    return name;
}

fs::path BackupObject::getSourcePath() const {
    return sourcePath;
}

bool BackupObject::exists() const {
    return fs::exists(sourcePath);
}

size_t BackupObject::getSize() const {
    if (fs::is_directory(sourcePath)) {
        size_t size = 0;
        for (const auto& entry : fs::recursive_directory_iterator(sourcePath)) {
            if (entry.is_regular_file()) {
                size += entry.file_size();
            }
        }
        return size;
    }
    return fs::file_size(sourcePath);
}