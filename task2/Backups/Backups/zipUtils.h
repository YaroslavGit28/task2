#ifndef ZIPUTILS_H
#define ZIPUTILS_H


#include <zip.h>
#include <string>
#include <vector>
#include <stdexcept>

class ZipUtils {
public:
    static void addFilesToZip(const std::string& zipPath, const std::vector<std::string>& filePaths);
};

#endif // ZIPUTILS_H