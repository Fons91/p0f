#include <QVector>
#include "p0f_info.h"
#include "host.h"
#ifndef NETWORK_DB_H
#define NETWORK_DB_H

class network_db
{
private:
    void add_packet_host(p0f_info *packet,p0f_info_factory::info_type info_type,host* new_host);
    QVector<host*> network;

public:
    network_db();
    host* find_host(QString addr);
    void add_packet(p0f_info packet);
    void  show_network();
    void   add_info_network(p0f_info *packet,p0f_info_factory::info_type type);



};

#endif // NETWORK_DB_H

