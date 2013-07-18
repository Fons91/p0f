#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;

p0f_info::p0f_info(QString ip,info_type packet_type){
    ip_address=ip;
    type=packet_type;
}

QString p0f_info::get_info(){
    QString info = ">>>>>>>>>PACKET<<<<<<<<<<< \nADDRESS "+ip_address+"\nIS_CLIENT "+type+"\n";
    foreach (QString key,information.keys()){
        info.append(key+"  "+information.value(key));
        qDebug()<<key<<"  "<<information.value(key);

    }
    qDebug()<<">>>>>>>>>PACKET<<<<<<<<<<<";
    qDebug()<<"ADDRESS "<<ip_address<<"\nTYPE"<<type;
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
