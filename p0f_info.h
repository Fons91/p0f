#include <map>
#include <time.h>
#include <QString>
#ifndef P0F_PACKET_H
#define P0F_PACKET_H

//Abstract class
using namespace std;



typedef std::map<QString, QString>MAP;
class p0f_info
{
public:
    enum owner{
        SERVER,
        CLIENT
    };
    p0f_info();
   owner  get_subject(){
        return subject;
    }
private:
    owner subject;
};

class uptime_info : public p0f_info{
private:
    QString uptime;

    QString raw_freq;
public:
    uptime_info(QString time, QString freq){
        uptime=time;
        raw_freq= freq;
    }
   QString  get_uptime(){
        return uptime;
    }
    QString get_raw_freq(){
        return raw_freq;
    }
};

class mtu_info :public p0f_info{
private:
    QString link;
    QString raw_mtu;
public:
    mtu_info(QString l,QString mtu){
        link=l;
        mtu=raw_mtu;
    }
    QString get_link(){
        return link;
    }
     QString get_raw_mtu(){
        return raw_mtu;
    }
};

class syn_info :public p0f_info{
private:
    QString os;
    QString dist;
    QString params;
    QString raw_sig;
public:
    syn_info(QString SO,QString distance,QString parameters,QString sig){
        os=SO;
        dist=distance;
        params=parameters;
        raw_sig=sig;

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
};
class http_response_info :public p0f_info{
private:
    QString app;
    QString lang;
    QString param;
    QString raw_sig;
public:
    http_response_info(QString application,QString language,QString parameters,QString sig){
        app=application;
        lang = language;
        param= parameters;
        raw_sig = sig;
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

};

class p0f_info_factory{
public:
    enum info_type{
        HTTP_RESPONSE,
        SYN,
        MTU,
        UPTIME
    };
    static p0f_info *new_p0f_info(p0f_info_factory::info_type type,MAP info_field);

};


int test();


#endif // P0F_PACKET_H
