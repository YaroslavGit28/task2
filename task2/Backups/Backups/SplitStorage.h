#ifndef SPLITSTORAGE_H
#define SPLITSTORAGE_H

#include "Storage.h"

class SplitStorage : public Storage {
public:
    void save(const std::vector<BackupObject>& objects) override;
    std::string getCurrentTimeString();
};

#endif // SPLITSTORAGE_H