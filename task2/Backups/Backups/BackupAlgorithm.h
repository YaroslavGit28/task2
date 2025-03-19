#ifndef BACKUPALGORITHM_H
#define BACKUPALGORITHM_H

#include <vector>
#include "BackupObject.h"
#include "Storage.h"

class BackupAlgorithm {
public:
    virtual void backup(const std::vector<BackupObject>& objects, Storage* storage) = 0;
    virtual ~BackupAlgorithm() = default;
};

#endif // BACKUPALGORITHM_H#pragma once
