#ifndef HOST_H
#define HOST_H
#include "p0f_info.h"
#include "QDebug"

class host
{
public:
    host(QString ip);
    QString get_ip();
    QString print_packets();
    QHash<info_type,p0f_info*> get_packets();
    p0f_info* get_packet(info_type type);
    void set_packet(p0f_info* info);
    QString get_os();
    QString get_app();
    bool host_with_nat();

private:
    QString ip_host;
    QHash<info_type,p0f_info*> host_packets;


};

#endif // HOST_H
