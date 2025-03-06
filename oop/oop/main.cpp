#include "FileStorage.h"
#include "SplitStorageBackup.h"
#include "SingleStorageBackup.h"
#include "BackupJob.h"
#include <memory>
#include <fstream>

void CreateFile(const std::string& fileName, const std::string& content) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << content;
        file.close();
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    FileStorage storage;
    SplitStorageBackup splitStrategy;
    SingleStorageBackup singleStrategy;

    CreateFile("file1.txt", "1121341");
    CreateFile("file2.txt", "321321");


    BackupJob job(singleStrategy, storage);
    auto file1 = std::make_shared<BackupObject>("file1.txt");
    auto file2 = std::make_shared<BackupObject>("file2.txt");

    job.AddObject(file1);
    job.AddObject(file2);
    job.CreateRestorePoint();

    return 0;
}

