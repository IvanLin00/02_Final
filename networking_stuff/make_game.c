#include "networking.h"
//WIP

int main(int argc, char **argv){
  //int server_socket;
  int listen_socket, client_socket, num_players;
  int current_players = 1;
  char game_mode[BUFFER_SIZE], players[BUFFER_SIZE];

  fd_set read_fds;

  printf("Enter p for poker: ");
  fgets(game_mode, sizeof(game_mode), stdin);
  *strchr(game_mode, '\n') = 0;
  if(strcmp(game_mode,"p")){
    printf("Error. Emergency Exit\n");
    return 0;
  }

  printf("How many players (must be less than 4 and greater than 1): ");
  fgets(players, sizeof(players), stdin);
  *strchr(players, '\n') = 0;
  sscanf(players, "%d", &num_players);

  printf("Waiting for players...\n");
  listen_socket = server_setup();

  while (current_players < num_players) {
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);
    FD_SET(listen_socket, &read_fds);

    select(listen_socket + 1, &read_fds, NULL, NULL, NULL);

    if (FD_ISSET(listen_socket, &read_fds)) {
      printf("A player has joined!\n");
      current_players++;
    }
  }
  printf("All players joined! Starting game...\n");
  //run_game();
  return 0;
}
