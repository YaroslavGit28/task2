#include "zipUtils.h"
#include <iostream>

void ZipUtils::addFilesToZip(const std::string& zipPath, const std::vector<std::string>& filePaths) {
    int error = 0;
    zip_t* zip = zip_open(zipPath.c_str(), ZIP_CREATE | ZIP_TRUNCATE, &error);
    if (!zip) {
        throw std::runtime_error("Failed to create ZIP archive: " + zipPath);
    }

    for (const auto& filePath : filePaths) {
        zip_source_t* source = zip_source_file(zip, filePath.c_str(), 0, 0);
        if (!source) {
            zip_close(zip);
            throw std::runtime_error("Failed to add file to ZIP: " + filePath);
        }

        std::string fileName = filePath.substr(filePath.find_last_of("/\\") + 1);
        if (zip_file_add(zip, fileName.c_str(), source, ZIP_FL_ENC_UTF_8) < 0) {
            zip_source_free(source);
            zip_close(zip);
            throw std::runtime_error("Failed to add file to ZIP: " + filePath);
        }
    }

    zip_close(zip);
    std::cout << "Created ZIP archive: " << zipPath << std::endl;
}