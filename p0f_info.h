#include <map>
#include <time.h>
#include <QString>
#include "QDebug"
#ifndef P0F_PACKET_H
#define P0F_PACKET_H

//Abstract class

class p0f_info
{
public:
    void print(){
        qDebug()<<"ADDRESS "<<server_address<<"\nIS_CLIENT "<<is_client;
    }
    p0f_info(QString server){//I create 2 constuctor because the owner field is optional
        server_address=server;
    }
    p0f_info(QString server,int type){
        server_address=server;
        is_client=type;
    }
    int isclient(){
        return is_client;
    }
    QString get_address(){
        return server_address;
    }
protected:
   QString server_address; //address of the computer which we are trying to identify
   int is_client;         //0 indicates server 1 indicates client
};



class uptime_info : public p0f_info{
private:
    QString uptime;
    QString raw_freq;
public:
   uptime_info(QString server) :p0f_info(server){}
   uptime_info(QString server,int own) : p0f_info(server,own){}
   void print_info(){
       p0f_info::print();
       qDebug()<<"UPTIME PACKET\n"<<"uptime:"<<uptime<<"\nraw_sig "<<raw_freq;
   }
   QString  get_uptime(){
        return uptime;
    }
    QString get_raw_freq(){
        return raw_freq;
    }
    void set_uptime(QString up_time){
        uptime=up_time;
    }
    void set_raw_freq(QString rawfreq){
        raw_freq=rawfreq;
    }
};

class mtu_info :public p0f_info{
private:
    QString link;
    QString raw_mtu;
public:
    void print_info(){
        p0f_info::print();
        qDebug()<<"MTU PACKET\n"<<"link:"<<link<<"\nraw_mtu:"<<raw_mtu;
    }
    mtu_info(QString server) :p0f_info(server){}
    mtu_info(QString server,int own) : p0f_info(server,own){}
    QString get_link(){
        return link;
    }
     QString get_raw_mtu(){
        return raw_mtu;
    }
     void set_link(QString mtu_link){
         link= mtu_link;
     }
     void set_raw_mtu(QString mtu){
         raw_mtu=mtu;

     }
};

class syn_info :public p0f_info{
private:
    QString os;
    QString dist;
    QString params;
    QString raw_sig;
public:
    syn_info(QString server) :p0f_info(server){}
    syn_info(QString server,int own) : p0f_info(server,own){}
    void print_info(){
        p0f_info::print();
        qDebug()<<"SYN PACKET\n os:"<<os<<"\ndist:"<<dist<<"\nparams "<<params<<"\nraw_sig "<<raw_sig;
    }

    QString get_os(){
        return os;
    }
    QString get_dist(){
        return dist;
    }
    QString get_params(){
        return params;
    }
    QString get_raw_sig(){
        return raw_sig;
    }
    void set_os(QString SO){
       os=SO;
    }
    void set_dist(QString distance){
        dist=distance;
    }
    void set_params(QString parameters){
        params=parameters;
    }
    void set_raw_sig(QString sig){
        raw_sig=sig;
    }
};
class http_info :public p0f_info{
private:
    QString app;
    QString lang;
    QString param;
    QString raw_sig;
public:
    http_info(QString server) :p0f_info(server){}
    http_info(QString server,int own) : p0f_info(server,own){}
    void print_info(){
        p0f_info::print();
        qDebug() << "HTTP PACKET\n"<<"app:"<<app<<"\nlang:"<<lang<<"\nparams "<<param<<"\nraw_sig "<<raw_sig;
    }
    QString get_app(){
        return app;
    }
    QString get_lang(){
        return lang;
    }
    QString get_param(){
        return param;
    }
    QString get_raw_sig(){
        return raw_sig;
    }
    void set_app(QString application){
        app=application;
    }
    void set_lang(QString language){

        lang=language;
    }
    void set_param(QString parameters){
        param=parameters;
    }
    void set_raw_sig(QString sig){
        raw_sig=sig;
    }

};

class p0f_info_factory{
public:
    enum info_type{
        HTTP_INFO,
        SYN,
        MTU,
        UPTIME
    };
    static p0f_info *new_p0f_info(p0f_info_factory::info_type type,QString machine_addr);

};




int test();


#endif // P0F_PACKET_H
