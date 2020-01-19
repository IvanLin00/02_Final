#include "networking.h"

int main() {

  int server_socket;
  int listen_socket, client_socket;
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
    printf("Enter your IP Address: ");
    fgets(buffer, sizeof(buffer), stdin);
    *strchr(buffer, '\n') = 0;
    printf("Connected!\nWaiting for other players...");
  }
}
