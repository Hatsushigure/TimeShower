#pragma once
#include "timeshower.h"
#include "timeevent.h"
#include "globals.h"

class TimeWidget;

class TimeEventManager : public QObject
{
    Q_OBJECT
private:
    QJsonDocument timetable;
	QList<TimeEvent*> events;
	QTimer* eventTimer;
public:
    TimeEventManager();
private:
	//初始化事件列表
	void initialize_timetable();

	//关联事件的信号
	void connect_events();

	//触发事件
	void trigger();
private slots:
	void onTimerTimeout();
signals:
	void eventChanged(QString name);
};
