#include "RestorePoint.h"
#include <ctime>

RestorePoint::RestorePoint(const std::vector<BackupObject>& objects)
    : backupObjects(objects), creationTime(std::time(nullptr)) {
}

std::time_t RestorePoint::getCreationTime() const {
    return creationTime;
}

std::vector<BackupObject> RestorePoint::getBackupObjects() const {
    return backupObjects;
}