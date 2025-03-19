#ifndef BACKUPOBJECT_H
#define BACKUPOBJECT_H

#include <string>
#include <stdexcept>

class BackupObject {
private:
    std::string filePath;

public:
    BackupObject(const std::string& path); // Конструктор
    std::string getFilePath() const; // Метод для получения пути к файлу
    std::string getFileContent() const; 
    bool operator==(const BackupObject& other) const; // Оператор сравнения
};

#endif // BACKUPOBJECT_H
