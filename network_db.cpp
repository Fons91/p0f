#include "network_db.h"
#include "QDebug"
network_db* network_db::istance =NULL;

network_db::network_db()
{   
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
    qDebug()<<"NETwork recived packed"<<packet->get_address();

    host* old_host = network_db::find_host(packet->get_address());
    if (old_host == 0){
        qDebug()<<"CREATING HOST WITH IP"<<packet->get_address();
        host *new_host = new host(packet->get_address());
        network_db::add_packet_host(packet,new_host);
        network.append(new_host);
    }
    else{
        qDebug()<<"Adding packet";
            network_db::add_packet_host(packet,old_host);
        }

    }


void  network_db::show_network(){
    qDebug()<<"SHOWING NETWORK"<<network.size();

    for (int i = 0;i<network.size();i++){
        qDebug()<<"<--------------------------------------------------------------------------->";
        qDebug()<<"host n "<<i<<" ip "<<network[i]->get_ip();
        network[i]->print_packets();



    }
}

 network_db* network_db::get_istance(){
    if(!istance) istance = new network_db();
    return istance;
}


