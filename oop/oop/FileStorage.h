// File: FileStorage.h
#pragma once
#include "IStorage.h"
#include <iostream>

class FileStorage : public IStorage {
public:
    void SaveBackup(const std::string& backupData) override {
        std::cout << "���������� ��������� �����: " << backupData << std::endl;
    }
};
