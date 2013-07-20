#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;

p0f_info::p0f_info(QString ip,info_type packet_type){
    ip_address = ip;
    type = packet_type;
}

//Return all informations about the packet
QString p0f_info::get_info(){
    QString type_of_info = "";
    if (type == MTU_INFO){
        type_of_info = " MTU";
    }
    else if (type == SYN_INFO){
        type_of_info = " SYN";
    }
    else if (type == HTTP_REQUEST){
        type_of_info = " HTTP REQUEST";
    }
    else if (type == HTTP_RESPONSE){
        type_of_info = " HTTP RESPONSE";
    }
    else if (type == UPTIME_INFO){
        type_of_info = " UPTIME";
    }
    else if (type == IP_SHARING){
        type_of_info = " IP SHARING";
    }
    else if (type == HOST_CHANGE){
        type_of_info = " HOST CHANGE";
    }
    QString info = "\n\nPACKET" + type_of_info;
    foreach (QString key,information.keys()){
        if (information.value(key) != "" && information.value(key) != "none"){
            info.append("\n" + key + ": " + information.value(key));

            qDebug()<<key<<"  "<<information.value(key);
        }

    }
    return info;
}


QString p0f_info::get_value(QString field){
    return information.value(field);
}

QString p0f_info::get_address(){
    return ip_address;
}



info_type p0f_info::get_type(){
    return type;
}


void p0f_info::set_info_field(QString key,QString value){
    information.insert(key,value);
}
