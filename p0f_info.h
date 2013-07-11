#include <map>
#include <time.h>
#include <string>
#ifndef P0F_PACKET_H
#define P0F_PACKET_H

//Abstract class
using namespace std;



typedef std::map<std::string, std::string>MAP;
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
    time_t uptime;

    string raw_freq;
public:
    uptime_info(time_t time, string freq){
        uptime=time;
        raw_freq= freq;
    }
   time_t  get_uptime(){
        return uptime;
    }
    string get_raw_freq(){
        return raw_freq;
    }
};

class mtu_info :public p0f_info{
private:
    string link;
    string raw_mtu;
public:
    mtu_info(string l,string mtu){
        link=l;
        mtu=raw_mtu;
    }
    string get_link(){
        return link;
    }
     string get_raw_mtu(){
        return raw_mtu;
    }
};

class syn_info :public p0f_info{
private:
    string os;
    string dist;
    string params;
    string raw_sig;
public:
    syn_info(string SO,string distance,string parameters,string sig){
        os=SO;
        dist=distance;
        params=parameters;
        raw_sig=sig;

    }

    string get_os(){
        return os;
    }
    string get_dist(){
        return dist;
    }
    string get_params(){
        return params;
    }
    string get_raw_sig(){
        return raw_sig;
    }
};
class http_response_info :public p0f_info{
private:
    string app;
    string lang;
    string param;
    string raw_sig;
public:
    http_response_info(string application,string language,string parameters,string sig){
        app=application;
        lang = language;
        param= parameters;
        raw_sig = sig;
    }
    string get_app(){
        return app;
    }
    string get_lang(){
        return lang;
    }
    string get_param(){
        return param;
    }
    string get_raw_sig(){
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
