#ifndef SINGLEBACKUPALGORITHM_H
#define SINGLEBACKUPALGORITHM_H

#include "BackupAlgorithm.h"

class SingleBackupAlgorithm : public BackupAlgorithm {
public:
    void backup(const std::vector<BackupObject>& objects, Storage* storage) override;
};

#endif // SINGLEBACKUPALGORITHM_H