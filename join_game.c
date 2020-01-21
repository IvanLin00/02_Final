#include "networking.h"

int main(int argc, char **argv) {

  int server_socket;
  char ip[BUFFER_SIZE], buffer[BUFFER_SIZE];

  fd_set read_fds;

  printf("Enter the IP Address of the game: ");
  fgets(ip, sizeof(ip), stdin);
  *strchr(ip, '\n');

  if (argc == 2) server_socket = client_setup(argv[1]);
  else server_socket = client_setup(ip);

  printf("Connected!\nWaiting for other players...\n");

  while (1) {
    fflush(stdout);

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    FD_SET(server_socket, &read_fds);

    select(server_socket + 1, &read_fds, NULL, NULL, NULL);

    if (FD_ISSET(STDIN_FILENO, &read_fds)) {
      fgets(buffer, sizeof(buffer), stdin);
      *strchr(buffer, '\n') = 0;
      write(server_socket, buffer, sizeof(buffer));
      read(server_socket, buffer, sizeof(buffer));
    }

    if (FD_ISSET(server_socket, &read_fds)) {
      read(server_socket, buffer, sizeof(buffer));
      if(!strcmp(buffer, "start")){
        printf("Game will start now!\n");
        run_game();
        return 0;
      }
      fflush(stdout);
    }
  }
  return 0;
}
