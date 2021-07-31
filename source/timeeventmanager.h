#ifndef TIMEEVENTMANAGER_H
#define TIMEEVENTMANAGER_H
#include "timeshower.h"
#include "timeevent.h"
#include "settings.h"

class TimeWidget;

class TimeEventManager : public QObject
{
    Q_OBJECT
private:
    Settings* settings;
    QJsonDocument timetable;
    QList<TimeEvent*> events;
public:
    TimeEventManager(Settings* s);

    //初始化事件列表
    void initialize_timetable();

    //关联事件的信号
    void connect_events(TimeWidget* parent);

    //获取下一事件
    TimeEvent* next_event() {return *events.begin();}

    //触发事件
    void trigger();
};

#endif // TIMEEVENTMANAGER_H
