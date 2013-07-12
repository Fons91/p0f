#include "p0f_auditor.h"
#include "QDebug"
#include <stdio.h>
#include "p0f_info.h"



p0f_info* packet;

void create_packet(char* client, int client_port, char* server, int server_port, char *keyword){
    qDebug()<<client;
    qDebug()<<client_port;
    qDebug()<<QString(server);
    qDebug()<<server_port;
    qDebug()<<keyword;
    p0f_info_factory::info_type tmp;
    if(strcmp(keyword,"mtu")){
        tmp = p0f_info_factory::MTU;
    }
    if(strcmp(keyword,"syn")){
        tmp = p0f_info_factory::SYN;
    }
    if(strcmp(keyword,"http_response")){
        tmp = p0f_info_factory::HTTP_RESPONSE;
    }
    if(strcmp(keyword,"uptime")){
        tmp = p0f_info_factory::UPTIME;
    }

    //packet = p0f_info_factory::new_p0f_info(tmp,client);

}

void add_info(char *key, char *value){

}

void end_packet(){

}

/*p0f_auditor::p0f_auditor()
{
}
*/
