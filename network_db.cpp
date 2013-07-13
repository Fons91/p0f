#include "network_db.h"

network_db::network_db()
{   
}
host* network_db::find_host(QString addr){
    for(int i=0;i<network.size();i++){
        if (addr.compare(network[i]->get_ip()))
            return network[i];
    }
    return NULL;
}

void  network_db::add_info_network(p0f_info *packet,p0f_info_factory::info_type info_type){
    host* old_host=find_host(packet->get_address());
    if (old_host==NULL){
        host *new_host = new host(packet->get_address());
        add_packet_host(packet,info_type,new_host);
        network.append(new_host);
    }
    else{
            add_packet_host(packet,info_type,old_host);
        }

    }


void  network_db::add_packet_host(p0f_info *packet,p0f_info_factory::info_type info_type,host* new_host){
    if (info_type==p0f_info_factory::HTTP_INFO){
        new_host->set_http_packet((http_info*)packet);
    }
    else if(info_type==p0f_info_factory::MTU){
        new_host->set_mtu_packet((mtu_info*)packet);
    }
    else if(info_type==p0f_info_factory::SYN){
        new_host->set_syn_packet((syn_info*)packet);
    }
    else if(info_type==p0f_info_factory::UPTIME){
        new_host->set_uptime_packet((uptime_info*)packet);
    }
}

void  network_db::show_network(){
    for (int i=0;i<network.size();i++){
        network[i]->get_mtu_packet()->print_info();

    }
}
