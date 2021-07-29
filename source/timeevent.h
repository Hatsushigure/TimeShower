#ifndef TIMEEVENT_H
#define TIMEEVENT_H
#include "timeshower.h"

class TimeEvent
{
private:
    QString m_name;
    int time;
    QList<TimeEventAction> m_actions;
    QString message;
    bool m_triggered;
public:
    TimeEvent(QString aName, int aTime, QList<TimeEventAction> aActions, QString aMessage);

    //获取事件名称
    QString name() {return m_name;}
    //获取事件操作
    QList<TimeEventAction> actions() {return m_actions;};
    //获取触发状态
    bool triggered() {return m_triggered;}

    //显示消息（如果有这个操作的话）
    void show_message(QSystemTrayIcon* trayIco);

    //检测时间
    bool check_time(int curTime);

    //设置触发状态
    void trigger();
};

#endif // TIMEEVENT_H
