#include "SingleStorage.h"
#include <fstream>
#include <iostream>
#include "ZipUtils.h"

void SingleStorage::save(const std::vector<BackupObject>& objects) {
    std::vector<std::string> filePaths;
    for (const auto& obj : objects) {
        filePaths.push_back(obj.getFilePath());
    }

    ZipUtils::addFilesToZip("backup_archive.zip", filePaths);
    std::cout << "Saved all objects to backup_archive.zip" << std::endl;
}