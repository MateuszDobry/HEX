Hex is a program that evaluates the winning possibilities for two players: red and blue, in the game of HEX ([link to the rules](https://www.kurnik.pl/hex/zasady.phtml)).
The program takes the current state of the game board and responds to specific questions regarding whether a given situation is possible.

The possible questions that can be asked are:

 - BOARD_SIZE
 - PAWNS_NUMBER
 - IS_BOARD_CORRECT
 - IS_GAME_OVER
 - IS_BOARD_POSSIBLE
 - CAN_RED_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT
 - CAN_BLUE_WIN_IN_1_MOVE_WITH_NAIVE_OPPONENT
 - CAN_RED_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT
 - CAN_BLUE_WIN_IN_2_MOVES_WITH_NAIVE_OPPONENT
 - CAN_RED_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT
 - CAN_BLUE_WIN_IN_1_MOVE_WITH_PERFECT_OPPONENT
 - CAN_RED_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT
 - CAN_BLUE_WIN_IN_2_MOVES_WITH_PERFECT_OPPONENT

As you can see, the program also allows for checking whether a situation is possible when playing against a perfect opponent as well as a naive opponent.

Sample input data can be found in the in.txt file.

Enjoy testing! 😁
