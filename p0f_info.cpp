#include <string>
#include <map>
#include "p0f_info.h"
#include <QDebug>


using namespace std;
//p0f_info



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
        info = new mtu_info(machine_addr);
    }
    else if(type==UPTIME){
        info = new uptime_info(machine_addr );
    }
    return info;
    }

int test(){
    QString addr= "192.168.0.100";
    syn_info* info = (syn_info*) p0f_info_factory::new_p0f_info(p0f_info_factory::SYN,addr);
    mtu_info* info2= new mtu_info("dasdsad",1);
    info2->set_link("dsadsa");
    qDebug()<<info2->isclient();
    info->set_os("Window");
    qDebug()<<  info->get_os();
    qDebug()<<  info->get_address();
    qDebug()<< info->get_raw_sig();






    return 0;
}
