#include <QVector>
#include "p0f_info.h"
#include "host.h"
#ifndef NETWORK_DB_H
#define NETWORK_DB_H

class network_db
{
private:
    network_db();

     void add_packet_host(p0f_info *packet,p0f_info_factory::info_type info_type,host* new_host);
     host*  find_host(QString addr);
     QVector<host*> network;

public:
     static network_db& get_istance(){
         static network_db istance;
         return istance;
     }

     void  show_network();
     void   add_info_network(p0f_info *packet,p0f_info_factory::info_type type);



};

#endif // NETWORK_DB_H
