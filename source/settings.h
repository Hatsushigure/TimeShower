#pragma once
#include "timeshower.h"
#include "messagebox.h"
class Settings
{
private:
    QFile* settingsFile;
    QFile* logFile;
    short m_size;
    short m_timerInterval;
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
    void write_log(const QString& text, LogType tp = LogType::info);

    short size() {return m_size;}
    short timerInterval() {return m_timerInterval;}
    bool doAutoAlign() {return m_doAutoAlign;}
};
