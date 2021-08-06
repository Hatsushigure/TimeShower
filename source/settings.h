#pragma once
#include "timeshower.h"
#include "messagebox.h"
class Settings
{
private:
    QFile* settingsFile;
    QFile* logFile;
    double m_size;
    short m_timerInterval;
    bool m_doAutoAlign;
	short m_shutdownPrerock;
public:
    Settings();

    //读取设置
    void read_settings();

    //写入默认设置
    void write_default_settings();

    //写入设置
    void write_settings();

    double size() {return m_size;}
    short timerInterval() {return m_timerInterval;}
    bool doAutoAlign() {return m_doAutoAlign;}
	short shutdownPrerock() {return m_shutdownPrerock;}
};
