# straights
Straights card game in CLI

After compiling the program with make, the program can be executed with the command ./straights <seed>, where seed is an optional command-line argument input for deck shuffling

After the command is entered, the first thing the program asks for is player type. The user can decide between typing in âhâ for human player or âcâ for computer player for all 4 players. The human player option will require the player to decide all their moves on their own, that is, deciding which card to play and which to discard. The computer player is an automated player that plays or discards the first card possible. (To do: create smarter computer players)

```
// plays a card
play <card>
```
```
// discards a card
discard <card>
```
```
// computer player takes over human player
ragequit
```
```
// displays shuffled deck (cheats lol)
deck
```
```
// terminate program
quit
```

Model-View-Controller design pattern
<img width="1053" alt="Screen Shot 2020-12-17 at 11 18 05 AM" src="https://user-images.githubusercontent.com/53837437/134428706-5de4e4df-59c7-483f-b86e-2dcb963d52da.png">

