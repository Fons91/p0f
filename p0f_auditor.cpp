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
http_info* http_info_packet;
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
        packet_type = p0f_info_factory::HTTP_INFO;
        http_info_packet = new http_info(qClient, to_srv);
    }
    else if(strcmp(keyword,"uptime") == 0){
        packet_type = p0f_info_factory::UPTIME;
        uptime_packet = new uptime_info(qClient, to_srv);
    }





}

//choose type of packet
void add_info(char *key, char *value){
    QString qKey = QString::fromUtf8(key);
    QString qValue = QString::fromUtf8(value);
    if(packet_type == p0f_info_factory::MTU){
        add_info_mtu(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::HTTP_INFO){
        add_info_http_response(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::SYN){
        add_info_syn(qKey,qValue);
    }
    else if(packet_type == p0f_info_factory::UPTIME){
        add_info_uptime(qKey,qValue);
    }
}

//methods to add information to packets
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

void add_info_http_response(QString key, QString value){
    if(key.compare("app") == 0){
        http_info_packet->set_app(value);
    }
    else if(key.compare("lang") == 0){
        http_info_packet->set_lang(value);
    }
    else if(key.compare("params") == 0){
        http_info_packet->set_param(value);
    }
    else if(key.compare("raw_sig") == 0){
        http_info_packet->set_raw_sig(value);
    }
    qDebug()<<http_info_packet->get_app();
    qDebug()<<http_info_packet->get_lang();
    qDebug()<<http_info_packet->get_param();
    qDebug()<<http_info_packet->get_raw_sig();
}

void add_info_syn(QString key, QString value){
    if(key.compare("dist") == 0){
        syn_packet->set_dist(value);
    }
    else if(key.compare("os") == 0){
        syn_packet->set_os(value);
    }
    else if(key.compare("params") == 0){
        syn_packet->set_params(value);
    }
    else if(key.compare("raw_sig") == 0){
        syn_packet->set_raw_sig(value);
    }
    qDebug()<<syn_packet->get_dist();
    qDebug()<<syn_packet->get_os();
    qDebug()<<syn_packet->get_params();
    qDebug()<<syn_packet->get_raw_sig();
}

void add_info_uptime(QString key, QString value){
    if(key.compare("uptime") == 0){
        uptime_packet->set_uptime(value);
    }
    else if(key.compare("raw_freq") == 0){
        uptime_packet->set_raw_freq(value);
    }
    qDebug()<<uptime_packet->get_uptime();
    qDebug()<<uptime_packet->get_raw_freq();
}

void end_packet(){

}



