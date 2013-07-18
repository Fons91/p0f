#include <QVector>
#include "p0f_info.h"
#include "host.h"
#ifndef NETWORK_DB_H
#define NETWORK_DB_H

class network_db
{
private:
    network_db();

     void add_packet_host(p0f_info *packet,host* new_host);
     host*  find_host(QString addr);
     QVector<host*> network;
     static network_db* istance;

public:
     static network_db* get_istance();

     void  show_network();
     void   add_info_network(p0f_info *packet);
     QVector<host*> get_hosts(){
         return network;
     }



};

#endif // NETWORK_DB_H

