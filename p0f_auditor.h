#ifndef P0F_AUDITOR_H
#define P0F_AUDITOR_H
>>>>>>>>>>>>>>>>>>>> File 1
#ifdef  __cplusplus
extern "C"{
void create_packet(char* client, int client_port, char* server, int server_port, char* keyword);
void add_info(char* key, char* value);
void end_packet();
}
#else
void create_packet(char* client, int client_port, char* server, int server_port, char* keyword);
void add_info(char* key, char* value);
void end_packet();
#endif
/*
>>>>>>>>>>>>>>>>>>>> File 2

>>>>>>>>>>>>>>>>>>>> File 3
#ifdef __cplusplus
extern "C" void create_info(char* client,int portclient,char* server, int serverport,char* key );

#endif
/*
<<<<<<<<<<<<<<<<<<<<
class p0f_auditor
{
public:
>>>>>>>>>>>>>>>>>>>> File 1
    p0f_auditor();  
>>>>>>>>>>>>>>>>>>>> File 2
    p0f_auditor();  
>>>>>>>>>>>>>>>>>>>> File 3
    p0f_auditor();
<<<<<<<<<<<<<<<<<<<<
};
>>>>>>>>>>>>>>>>>>>> File 1
*/
>>>>>>>>>>>>>>>>>>>> File 2

>>>>>>>>>>>>>>>>>>>> File 3
*/

<<<<<<<<<<<<<<<<<<<<
#endif // P0F_AUDITOR_H
