#include "networking.h"
//WIP

int main(int argc, char **argv){
  int server_socket;
  char buffer[BUFFER_SIZE];

  while(1){
    printf("Enter p for poker:\n");
    fgets(buffer, sizeof(buffer), stdin);
    //if(buffer[BUFFER_SIZE - 1] == '\n') buffer[BUFFER_SIZE - 1] = '\0'; //need to remove new line
    printf("%s", buffer);
    if(!strcmp(buffer,"p")){
      printf("Error. Emergency Exit\n");
      return 0;
    }
    printf("Enter your IP Address:\n");
    fgets(buffer, sizeof(buffer), stdin);
    //if(buffer[BUFFER_SIZE - 1] == '\n') buffer[BUFFER_SIZE - 1] = 0;
    if(argc == 2) server_socket = client_setup(argv[1]);
    else server_socket = client_setup(buffer);
    
    write(server_socket, buffer, sizeof(buffer));
    read(server_socket, buffer, sizeof(buffer));

    printf("Waiting for players... Type start if all players joined\n");
    //track how many players joined if 4 players immediately start
    fgets(buffer, sizeof(buffer), stdin);
    //if(!strcmp(buffer, "start")){
    //run program...
  }

  return 0;
}
