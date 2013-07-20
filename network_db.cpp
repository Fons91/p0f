#include "network_db.h"
#include "QDebug"

network_db* network_db::istance =NULL;

network_db::network_db()
{   
}

network_db* network_db::get_istance(){
    if(!istance) istance = new network_db();
    return istance;
}

host* network_db::find_host(QString addr){
    for(int i = 0;i<network.size();i++){
        if (addr.compare(network[i]->get_ip()) == 0){
            return network[i];
        }
    }
    return 0;
}




void  network_db::add_packet_host(p0f_info *packet, host* new_host){
    new_host->set_packet(packet);
}

//Add a packet to an existing host or to a new one
void  network_db::add_info_network(p0f_info *packet){

    host* old_host = network_db::find_host(packet->get_address());
    if (old_host == 0){
        host *new_host = new host(packet->get_address());
        network_db::add_packet_host(packet,new_host);
        network.append(new_host);
    }else{
        network_db::add_packet_host(packet,old_host);
    }

}







