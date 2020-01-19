#include "networking.h"

int main() {

  int server_socket;
  //int listen_socket, client_socket;
  char buffer[BUFFER_SIZE];

  fd_set read_fds;

  while (1) {
    printf("Enter p for poker: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    if(strcmp(buffer,"p")){
      printf("Error. Emergency Exit\n");
      return 0;
    }

    //listen_socket = server_setup();
    //printf("Please wait for an opponent...\n\n");

    //client_socket = server_connect(listen_socket);
    //printf("Opponent found!\n\n");

    //not sure if these lines of code should be in join or make

    printf("Enter your IP Address: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    server_socket = client_setup(buffer);
    printf("Connected!\nWaiting for other players...");
  }
}
