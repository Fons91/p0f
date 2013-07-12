#ifndef HOST_H
#define HOST_H
#include "p0f_info.h"

class host
{
public:
    host(QString ip);
    QString get_ip();
    void set_mtu_packet(mtu_packet* packet);
    void set_syn_packet(syn_packet* packet);
    void set_http_packet(http_packet* packet);
    void set_uptime_packet(uptime_packet* packet);
    mtu_info* get_mtu_packet();
    syn_info* get_syn_packet();
    http_info* get_http_packet();
    uptime_info* get_uptime_packet();
private:
    QString ip_host;
    mtu_info* mtu_packet;
    syn_info* syn_packet;
    http_info* http_packet;
    uptime_info* uptime_packet;
};

#endif // HOST_H
