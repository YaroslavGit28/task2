#include "BackupObject.h"

// Определение конструктора
BackupObject::BackupObject(const std::string& path) : filePath(path) {
    if (path.empty()) {
        throw std::invalid_argument("File path cannot be empty.");
    }
}

// Метод для получения пути к файлу
std::string BackupObject::getFilePath() const {
    return filePath;
}

std::string BackupObject::getFileContent() const {
    // Симуляция содержимого файла
    return "Simulated content of " + filePath;
}

// Определение оператора сравнения
bool BackupObject::operator==(const BackupObject& other) const {
    return this->filePath == other.filePath; // Сравниваем по полю filePath
}
