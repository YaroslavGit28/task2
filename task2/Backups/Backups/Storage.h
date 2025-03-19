#ifndef STORAGE_H
#define STORAGE_H

#include <vector>
#include "BackupObject.h"

class Storage {
public:
    virtual void save(const std::vector<BackupObject>& objects) = 0;
    virtual ~Storage() = default;
};

#endif // STORAGE_H