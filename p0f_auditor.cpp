#include "p0f_auditor.h"
#include "QDebug"
#include <stdio.h>
#include "p0f_info.h"
#include "QString"
#include "QDebug"
#include "network_db.h"

p0f_info *current_packet;



network_db* nt = network_db::get_istance();



//the method creates a new packet looking at the keyword that identifies the packet's type
void create_packet(char* host, int to_srv, char *keyword){
    qDebug()<<host;

    qDebug()<<keyword;

    QString qClient = QString::fromUtf8(host);
    if(strcmp(keyword,"mtu") == 0){
        current_packet = new p0f_info(qClient,MTU_INFO);
    }
    else if(strcmp(keyword,"syn") == 0 || strcmp(keyword,"syn+ack") == 0){
        current_packet = new p0f_info(qClient,SYN_INFO);
    }
    else if(strcmp(keyword,"http response") == 0||strcmp(keyword,"http request")==0){
        current_packet = new p0f_info(qClient,HTTP_INFO);

    }
    else if(strcmp(keyword,"uptime") == 0){
        current_packet = new p0f_info(qClient,UPTIME_INFO);

    }else if(strcmp(keyword,"host change") == 0){
        current_packet = new p0f_info(qClient,HOST_CHANGE);

    }else if(strcmp(keyword,"ip sharing") == 0){
        current_packet = new p0f_info(qClient,IP_SHARING);
    }


}

//add information to packet
void add_info(char *key, char *value){

    QString qKey = QString::fromUtf8(key);
    QString qValue = QString::fromUtf8(value);
    current_packet->set_info_field(qKey,qValue);

}



void end_packet(){

    nt->add_info_network(current_packet);

}

