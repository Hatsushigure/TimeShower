#include "timeevent.h"

TimeEvent::TimeEvent(QString aName, int aTime, QList<TimeEventAction> aActions, QString aMessage, QObject* parent) :QObject(parent)
{
    m_name = aName;
    time = aTime;
    actions = aActions;
    message = aMessage;
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
