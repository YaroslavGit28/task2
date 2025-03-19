#include "SplitStorage.h"
#include "zipUtils.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>
#include <ctime> // Для работы с временем
#include <sstream> // Для работы со строками

std::string getCurrentTimeString() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    // Форматируем время в строку "YYYYMMDD_HHMMSS"
    std::ostringstream oss;
    oss << std::put_time(localTime, "%Y%m%d_%H%M%S");
    return oss.str();
}

void SplitStorage::save(const std::vector<BackupObject>& objects) {
    for (const auto& object : objects) {
        // Получаем текущую временную метку
        std::string timestamp = getCurrentTimeString();

        // Создаем буфер для хранения полного имени файла
        char zipName[128]; // Увеличиваем размер буфера для полного пути

        // Форматируем имя файла с учетом временной метки
        snprintf(zipName, sizeof(zipName), "backup_object_%s.zip", timestamp.c_str());

        // Убедимся, что строка завершена нулевым символом
        zipName[sizeof(zipName) - 1] = '\0';

        std::vector<std::string> files = { object.getFilePath() };
        ZipUtils::addFilesToZip(zipName, files);

        std::cout << "Saved " << object.getFilePath() << " to " << zipName << std::endl;
    }
}