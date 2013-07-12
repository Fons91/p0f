#include "p0f_auditor.h"
#include "QDebug"
#include <stdio.h>

void create_packet(char* client, int client_port, char* server, int server_port, char *keyword){
    qDebug()<<client;
    qDebug()<<client_port;
    qDebug()<<QString(server);
    qDebug()<<server_port;
    qDebug()<<keyword;

}

void add_info(char *key, char *value){

}

void end_packet(){

}

/*p0f_auditor::p0f_auditor()
{
}
*/
