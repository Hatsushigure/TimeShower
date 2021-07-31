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
    if(check_time(tmNum))
    {
        for(auto i = actions.begin(); i != actions.end(); i++)
        {
            if(*i == TimeEventAction::exit)
            {
                emit signalExit();
            }
            else if(*i == TimeEventAction::hide)
            {
                emit signalHide();
            }
            else if(*i == TimeEventAction::restart)
            {
                emit signalRestart();
            }
            else if(*i == TimeEventAction::show)
            {
                emit signalShow();
            }
            else if(*i == TimeEventAction::showMessage)
            {
                emit signalShowMessage(message);
            }
            else if(*i == TimeEventAction::shutDown)
            {
                emit signalShutDown();
            }
        }
        triggered = true;
    }
}
