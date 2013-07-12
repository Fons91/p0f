#include "network_db.h"

network_db::network_db()
{   
}
host* network_db::find_host(QString addr){
    for(int i=0;i<network.size();i++){
        if (addr.compare(network[i].get_ip()))
            return network[i];
    }
    return NULL;
}

void network_db::add_packet(p0f_info packet){

}

