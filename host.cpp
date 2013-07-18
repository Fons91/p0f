#include "host.h"

host::host(QString ip){
    ip_host = ip;

}

QString host::get_ip(){
    return ip_host;
}

QHash<info_type,p0f_info*> host::get_packets(){
    return host_packets;
}

p0f_info* host::get_packet(info_type type){
    return host_packets.value(type);
}

void host::set_packet(p0f_info* info){
    host_packets.insert(info->get_type(),info);
}


QString host::print_packets(){
    QString info;
    foreach(p0f_info* packet, host_packets){
        info.append(packet->get_info());
        qDebug()<<    packet->get_info();
    }

    return info;

}

