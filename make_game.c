#include "networking.h"
#include "poker.h"

int main(int argc, char **argv){
  int listen_socket, client_socket, num_players;
  int current_players = 1;
  char game_mode[BUFFER_SIZE], players[BUFFER_SIZE], buffer[BUFFER_SIZE];

  fd_set read_fds;

  printf("Enter p for poker: ");
  fgets(game_mode, sizeof(game_mode), stdin);
  *strchr(game_mode, '\n') = 0;
  if(strcmp(game_mode,"p")){
    printf("Error. Emergency Exit\n");
    return 0;
  }

  num_players = 3;

  printf("Waiting for two more players...\n");
  listen_socket = server_setup();
  int player_data[num_players - 1];

  while (current_players < num_players) {
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    FD_SET(listen_socket, &read_fds);

    select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    if (FD_ISSET(listen_socket, &read_fds)) {
      player_data[current_players - 1] = server_connect(listen_socket);
      printf("A player has joined!\n");
      current_players++;
    }
  }
  printf("All players joined! Starting game...\n");
  for(int i = 0; i < num_players - 1; i++){
    client_socket = player_data[i];
    strcpy(buffer, "start");
    write(client_socket, buffer, sizeof(buffer));
  }
  run_game();
  printf("Thank you for playing!\n");
  return 0;
}
