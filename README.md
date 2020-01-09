# Poker
Ivan Lin and Jimmy Luo Period 5

# Proposal
1. Description
   - A poker game with at most 4 players. One player will be the server leader and the other players will join. Other game modes may be implemented if there is extra time.
2. UI Description
   - The game will be run using an executable.
   - The user will be given the option to join a game or to create a new game.
   - If the user is starting a new game, the user has to enter a name and password and will send a start game signal when all players join.
   - If the user is joining a game, the user has to enter all the necessary information and then wait for the server leader to start the game.
3. Technical Design Description
   - Forking server to create subservers that control a game of up to 4 people.
   - A linked list of arrays that would store match history. 
   - Bets and current balance will be kept in a text file.
4. Expected Dates
   - 1/9: C program to control and deal with the deck
   - 1/11: Make networking server work 
   - 1/15: Implement rules for game
   - 1/17: Hopefully finish
# Dev Log 
1/9/2020: 
   - create deck: done in class together
      - creates a standard deck of cards, linked list of 52 cards
   - shuffle deck: Jimmy Luo
      - swaps a card with a card in a random position 52 times
   - deal card: Jimmy Luo
      - currently not functional
      - idea: move front node to next node and free the front node
      
   
