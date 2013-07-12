#include "host.h"

host::host(QString ip){
    ip_host = ip;
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

syn_info* host::get_mtu_packet(){
   return syn_packet;
}

uptime_info* host::get_mtu_packet(){
   return uptime_packet();
}

void host::set_http_packet(http_packet *packet){
    http_packet = packet;
}

void host::set_mtu_packet(mtu_packet *packet){
    mtu_packet = packet;
}

void host::set_syn_packet(syn_packet *packet){
    syn_packet = packet;
}

void host::set_uptime_packet(uptime_packet *packet){
    uptime_packet = packet;
}
