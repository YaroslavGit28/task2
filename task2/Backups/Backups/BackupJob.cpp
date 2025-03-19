#include "BackupJob.h"
#include <algorithm>
#include <stdexcept>

BackupJob::BackupJob()
    : storage(nullptr), backupAlgorithm(nullptr) {
}

void BackupJob::addBackupObject(const BackupObject& object) {
    backupObjects.push_back(object);
}

void BackupJob::removeBackupObject(const BackupObject& object) {
    auto it = std::remove(backupObjects.begin(), backupObjects.end(), object);
    if (it != backupObjects.end()) {
        backupObjects.erase(it, backupObjects.end());
    }
    else {
        throw std::runtime_error("BackupObject not found.");
    }
}

void BackupJob::createRestorePoint() {
    if (backupAlgorithm && storage) {
        backupAlgorithm->backup(backupObjects, storage);
        restorePoints.emplace_back(backupObjects);
    }
    else {
        throw std::runtime_error("Storage or BackupAlgorithm is not set.");
    }
}

void BackupJob::setStorage(Storage* storage) {
    this->storage = storage;
}

void BackupJob::setBackupAlgorithm(BackupAlgorithm* algorithm) {
    this->backupAlgorithm = algorithm;
}
