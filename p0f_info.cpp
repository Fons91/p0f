#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;

p0f_info::p0f_info(){}

p0f_info *p0f_info_factory::new_p0f_info(p0f_info_factory::info_type type,MAP info_field){

    p0f_info *info=0;
    if(type==HTTP_RESPONSE){
         info = new http_response_info(info_field["app"],info_field["lang"],info_field["param"],info_field["raw_sig"]);
    }
    else if(type==SYN){
         info = new syn_info(info_field["os"],info_field["dist"],info_field["params"],info_field["raw_sig"]);
    }

    return info;
    }

int test(){
    map<string,string> mp;
    mp["os"]="Linux";
    mp["params"]="niente";
    mp["dist"]="dadas";
    mp["raw_sig"]="raw";
    syn_info* info = (syn_info*) p0f_info_factory::new_p0f_info(p0f_info_factory::SYN,mp);
    qDebug()<< QString::fromUtf8( info->get_os().c_str() );



    return 0;
}
