#include "timeevent.h"

TimeEvent::TimeEvent(QString aName, int aTime, const QList<TimeEventAction>* aActions, QString aMessage)
{
    m_name = aName;
    time = aTime;
    message = aMessage;

    for(auto i = aActions->begin(); i != aActions->end(); i++)
    {
        actions.push_back(*i);
    }

    triggered = false;
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

//触发事件
void TimeEvent::trigger()
{
    QTime tm = QTime::currentTime();
    int tmNum = tm.hour() * 3600 + tm.minute() * 60 + tm.second();
	if (time > tmNum) {
		return;
	}
	else if (time < tmNum) {
		triggered = true;
		return;
	}
	else if (check_time(tmNum)) {
		triggered = true;
		for(auto i = actions.begin(); i != actions.end(); i++)
		{
			switch (*i)
			{
			case TimeEventAction::exit:
				emit signalExit();
				break;
			case TimeEventAction::hide:
				emit signalHide();
				break;
			case TimeEventAction::restart:
				emit signalRestart();
				break;
			case TimeEventAction::show:
				emit signalShow();
				break;
			case TimeEventAction::showMessage:
				emit signalShowMessage(message);
				break;
			case TimeEventAction::shutDown:
				emit signalShutDown();
				break;
			default:
				break;
			}
		}
	}
}
