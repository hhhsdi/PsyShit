#pragma once
#include "BackupObject.h"
#include <vector>
#include <memory>
#include <ctime>
#include <iostream>

class RestorePoint {
private:
    std::time_t timestamp;
    std::vector<std::shared_ptr<BackupObject>> objects;
public:
    RestorePoint(const std::vector<std::shared_ptr<BackupObject>>& objs) : objects(objs) {
        timestamp = std::time(nullptr);
    }
    void ShowInfo() const {
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &timestamp);
        std::cout << "Точка восстановления создана: " << buffer;
    }

};
