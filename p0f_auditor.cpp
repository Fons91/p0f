#include "p0f_auditor.h"
#include "QString"
#include "stdio.h"
#include "QDebug"

void create_info(char* client,int portclient,char* server, int serverport,char* key){
    QString str = QString::fromUtf8( client );

    qDebug()<<"Client "<<str;

    printf("dawdawdwadas");

}
/*
p0f_auditor::p0f_auditor()
{
}
*/
