#include <map>
#include <time.h>
#include <QString>
#include "QDebug"
#include "QMap"
#ifndef P0F_PACKET_H
#define P0F_PACKET_H

//Abstract class

enum info_type{
    MTU_INFO,
    HTTP_INFO,
    SYN_INFO,
    UPTIME_INFO
};

class p0f_info
{
public:
    p0f_info(QString ip, info_type packet_type);
    QString get_value(QString field);
    QString get_address();
    QString get_info();
    info_type get_type();
    void set_info_field(QString key,QString value);


private:
   QHash<QString,QString> information;//place where info are stored
   QString ip_address; //address of the computer which we are trying to identify
   info_type type;      //type of info(mtu http syn)

};





#endif // P0F_PACKET_H
