#ifndef SINGLESTORAGE_H
#define SINGLESTORAGE_H

#include "Storage.h"

class SingleStorage : public Storage {
public:
    void save(const std::vector<BackupObject>& objects) override;
};

#endif // SINGLESTORAGE_H