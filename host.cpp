#include "host.h"

host::host(QString ip){
    ip_host = ip;

}

QString host::get_ip(){
    return ip_host;
}

QString host::get_os(){
    QString os = "";
    if(host_packets.value(SYN_INFO)!=NULL){
        os = host_packets.value(SYN_INFO)->get_value("os");
    }
    return os;
}

//Return the app field value
QString host::get_app(){
    QString app = "";
    if(host_packets.value(HTTP_RESPONSE)!=NULL){
        app = host_packets.value(HTTP_RESPONSE)->get_value("app");
    }
    return app;
}

//Return a specific packet
p0f_info* host::get_packet(info_type type){
    return host_packets.value(type);
}

//Return all packets link to host
QHash<info_type,p0f_info*> host::get_packets(){
    return host_packets;
}


void host::set_packet(p0f_info* info){
    host_packets.insert(info->get_type(),info);
}


//Chech if an host is probably behind nat
bool host::host_with_nat(){
    return this->get_packet(HOST_CHANGE)!=NULL;
}



//Return all the host's informations
QString host::print_packets(){
    QString info;
    if(this->get_packet(HOST_CHANGE)!=NULL){
        info.append("PAY ATTENTION\nHOST MAY BE RUNNING BEHIND NAT\nINFORMATIONS CAN BE INCORRECT");
    }
    foreach(p0f_info* packet, host_packets){
        info.append(packet->get_info());

    }

    return info;

}

