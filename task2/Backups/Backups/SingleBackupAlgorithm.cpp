#include <iostream>
#include "SingleBackupAlgorithm.h"

void SingleBackupAlgorithm::backup(const std::vector<BackupObject>& objects, Storage* storage) {
    std::cout << "Using Single Backup Algorithm." << std::endl;
    storage->save(objects);
}