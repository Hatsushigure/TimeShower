#pragma once
#include "timeshower.h"
#include "messagebox.h"
class Settings
{
private:
    QFile* settingsFile;
	QJsonObject* settingsObj;
    double m_size;
	int m_timerInterval;
    bool m_doAutoAlign;
	int m_shutdownPrerock;
	bool m_newlyInstalled;
	bool m_enableSettingsWidget;
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
	bool enableSettingsWidget() {return m_enableSettingsWidget;}
};
