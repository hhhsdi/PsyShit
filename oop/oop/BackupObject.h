
#pragma once
#include <string>

class BackupObject {
private:
    std::string filePath;
public:
    BackupObject(const std::string& path) : filePath(path) {}
    std::string GetFilePath() const { return filePath; }
};
