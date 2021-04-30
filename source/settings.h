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
const bool DEF_DO_AUTO_ALIGN = true;
const short APP_VERSION = 2;

//枚举
enum class LogType {info, warning, error};

class Settings
{
private:
    QFile* settingsFile;
    QFile* logFile;
    short m_size;
    bool m_doAutoAlign;
public:
    Settings();

    //读取设置
    void read_settings();

    //写入默认设置
    void write_default_settings();

    //写入设置
    void write_settings();

    //写日志
    void write_log(const QString text, LogType tp = LogType::info);

    //获取值
    QString get_val(QString key);

    short size() {return m_size;}
    bool doAutoAlign() {return m_doAutoAlign;}
};
