#ifndef RESTOREPOINT_H
#define RESTOREPOINT_H

#include <vector>
#include <ctime>
#include "BackupObject.h"

class RestorePoint {
private:
    std::vector<BackupObject> backupObjects;
    std::time_t creationTime;

public:
    RestorePoint(const std::vector<BackupObject>& objects);
    std::time_t getCreationTime() const;
    std::vector<BackupObject> getBackupObjects() const;
};

#endif // RESTOREPOINT_H