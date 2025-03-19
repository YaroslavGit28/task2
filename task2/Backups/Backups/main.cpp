#include <iostream>
#include "BackupObject.h"
#include "BackupJob.h"
#include "SplitStorage.h"
#include "SingleStorage.h"
#include "SplitBackupAlgorithm.h"
#include "SingleBackupAlgorithm.h"

int main() {
    try {
        // Создаем тестовые объекты (указываем реальные пути к файлам)
        BackupObject file1("C:/Users/studentColl/Desktop/file1.txt");
        BackupObject file2("C:/Users/studentColl/Desktop/file2.txt");
        BackupObject file3("C:/Users/studentColl/Desktop/file3.txt");

        // Создаем джобу и добавляем объекты
        BackupJob backupJob;
        backupJob.addBackupObject(file1);
        backupJob.addBackupObject(file2);
        backupJob.addBackupObject(file3);

        // Настраиваем раздельное хранение
        SplitStorage splitStorage;
        SplitBackupAlgorithm splitAlgorithm;

        backupJob.setStorage(&splitStorage);
        backupJob.setBackupAlgorithm(&splitAlgorithm);

        // Создаем точку восстановления
        std::cout << "Creating restore point with split storage..." << std::endl;
        backupJob.createRestorePoint();

        // Настраиваем общее хранилище
        SingleStorage singleStorage;
        SingleBackupAlgorithm singleAlgorithm;

        backupJob.setStorage(&singleStorage);
        backupJob.setBackupAlgorithm(&singleAlgorithm);

        // Создаем еще одну точку восстановления
        std::cout << "\nCreating restore point with single storage..." << std::endl;
        backupJob.createRestorePoint();

        // Проверка обработки исключений
        BackupJob faultyJob;
        faultyJob.addBackupObject(file1);

        std::cout << "\nTesting error handling..." << std::endl;
        faultyJob.createRestorePoint(); // Должно выбросить исключение

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}