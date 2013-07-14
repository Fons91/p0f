#ifndef HOST_H
#define HOST_H
#include "p0f_info.h"
#include "QDebug"

class host
{
public:
    host(QString ip);
    QString get_ip();
    void set_mtu_packet(mtu_info* packet);
    void set_syn_packet(syn_info* packet);
    void set_http_packet(http_info* packet);
    void set_uptime_packet(uptime_info* packet);
    mtu_info* get_mtu_packet();
    syn_info* get_syn_packet();
    uptime_info* get_uptime_packet();
    http_info* get_http_packet();
    void print_packets();


private:
    QString ip_host;
    mtu_info* mtu_packet=0;
    syn_info* syn_packet=0;
    http_info* http_packet=0;
    uptime_info* uptime_packet=0;
};

#endif // HOST_H
