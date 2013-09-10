Tic-Tac-Toe
===========

An artificial game between Man and Computer 

Write a tic tac toe **bot** - that will make **one move** given an input. Assume computer is playing as C 
and the opponent is playing as O. The bot must be intelligent enough to win when provided an opportunity. 
 
Input will have 3 rows of string with 3 characters each. C,O,X are the only possible characters 
in the string. O represents the opponent the computer is playing with, C represents the computer and 
X represents a cell that is not taken. Also assume that computer made the first move or will make 
the first move if no other move has been made.  Below are some sample inputs and corresponding outputs.
 
Input1
OOX
XCX
XCX
 
Output1
OOC
XCX
XCX
 
Input2
CCX
XOX
OXX
 
Output2
CCC
XOX
OXX
 
Input3
XOC
XXX
COX
 
Output3
XOC
XCX
COX
 
Input4
COC
OXX
XXX
 
Output4
COC
OCX
XXX
 
----------
 
 
**About Tic Tac Toe**
 
Tic Tac Toe is a two player turn based board game. In each turn the player makes a move 
by placing the coins given to him.  In the above case, Computer places C and the opponent places O. 
 
Players keep placing coins until they run out of empty slots to place coins or one of 
them wins. The game is won when a player gets three of his/her coins in a row, column or 
diagonal. Example wins below. 
 
CCC
XOX                          Horizontal
OXX
 
CXO
COX                          Vertical
CXX
 
CXO
XCX                           Diagonal
OXC
 
The game ends in a draw if 9 moves are made and all  'X's are replace by 'C's and 'O's 
and nobody has formed  3 of the same kind in a row, column or diagonal. Example draw
 
COC
OCO                          Draw
OCO
