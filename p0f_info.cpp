#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;

//factory method which recives the info_type TYPE of the info to be created and the ip addr (QString) MACHINE_ADDR of the machine which the info refers to
//It returns a p0f_info object
p0f_info *p0f_info_factory::new_p0f_info(p0f_info_factory::info_type type,QString machine_addr){

    p0f_info *info=0;
    if(type==HTTP_INFO){
         info = new http_info(machine_addr);
    }
    else if(type==SYN){
         info = new syn_info(machine_addr);
    }
    else if(type==MTU){
        info= new mtu_info(machine_addr);
    }
    else if(type==UPTIME){
        info = new uptime_info(machine_addr );
    }
    return info;
}

