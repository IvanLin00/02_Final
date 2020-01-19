#include "networking.h"
//WIP

int main(int argc, char **argv){
  int server_socket;
  char buffer[BUFFER_SIZE];

  while(1){
    printf("Enter p for poker: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    if(strcmp(buffer,"p")){
      printf("Error. Emergency Exit\n");
      return 0;
    }
    printf("Enter your IP Address: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    if(argc == 2) server_socket = client_setup(argv[1]);
    else server_socket = client_setup(buffer);
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));

    printf("Waiting for players... Type start if all players joined\n");
    fgets(buffer, sizeof(buffer), stdin);

    if(!strcmp(buffer, "start")){
      write(server_socket, buffer, sizeof(buffer));
      read(server_socket, buffer, sizeof(buffer));
    }
    //have the main server run program somehow...
  }

  return 0;
}
