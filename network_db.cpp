#include "network_db.h"
#include "QDebug"
network_db* network_db::istance =NULL;

network_db::network_db()
{   
}
host* network_db::find_host(QString addr){
    for(int i=0;i<network.size();i++){
        qDebug()<<"Comparing "<<addr<<"   "<<network[i]->get_ip();
        if (addr.compare(network[i]->get_ip())==0){
            qDebug()<<"is equal "<<addr<<"   "<<network[i]->get_ip();
            return network[i];
        }
    }
    return 0;
}

void  network_db::add_info_network(p0f_info *packet,info_type Itype){
    qDebug()<<"NETwork recived packed"<<packet->get_address();

    host* old_host=network_db::find_host(packet->get_address());
    if (old_host==0){
        qDebug()<<"CREATING HOST WITH IP"<<packet->get_address();
        host *new_host = new host(packet->get_address());
        network_db::add_packet_host(packet,Itype,new_host);
        network.append(new_host);
    }
    else{
        qDebug()<<"Adding packet";
            network_db::add_packet_host(packet,Itype,old_host);
        }

    }


void  network_db::add_packet_host(p0f_info *packet, info_type Itype, host* new_host){
    if (Itype==HTTP_INFO){
        new_host->set_http_packet((http_info*)packet);
    }
    else if(Itype==MTU){
        new_host->set_mtu_packet((mtu_info*)packet);
    }
    else if(Itype==SYN){
        new_host->set_syn_packet((syn_info*)packet);
    }
    else if(Itype==UPTIME){
        new_host->set_uptime_packet((uptime_info*)packet);
    }
}

void  network_db::show_network(){
    qDebug()<<"SHOWING NETWORK"<<network.size();

    for (int i=0;i<network.size();i++){
        qDebug()<<"<--------------------------------------------------------------------------->";
        qDebug()<<"host n "<<i<<" ip "<<network[i]->get_ip();
        network[i]->print_packets();



    }
}

 network_db* network_db::get_istance(){
    if(!istance) istance = new network_db();
    return istance;
}


