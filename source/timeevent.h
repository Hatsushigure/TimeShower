#ifndef TIMEEVENT_H
#define TIMEEVENT_H
#include "timeshower.h"

class TimeEvent : public QObject
{
    Q_OBJECT

private:
    QString m_name;
    int time;
    QList<TimeEventAction> actions;
    QString message;
    bool triggered;
public:
    TimeEvent(QString aName, int aTime, const QList<TimeEventAction>* aActions, QString aMessage);

    //获取事件名称
    QString name() {return m_name;}

    //检测时间
    bool check_time(int curTime);

    //触发事件
    void trigger();

    //是否触发
    bool isTriggered() {return triggered;}

signals:
    //关机
    void signalShutDown();

    //显示
    void signalShow();

    //隐藏
    void signalHide();

    //退出
    void signalExit();

    //重启
    void signalRestart();

    //显示消息
    void signalShowMessage(QString msg);
};

#endif // TIMEEVENT_H
