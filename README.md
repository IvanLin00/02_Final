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
   - modified linked_list functions to work with the struct card: done together in class
   - struct card * create_deck(): done in class together
      - creates a standard deck of cards, linked list of 52 cards, shuffles afterwards, returns shuffled deck
   - void shuffle(struct card * deck): Jimmy Luo
      - takes a deck and swaps a card in every position with a card in another random position
   - void swap(struct card * deck, int first, int second): Jimmy Luo
      - swaps card in position first with card in position second 
  
1/10/2019
   - struct card * deal_card(struct card * deck): done in class together
      - deals the first card, print card dealt, returns new top card. 
      
   
