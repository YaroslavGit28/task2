#ifndef SPLITBACKUPALGORITHM_H
#define SPLITBACKUPALGORITHM_H

#include "BackupAlgorithm.h"

class SplitBackupAlgorithm : public BackupAlgorithm {
public:
    void backup(const std::vector<BackupObject>& objects, Storage* storage) override;
};

#endif // SPLITBACKUPALGORITHM_H
