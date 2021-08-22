#include "timeeventmanager.h"
#include "timewidget.h"

TimeEventManager::TimeEventManager()
{
    QFile tmp(TIMETABLE_FILE_NAME);
    tmp.open(QFile::ReadOnly);
    timetable = QJsonDocument::fromJson(tmp.readAll());
    tmp.close();
    initialize_timetable();

    write_log("时间表初始化完成");
}

//初始化事件列表
void TimeEventManager::initialize_timetable()
{
    QJsonArray arr = timetable.array();
    for(auto i = arr.begin(); i != arr.end(); i++)
    {
        QJsonObject obj = i->toObject();
        QString name = obj.value("name").toString();
        qDebug() << name;
        int time = obj.value("time").toInt();
        qDebug() << time;
        QJsonArray arr1 = obj.value("actions").toArray();
        QList<TimeEventAction> actions;
        for(auto j = arr1.begin(); j != arr1.end(); j ++)
        {
            TimeEventAction act = static_cast<TimeEventAction>(j->toInt());
            qDebug() << int(act);
            actions.push_back(act);
        }
        QString msg = obj.value("message").toString();
        TimeEvent* tmp = new TimeEvent(name, time, &actions, msg);
        events.push_back(tmp);
    }
}

//关联事件的信号
void TimeEventManager::connect_events()
{
    write_log("正在关联时间表与对应操作");

    for(auto i = events.begin(); i != events.end(); i++)
    {
		connect(*i, &TimeEvent::signalExit, timeWid, &TimeWidget::slotExit);
		connect(*i, &TimeEvent::signalHide, timeWid, &TimeWidget::slotHide);
		connect(*i, &TimeEvent::signalRestart, timeWid, &TimeWidget::slotRestart);
		connect(*i, &TimeEvent::signalShow, timeWid, &TimeWidget::slotShow);
		connect(*i, &TimeEvent::signalShowMessage, timeWid, &TimeWidget::slotShowMessage);
		connect(*i, &TimeEvent::signalShutDown, timeWid, &TimeWidget::slotShutDown);
		connect(this, &TimeEventManager::eventChanged, timeWid, &TimeWidget::slotEventChanged);
    }

    write_log("关联结束");
}

//触发事件
void TimeEventManager::trigger()
{
    if(!events.isEmpty())   //检测时间表是否为空
    {
        (*events.begin())->trigger();
        if((*events.begin())->isTriggered())
        {
			emit eventChanged((*events.begin())->name());
			delete (*events.begin());
            events.pop_front();
        }
    }
}
