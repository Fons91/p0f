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

    //packet = p0f_info_factory::new_p0f_info();

}

void add_info(char *key, char *value){

}

void end_packet(){

}

/*p0f_auditor::p0f_auditor()
{
}
*/
