#include "SDManager.h"


SDManager::SDManager(int sdPin)
{
    _sdPin = sdPin;
    _file = nullptr;
    SD.begin(_sdPin);
}

SDManager::~SDManager()
{
}

bool SDManager::openFile(String filePath)
{
    *_file = SD.open(filePath, FILE_READ);
    if (_file != nullptr) {
        return true;
    }
    return false;
}

void SDManager::closeFile()
{
    _file->close();
}

ArduinoQueue<String>* SDManager::readFile()
{
    ArduinoQueue<String>* fileData = new ArduinoQueue<String>();
    while (_file->available()) {
        _file->read();
        String data = String(_file->read());
        fileData->enqueue(data);
    }
    return fileData;
}
