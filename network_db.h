#include <QVector>
#include "p0f_info.h"
#include "host.h"
#ifndef NETWORK_DB_H
#define NETWORK_DB_H

class network_db
{
private:
    QVector<host*> network;

public:
    network_db();
    host* find_host(QString addr);
    void add_packet(p0f_info packet);
};

#endif // NETWORK_DB_H

