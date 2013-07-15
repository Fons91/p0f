#include "host.h"

host::host(QString ip){
    ip_host = ip;
    mtu_packet=0;
    syn_packet=0;
    http_packet=0;
    uptime_packet=0;
}

QString host::get_ip(){
    return ip_host;
}

http_info* host::get_http_packet(){
    return http_packet;
}

mtu_info* host::get_mtu_packet(){
    return mtu_packet;
}

syn_info* host::get_syn_packet(){
    return syn_packet;
}

uptime_info* host::get_uptime_packet(){
    return uptime_packet;
}


void host::set_http_packet(http_info *packet){
    http_packet = packet;
}

void host::set_mtu_packet(mtu_info *packet){
    mtu_packet = packet;
}

void host::set_syn_packet(syn_info *packet){
    syn_packet = packet;
}

void host::set_uptime_packet(uptime_info *packet){
    uptime_packet = packet;
}
void host::print_packets(){
    if (mtu_packet!=0){
        mtu_packet->print_info();
    }
    if (uptime_packet!=0){
        uptime_packet->print_info();
    }
    if (syn_packet!=0){
         syn_packet->print_info();
    }
    if (http_packet!=0){
        http_packet->print_info();
    }

}

