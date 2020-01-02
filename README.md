# Poker
Ivan Lin and Jimmy Luo Period 5

# Proposal
1. Description
   - A poker game with at most 4 players. One player will be the server leader and the other players will join. Other game modes may be implemented if there is extra time.
2. UI Description
   - The game will be run using an executable.
   - The user will beg given the option of joining a game or creating a new game.
   - If the user is starting a new game, the user has to enter a name and password and will send a start game signal when all players join.
   - If the user is joining a game, the user has to enter all the necessary information and then wait for the server leader to start the game.
3. Technical Design Description
   - One player will make a server so that 3 other people can join through networking.
   - Turn order will be regulated through semaphores.
   - Bets and current balance will be kept in a text file.
   - Actions will be determined through signals.
4. Expected Dates
   - ... 
