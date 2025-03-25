#include <iostream>
#include <memory>
#include "BackupJob.h"
#include "BackupObject.h"
#include "SplitStorage.h"
#include "SingleStorage.h"

int main() {
    try {
        // Создаем джобу с алгоритмом раздельного хранения
        auto splitStorage = std::make_unique<SplitStorage>();
        BackupJob job(std::move(splitStorage), "my_backups");
        
        // Добавляем объекты для резервного копирования
        job.addObject(std::make_shared<BackupObject>("file1.txt"));
        job.addObject(std::make_shared<BackupObject>("file2.txt"));
        job.addObject(std::make_shared<BackupObject>("folder1"));
        
        // Создаем точку восстановления
        job.createRestorePoint();
        
        // Меняем алгоритм на общее хранилище
        job.setStorageAlgorithm(std::make_unique<SingleStorage>());
        
        // Создаем еще одну точку восстановления
        job.createRestorePoint();
        
        // Выводим информацию о джобе
        std::cout << "Backup job info:" << std::endl;
        std::cout << "Objects in job: " << job.getObjects().size() << std::endl;
        std::cout << "Restore points: " << job.getRestorePoints().size() << std::endl;
        std::cout << "Total backup size: " << job.getTotalBackupSize() << " bytes" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}