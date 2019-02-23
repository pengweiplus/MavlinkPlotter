#ifndef MSG_PRASE_THREAD_H
#define MSG_PRASE_THREAD_H

#include <QObject>
#include "io_manager.h"
#include "msg_disposer.h"
class msg_prase_thread : public QThread
{

    Q_OBJECT

protected:
    void run();

public:
    msg_prase_thread(QObject *parent = 0);
    bool setup(io_manager *m_io, msg_disposer *m_disposer,QMap<QString,msg_disposer::mavlink_field_t>*m_map);

private:

    //线程信息
    bool shouldExit;                                //线程退出标志
    io_manager *io;
    msg_disposer *disposer;
    QMap<QString,msg_disposer::mavlink_field_t>*map;
};

#endif // MSG_PRASE_THREAD_H
