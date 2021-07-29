#include "timeevent.h"

TimeEvent::TimeEvent(QString aName, int aTime, QList<TimeEventAction> aActions, QString aMessage)
{
    m_name = aName;
    time = aTime;
    m_actions = aActions;
    message = aMessage;
    m_triggered = false;
}

//显示消息（如果有这个操作的话）
void TimeEvent::show_message(QSystemTrayIcon *trayIco)
{
    trayIco->showMessage("", message, APP_ICON);
}

//检测时间
bool TimeEvent::check_time(int curTime)
{
    if(time == curTime)
    {
        return true;
    }
    else
        return false;
}

//设置触发状态
void TimeEvent::trigger()
{
    m_triggered = true;
}
