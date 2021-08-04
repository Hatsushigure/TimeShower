#include "settings.h"
#include "globalvariables.h"

Settings::Settings()
{
    using namespace DefaultSettings;

    //初始化变量
    write_log("正在初始化设置");
    settingsFile = new QFile(SETTINGS_FILE_NAME);
    m_size = DEF_SIZE;
    m_doAutoAlign = DEF_DO_AUTO_ALIGN;
    m_timerInterval = TIMER_INTERVAL;

    read_settings();
    write_log("设置对象已创建");
}

//读取设置
void Settings::read_settings()
{    
    write_log("正在读取设置...");
    if(!settingsFile->exists()) //文件不存在
    {
        write_log("文件不存在，恢复默认设置");

        QMessageBox errMsg(QMessageBox::Icon::Critical, "无法读取设置", "    设置文件不存在！");
        errMsg.exec();

        settingsFile->close();
        write_default_settings();
    }
    else if(settingsFile->open(QFile::ReadOnly | QFile::Text))  //正常打开
    {
        bool oldSettings = false;
        while(!settingsFile->atEnd())
        {
            QString ret = settingsFile->readLine();
            if(!ret.startsWith("#"))    //忽略#注释
            {
                if(ret.startsWith("appVersion"))    //读取应用版本
                {
                    short val = ret.mid(ret.indexOf('=') + 1).toShort();
                    if(val < APP_VERSION)
                    {
                        oldSettings = true;
                    }
                }
                else if(ret.startsWith("size"))    //读取窗口相对大小
                {
                    double val = ret.mid(ret.indexOf('=') + 1).toDouble();
                    m_size = val;
                }
                else if(ret.startsWith("doAutoAlign"))  //读取是否自动对齐
                {
                    bool val = ret.mid(ret.indexOf('=') + 1).toShort();
                    m_doAutoAlign = val;
                }
            }
        }
        settingsFile->close();
        write_log("赋值完毕");

        if(oldSettings)
        {
            write_log("检测到旧版设置文件，将更新格式");
            write_settings();
            write_log("格式更新成功");
        }
    }
    else    //无读取权限(基本不会)
    {
        write_log("无文件读取权限");
        MessageBox errMsg(nullptr, scrSize.width(), "    无文件读取权限，应用无法正常启动！\n\n    请手动处理权限问题后再启动", "无法读取设置");
        errMsg.exec();
        settingsFile->close();
    }
}

//写入默认设置
void Settings::write_default_settings()
{
    using namespace DefaultSettings;

    write_log("正在写入默认设置");

    settingsFile->open(QFile::WriteOnly);
    //注释
    settingsFile->write("#此文件为时间查看器设置文件，请谨慎修改，否则会导致程序出现奇怪的错误！\n#注意：以“#”开头的一整行都为注释，会被忽略。要插入注释，请务必使用”#“！\n");
    //应用版本
    settingsFile->write(std::string("appVersion = ").append(std::to_string(APP_VERSION)).append("\n").c_str());
    //窗口相对大小
    settingsFile->write(std::string("size = ").append(std::to_string(DEF_SIZE)).append("\n").c_str());
    //是否自动对齐
    settingsFile->write(std::string("doAutoAlign = ").append(std::to_string(DEF_DO_AUTO_ALIGN)).append("\n").c_str());

    settingsFile->close();
}

//写入设置
void Settings::write_settings()
{    
    write_log("正在写入设置");

    settingsFile->open(QFile::WriteOnly);
    //注释
    settingsFile->write("#此文件为时间查看器设置文件，请谨慎修改，否则会导致程序出现奇怪的错误！\n#注意：以“#”开头的一整行都为注释，会被忽略。要插入注释，请务必使用”#“！\n");
    //应用版本
    settingsFile->write(std::string("appVersion = ").append(std::to_string(APP_VERSION)).append("\n").c_str());
    //窗口相对大小
    settingsFile->write(std::string("size = ").append(std::to_string(m_size)).c_str());
    //是否自动对齐
    settingsFile->write(std::string("doAutoAlign = ").append(std::to_string(m_doAutoAlign)).c_str());

    settingsFile->close();
}
