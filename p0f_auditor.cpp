#include "p0f_auditor.h"

#include "QDebug"
#include <stdio.h>
#include "p0f_info.h"

#include "QString"
#include "stdio.h"
#include "QDebug"


void add_info_mtu(QString key, QString value);
void add_info_http_response(QString key, QString value);
void add_info_syn(QString key, QString value);
void add_info_uptime(QString key, QString value);

mtu_info* mtu_packet;
http_response_info* http_response_packet;
syn_info* syn_packet;
uptime_info* uptime_packet;

p0f_info_factory::info_type packet_type;

void create_packet(char* host, int to_srv, char *keyword){
    qDebug()<<host;

    qDebug()<<keyword;

    QString qClient = QString::fromUtf8(host);
    if(strcmp(keyword,"mtu") == 0){
        packet_type = p0f_info_factory::MTU;
        mtu_packet = new mtu_info(qClient, to_srv);
        qDebug()<<"Created a mtu_packet";
    }
    else if(strcmp(keyword,"syn") == 0 || strcmp(keyword,"syn+ack") == 0){
        packet_type = p0f_info_factory::SYN;
        syn_packet = new syn_info(qClient, to_srv);
    }
    else if(strcmp(keyword,"http_response") == 0){
        packet_type = p0f_info_factory::HTTP_RESPONSE;
        http_response_packet = new http_response_info(qClient, to_srv);
    }
    else if(strcmp(keyword,"uptime") == 0){
        packet_type = p0f_info_factory::UPTIME;
        uptime_packet = new uptime_info(qClient, to_srv);
    }





}

void add_info(char *key, char *value){
    QString qKey = QString::fromUtf8(key);
    QString qValue = QString::fromUtf8(value);
    if(packet_type == p0f_info_factory::MTU){
        add_info_mtu(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::HTTP_RESPONSE){
        //add_info_http_response(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::SYN){
       // add_info_syn(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::UPTIME){
       // add_info_uptime(qKey,qValue);
    }
}

void add_info_mtu(QString key, QString value){

    qDebug()<<"add information to mtu_packet";
    if(key.compare("link") == 0){
        mtu_packet->set_link(value);
    }
    else if(key.compare("raw_mtu") == 0){
        mtu_packet->set_raw_mtu(value);
    }
    qDebug()<<mtu_packet->get_address();
    qDebug()<<mtu_packet->get_link();
    qDebug()<<mtu_packet->get_raw_mtu();
}

void end_packet(){

}



