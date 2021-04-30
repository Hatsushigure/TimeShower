#pragma once
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QTime>
#include <QDate>

//常量
const QString FILE_NAME = "settings.txt";
const short DEF_SIZE = 1;
const short APP_VERSION = 1;

//枚举
enum class LogType {info, warning, error};

class Settings
{
private:
    QFile* settingsFile;
    QFile* logFile;
    short m_size;
public:
    Settings();

    //读取设置
    bool read_settings();

    //写入默认设置
    void write_default_settings();

    //写日志
    void write_log(const QString text, LogType tp = LogType::info);

    short size() {return m_size;}
};
