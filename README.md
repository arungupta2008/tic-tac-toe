Tic-Tac-Toe
===========

An artificial game between Man and Computer 

Write a tic tac toe **bot** - that will make **one move** given an input. Assume computer is playing as C 
and the opponent is playing as O. The bot must be intelligent enough to win when provided an opportunity. 
 
Input will have 3 rows of string with 3 characters each. C,O,X are the only possible characters 
in the string. O represents the opponent the computer is playing with, C represents the computer and 
X represents a cell that is not taken. Also assume that computer made the first move or will make 
the first move if no other move has been made.  Below are some sample inputs and corresponding outputs.

I am planning to extend this game to human interaction, now it's only takes an instance of TTT and reply in best way.
so wait for that.
```
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
```
----------
 
 
**About Tic Tac Toe**
 
Tic Tac Toe is a two player turn based board game. In each turn the player makes a move 
by placing the coins given to him.  In the above case, Computer places C and the opponent places O. 
 
Players keep placing coins until they run out of empty slots to place coins or one of 
them wins. The game is won when a player gets three of his/her coins in a row, column or 
diagonal. Example wins below. 
``` 
CCC
XOX                          Horizontal
OXX
 
CXO
COX                          Vertical
CXX
 
CXO
XCX                           Diagonal
OXC
 ```
The game ends in a draw if 9 moves are made and all  'X's are replace by 'C's and 'O's 
and nobody has formed  3 of the same kind in a row, column or diagonal. Example draw
 ```
COC
OCO                          Draw
OCO
```


NOTE::

I have used C++ language version 4.8.1 (gcc-4.8.1)
if you want to compile online please use this link (Recommended)

http://ideone.com/3CcnB8

Below code works in three ways like 1. if Computer is in state of win or 2.   if in state of loose will try to protect
3. if no one is winning then what is the best place to win in future.

Let's if computer is in state of Win there is no problem.
There may be conditions where Computer can't win the match but at least it can't let win the Opponent so,
in this below code will try to find the place and where opponent can win it will put 'C' there because 
it's computer's chance.

let's for below exampl 
XXC
XOC
XXO
then computer will put 'C' at (0,0).

otherwise if computer is in state of Win then there is no problem.

one more Example like that 
OCC
OXC
XXO        

It Can Also solve if both opponent and computer are not in state of win
then what is the best possible  place that computer can put 'C'
for Example for input 
COC
XXX
OXX
out would be 
COC
XXX
OXC


and for  input 
XOC
XXO
XCX
 
output would be 
XOC
XXO
CCX
