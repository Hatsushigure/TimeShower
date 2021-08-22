#include "settings.h"
#include "globals.h"

Settings::Settings()
{
    using namespace DefaultSettings;

    //初始化变量
    write_log("正在初始化设置");
    settingsFile = new QFile(SETTINGS_FILE_NAME);
    m_size = DEF_SIZE;
    m_doAutoAlign = DEF_DO_AUTO_ALIGN;
	m_timerInterval = DEF_TIMER_INTERVAL;
	m_shutdownPrerock = DEF_SHUTDOWN_PREROCK;

    read_settings();
    write_log("设置对象已创建");
}

//读取设置
void Settings::read_settings()
{    
	//write_log("正在读取设置...");
    if(!settingsFile->exists()) //文件不存在
    {
		write_log("检测到首次使用");
		m_newlyInstalled = true;

        settingsFile->close();
        write_default_settings();
    }
	else if(settingsFile->open(QFile::ReadOnly))  //正常打开
    {
		m_newlyInstalled = false;
        bool oldSettings = false;

		settingsObj = new QJsonObject(QJsonDocument::fromJson(settingsFile->readAll()).object());
		settingsFile->close();

		if (settingsObj->find("size") != settingsObj->end()) {	//窗口大小
			m_size = settingsObj->value("size").toDouble();
		}
		if (settingsObj->find("shutdownPrerock") != settingsObj->end()) {	//关机前摇
			m_shutdownPrerock = settingsObj->value("shutdownProrock").toInt();
		}
		if (settingsObj->find("doAutoAlign") != settingsObj->end()) {	//是否自动对齐
			m_doAutoAlign = settingsObj->value("doAutoAlign").toBool();
		}
		if (settingsObj->find("timerInterval") != settingsObj->end()) {
			m_timerInterval = settingsObj->value("timerInterval").toInt();
		}

		//write_log("赋值完毕");

		if (settingsObj->value("settingsVersion").toInt() < SETTINGS_VERSION) {	//检测设置版本
			oldSettings = true;
		}
		if(oldSettings) {
            write_log("检测到旧版设置文件，将更新格式");
            write_settings();
            write_log("格式更新成功");
        }

		delete settingsObj;
		settingsObj = nullptr;
    }
}

//写入默认设置
void Settings::write_default_settings()
{
    using namespace DefaultSettings;

	write_log("正在载入设置");
	settingsObj = new QJsonObject;
	settingsObj->insert("settingsVersion", SETTINGS_VERSION);	//应用版本
	settingsObj->insert("size", DEF_SIZE);	//窗口相对大小
	settingsObj->insert("doAutoAlign", DEF_DO_AUTO_ALIGN);	//是否自动对齐
	settingsObj->insert("shutdownPrerock", DEF_SHUTDOWN_PREROCK);	//关机前摇
	settingsObj->insert("timerInterval", DEF_TIMER_INTERVAL);	//时钟更新间隔
	write_log("设置载入成功，即将写入");

	QJsonDocument doc(*settingsObj);
	delete settingsObj;
	settingsObj = nullptr;
	settingsFile->open(QFile::WriteOnly);
	settingsFile->write(doc.toJson());
    settingsFile->close();
	write_log("设置写入完成");
}

//写入设置
void Settings::write_settings()
{    
	write_log("正在载入设置");
	settingsObj = new QJsonObject;
	settingsObj->insert("settingsVersion", SETTINGS_VERSION);	//应用版本
	settingsObj->insert("size", m_size);	//窗口相对大小
	settingsObj->insert("doAutoAlign", m_doAutoAlign);	//是否自动对齐
	settingsObj->insert("shutdownPrerock", m_shutdownPrerock);	//关机前摇
	settingsObj->insert("timerInterval", m_timerInterval);	//时钟更新间隔
	write_log("设置载入成功，即将写入");

	QJsonDocument doc(*settingsObj);
	delete settingsObj;
	settingsObj = nullptr;
	settingsFile->open(QFile::WriteOnly);
	settingsFile->write(doc.toJson());
	settingsFile->close();
	write_log("设置写入完成");
}
