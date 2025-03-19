#include <iostream>
#include "SplitBackupAlgorithm.h"

void SplitBackupAlgorithm::backup(const std::vector<BackupObject>& objects, Storage* storage) {
    std::cout << "Using Split Backup Algorithm." << std::endl;
    storage->save(objects);
}