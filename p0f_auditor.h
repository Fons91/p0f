#ifndef P0F_AUDITOR_H
#define P0F_AUDITOR_H

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

#endif // P0F_AUDITOR_H
