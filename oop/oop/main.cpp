#include "FileStorage.h"
#include "SplitStorageBackup.h"
#include "SingleStorageBackup.h"
#include "BackupJob.h"
#include <memory>

int main() {
    FileStorage storage;
    SplitStorageBackup splitStrategy;
    SingleStorageBackup singleStrategy;

    BackupJob job(singleStrategy, storage);
    auto file1 = std::make_shared<BackupObject>("file1.txt");
    auto file2 = std::make_shared<BackupObject>("file2.txt");

    job.AddObject(file1);
    job.AddObject(file2);
    job.CreateRestorePoint();

    return 0;
}
