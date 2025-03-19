#ifndef BACKUPJOB_H
#define BACKUPJOB_H

#include <vector>
#include "BackupObject.h"
#include "RestorePoint.h"
#include "Storage.h"
#include "BackupAlgorithm.h"

class BackupJob {
private:
    std::vector<BackupObject> backupObjects; //Легкость в работе с коллекциями
    std::vector<RestorePoint> restorePoints;
    Storage* storage;
    BackupAlgorithm* backupAlgorithm;

public:
    BackupJob();
    void addBackupObject(const BackupObject& object);
    void removeBackupObject(const BackupObject& object);
    void createRestorePoint();
    void setStorage(Storage* storage);
    void setBackupAlgorithm(BackupAlgorithm* algorithm);
};

#endif // BACKUPJOB_H