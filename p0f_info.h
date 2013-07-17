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
    p0f_info(QString ip,int type);
    QString print();


    int isclient(){
        return is_client;
    }
    QString get_address(){
        return ip_address;
    }
protected:
   QString ip_address; //address of the computer which we are trying to identify
   int is_client;         //0 indicates server 1 indicates client
};



class uptime_info : public p0f_info{
private:
    QString uptime;
    QString raw_freq;
public:
   uptime_info(QString server,int type) : p0f_info(server,type){}
   QString print_info();
   QString  get_uptime();
    QString get_raw_freq();
    void set_uptime(QString up_time);
    void set_raw_freq(QString rawfreq);
};

class mtu_info :public p0f_info{
private:
    QString link;
    QString raw_mtu;
public:
    QString print_info();
    mtu_info(QString server,int own) : p0f_info(server,own){}
    QString get_link();
     QString get_raw_mtu();
     void set_link(QString mtu_link);
     void set_raw_mtu(QString mtu);
};

class syn_info :public p0f_info{
private:
    QString os;
    QString dist;
    QString params;
    QString raw_sig;
public:
    syn_info(QString server,int own) : p0f_info(server,own){}
    QString print_info();

    QString get_os();
    QString get_dist();
    QString get_params();
    QString get_raw_sig();
    void set_os(QString SO);
    void set_dist(QString distance);
    void set_params(QString parameters);
    void set_raw_sig(QString sig);
};
class http_info :public p0f_info{
private:
    QString app;
    QString lang;
    QString param;
    QString raw_sig;
public:
    http_info(QString server,int own) : p0f_info(server,own){}
    QString print_info();
    QString get_app();
    QString get_lang();
    QString get_param();
    QString get_raw_sig();
    void set_app(QString application);
    void set_lang(QString language);
    void set_param(QString parameters);
    void set_raw_sig(QString sig);

};
enum info_type{
    HTTP_INFO,
    SYN,
    MTU,
    UPTIME
};





int test();


#endif // P0F_PACKET_H
