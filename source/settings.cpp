#include "settings.h"

Settings::Settings()
{
    //初始化变量
    settingsFile = new QFile(FILE_NAME);
    logFile = new QFile(QDate::currentDate().toString("yyyy-MM-dd").append('-').append(QTime::currentTime().toString("HH-mm-ss")).append(".log"));
    write_log("成功创建日志文件");
    m_size = DEF_SIZE;

    write_log("正在读取设置");
    read_settings();
}

//读取设置
bool Settings::read_settings()
{
    if(!settingsFile->exists()) //文件不存在
    {
        write_log("文件不存在，恢复默认设置", LogType::warning);
        QMessageBox errMsg(QMessageBox::Critical, "无法读取设置", "设置文件不存在！", QMessageBox::StandardButton::Ok);
        errMsg.exec();
        settingsFile->close();
        write_default_settings();
        return false;
    }
    else if(settingsFile->open(QFile::ReadOnly | QFile::Text))  //正常打开
    {
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
                        write_log("检测到旧版设置文件，将更新格式", LogType::warning);
                    }
                }
                else if(ret.startsWith("size"))    //读取窗口相对大小
                {
                    short val = ret.mid(ret.indexOf('=') + 1).toShort();
                    m_size = val;
                }
            }
        }
        settingsFile->close();
        write_log("赋值完毕");
        return true;
    }
    else    //无读取权限(基本不会)
    {
        QMessageBox errMsg(QMessageBox::Critical, "无法读取设置", "无法打开文件，请检查是否具有读取权限！", QMessageBox::StandardButton::Ok);
        errMsg.exec();
        settingsFile->close();
        return false;
    }
}

//写入默认设置
void Settings::write_default_settings()
{
    write_log("正在写入默认设置", LogType::warning);
    //移除原文件
    if(settingsFile->exists())
    {
        settingsFile->remove();
    }
    settingsFile->open(QFile::ReadWrite | QFile::Append);
    //注释
    settingsFile->write("#此文件为时间查看器设置文件，请谨慎修改，否则会导致程序出现奇怪的错误！\n#注意：以“#”开头的一整行都为注释，会被忽略。要插入注释，请务必使用”#“！\n");
    //应用版本
    settingsFile->write(std::string("appVersion = ").append(std::to_string(APP_VERSION)).append("\n").c_str());
    //窗口相对大小
    settingsFile->write(std::string("size = ").append(std::to_string(DEF_SIZE)).c_str());
    settingsFile->close();
}

//写日志
void Settings::write_log(const QString text, LogType tp)
{
    QString tmp = "[";
    tmp.append(QTime::currentTime().toString());
    switch(tp)
    {
    case LogType::info:
        tmp.append(", 信息] ").append(text).append('\n');
        break;
    case LogType::warning:
        tmp.append(", 警告] ").append(text).append('\n');
        break;
    case LogType::error:
        tmp.append(", 错误] ").append(text).append('\n');
        break;
    default:
        break;
    }
    logFile->open(QFile::ReadWrite | QFile::Append);
    logFile->write(tmp.toUtf8());
    logFile->close();
}
