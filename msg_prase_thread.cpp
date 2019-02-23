#include "msg_prase_thread.h"

msg_prase_thread::msg_prase_thread(QObject *parent):
    QThread(parent),
    shouldExit(false),
    io(nullptr),
    disposer(nullptr)
{

}

///
/// \brief msg_prase_thread::setup
/// \param io
/// \param disposer
/// \return
///
bool msg_prase_thread::setup(io_manager *m_io, msg_disposer *m_disposer,QMap<QString,msg_disposer::mavlink_field_t>*m_map)
{
    io = m_io;
    disposer = m_disposer;
    map = m_map;
    return true;
}

///
/// \brief msg_prase_thread::run
///
void msg_prase_thread::run()
{

    char buff[1024];

    QMap<QString,msg_disposer::mavlink_field_t>&msg_file_map = *map;

    //主任务循环
    while (!shouldExit) {

        //阻塞读取硬件端口数据
        uint32_t numRead = io->readBytes(buff,1024);

        //数据流解析
        disposer->handle_stream(msg_file_map,buff,numRead);
    }

}
