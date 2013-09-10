


/**
NOTE::
It was a great experience, thanx for giving me this opportunity. If you want i can give a try to extend this solution for real time man Vs Computer TTT game.
Note:: I have used C++ language version 4.8.1 (gcc-4.8.1)
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
**/



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//using namespace std;
int source =0 ,des = 0;
void print_mat(char **ttt)
{
   for(int i=0; i<3;++i){
        for(int j=0; j<3;++j){
         printf("%c",ttt[i][j]);
        }
       printf("\n");
	}
      // getch();
   exit(1);
 }
 void print_opo(char **ttt,int s,int d)
 {
	//printf("\n(%d,%d) is the position where Oponent can win, This is computer's chance,  computer will not let oponent win\n", s,d);
	ttt[s][d] = 'C';
	for(int i=0; i<3;++i){
	    for(int j=0; j<3;++j){
		 printf("%c",ttt[i][j]);
	    }
       printf("\n");
	}
      // getch();
	exit(1);
 }
int traverse_H(char **ttt , int s , int d,char side)
{
	int count =1;
    int possible_count = 1;
    int place;
    int fin_place;
	char oppo_side;
	if(side == 'C')
	{
		oppo_side = 'O';
	}
	else 
	oppo_side = 'C';
	
	if(side == 'X')
	{
		oppo_side = 'O';
		side = 'C';
		count =0;
	}
	
   
    for(int i = 1; i <3; ++i)
    {
		place = (d+i)%3;
		if(ttt[s][place] != oppo_side )
		{
		if(ttt[s][place] == side)
		{
			++count;
			++possible_count;
		}
			else{
			++possible_count;
			fin_place = place;
			}
		}
		else{
			possible_count = 0 ;
			break;
			//Exit from This for loop only
		}
    }
    if(possible_count == 3 && count == 2 )
    {
		//printf("\n1For I:%d  j:%d invoked from place where value is putted I:%d  J:%d\n",s,d,s,fin_place);
		if(side == 'C')
		{
			ttt[s][fin_place] = side;
			print_mat(ttt);
			}
			else print_opo(ttt,s,fin_place);
		
    }
	else if(possible_count == 3 && count == 1 )
	{
		return 1;
	}
return 0;
}

int traverse_V(char **ttt , int s , int d,char side)
{
	char oppo_side;
	if(side == 'C')
	{
		oppo_side = 'O';
	}
	else 
	oppo_side = 'C';
	
     int count =1;
    int possible_count = 1;
    int place;
     int fin_place;
	 
	 if(side == 'X')
	{
		oppo_side = 'O';
		side = 'C';
		count =0;
	}
	
    for(int i = 1; i <3; ++i)
    {
	  place =(s+i)%3;
	if(ttt[place][d] != oppo_side)
	{
	  if(ttt[place][d] == side)
	   {
               ++count;
               ++possible_count;
           }
            else{
                ++possible_count;
                fin_place = place;
            }
        }
	else{
            possible_count = 0 ;
            break;
            //Exit from This for loop only 
        }
          
    }
    if(possible_count == 3 && count == 2 )
    {
		//printf("\n2For I:%d  j:%d invoked from place where value is putted I:%d  J:%d\n",s,d,fin_place,d);
		if(side == 'C')
		{
			ttt[fin_place][d] = side;
			print_mat(ttt);
		}
		else print_opo(ttt,fin_place,d);
    }
	else if(possible_count == 3 && count == 1 )
	{
		return 1;
	}
return 0;
}
int Cross(char **ttt , int s , int d,char side)
{
	char oppo_side;
	if(side == 'C')
	{
		oppo_side = 'O';
	}
	else 
	oppo_side = 'C';
	char current_side = side;
    int count =1;
    int possible_count = 1;
    int place1,place2;
    int fin_place1,fin_place2;
	int return_ = 0;
	if(side == 'X')
	{
		oppo_side = 'O';
		side = 'C';
		count =0;
	}
    if(s==d){
	for(int i = 1; i <3; ++i)
            {
                place1 =(s+i)%3;
                place2 =(d+i)%3;
                if(ttt[place1][place2] != oppo_side)
                {
                   if(ttt[place1][place2] == side)
                   {
                       ++count;
                       ++possible_count;
                   }
                    else{
                        ++possible_count;
                        fin_place1 = place1;
                        fin_place2 = place2;
                    }
                         
                        
                }
                else{
		    possible_count = 0 ;
                    break;
                    //Exit from This for loop only 
                }
                  
            }
            if(possible_count == 3 && count == 2 )
            {
				//printf("\n3For I:%d  j:%d invoked from place where value is putted I:%d  J:%d\n",s,d,fin_place1,fin_place2);
				if(side == 'C')
				{
                ttt[fin_place1][fin_place2] = side;
                print_mat(ttt);
				}else print_opo(ttt,fin_place1,fin_place1);
            }
			if(possible_count == 3 && count == 1 )
			{
				++return_;
			}
		}
    if(s==1 && d==1)
    {
             if(ttt[s-1][d+1] != oppo_side && ttt[s+1][d-1] != oppo_side )
             {
				if(ttt[s-1][d+1] == side || ttt[s+1][d-1] == side )
				{
					if(current_side == 'X')
					{
						return ++return_;
					}
					if(side == 'O')
					{
						if(ttt[s-1][d+1] == oppo_side)
						{
							print_opo(ttt,s-1,d+1);
						}
						if(ttt[s+1][d-1] == oppo_side)
						{
							print_opo(ttt,s+1,d-1);
						}
					}
					ttt[s][d] = side;
					ttt[s-1][d+1] = side;
					ttt[s+1][d-1] = side;
					print_mat(ttt);
				 }
				//else
				//{
				
				//}
	     }
    }
    if(s == 0 && d == 2){
         if(ttt[s+1][d-1] != oppo_side && ttt[s+2][d-2] != oppo_side )
          {
		if(ttt[s+1][d-1] == side || ttt[s+2][d-2] == side )
		{
			if(current_side == 'X')
			{
				return 1;
			}
			if(side == 'O')
			{
				if(ttt[s+1][d-1] == oppo_side)
				{
					print_opo(ttt,s+1,d-1);
				}
				if(ttt[s+2][d-2] == oppo_side)
				{
					print_opo(ttt,s+2,d-2);
				}
			}	
			ttt[s][d] = side;
			ttt[s+1][d-1] = side;
			ttt[s+2][d-2] = side;
			print_mat(ttt);
		 }
          }
    }
     if(s == 2 && d == 0){
          if(ttt[s-1][d+1] != oppo_side && ttt[s-2][d+2] != oppo_side )
           {
		if(ttt[s-1][d+1] == side || ttt[s-2][d+2] == side )
		{
			if(current_side == 'X')
			{
				return 1;
			}
			if(side == 'O')
			{
				if(ttt[s-1][d+1] == oppo_side)
				{
					print_opo(ttt,s-1,d+1);
				}
				if(ttt[s-2][d+2] == oppo_side)
				{
					print_opo(ttt,s-2,d+2);
				}
			}
			ttt[s][d] = side;
			ttt[s-1][d+1] = side;
			ttt[s-2][d+2] = side;
			print_mat(ttt);
		 }
	   }
     }

return 0;
}
void putx(char **ttt)
{
	if(ttt[1][1] != 'O' )
	{
		print_opo(ttt,1,1);
	}
	else{
	print_opo(ttt,2,2);
	}
}
void can_win(char **ttt , int s , int d, char side)
{	
	int i =0 ;
    i = traverse_H(ttt,s,d,side);
    i = traverse_V(ttt,s,d,side);
    i = Cross(ttt,s,d,side);
}
void searching_position(char **ttt,int s,int d,char side)
{
	int i = traverse_H(ttt,s,d,side)+traverse_V(ttt,s,d,side)+Cross(ttt,s,d,side);
	if(i >= 2)
	{
		print_opo(ttt,s,d);
	}
	if(i == 1)
	{
		source =s ;des = d;
	}
}
void Best_Selection(char **ttt, char side )
{
	int lines[8];
    for(int i =0 ; i<3 ;++i)
    {
	for(int j= 0 ; j<3 ; ++j ){
	    if(ttt[i][j] == side){
		if(side == 'X')
		{
			searching_position(ttt,i,j,side);
		}
		else
		can_win(ttt , i,j,side);
		/*		if(i == j)
				{
					can_win(ttt , i,j);
					//to be done
				}
				else if(lines[i] ==0 || lines[j+3] == 0)
				{
			can_win(ttt , i,j,side);
					lines[i] = 1;
				lines[j+3] = 1;
				}
				*/

		   }
	}
    }

}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char **ttt;
    char C = 'C';
    char X = 'X';
    char O = 'O';
    //clrscr();
    //printf("%d\t%d\t%d\n",C,X,O);
    //67-->C    88-->X	79-->O
    ttt = new char *[3];
    int i =0;
    for( i=0; i<3;++i)
     ttt[i] = new char[3];
	for( i=0; i<3;++i){
	    for(int j=0; j<3;++j){
	       scanf("%c",&ttt[i][j]);
		   while(ttt[i][j] != 67 && ttt[i][j] != 88 && ttt[i][j] != 79)
		   {
				scanf("%c",&ttt[i][j]);
		   }
		   
	    }
	}
	int change = 0;
	for( i=0; i<3;++i){
	    for(int j=0; j<3;++j){
		if(ttt[i][j] == 'X')
		change = 1;
			break;
		}
	}
	if(change != 1)
	{
		putx(ttt);
	}
	/*for( i=0; i<3;++i){
	    for(int j=0; j<3;++j){
	       printf("%c",ttt[i][j]);
	    }
	    printf("\n");
	}*/
    Best_Selection(ttt,'C');
	//For checking that C can win
	//printf("\nComputer Can't Win In this game\n Let's try to find out if Oponent can win if yes then Try to not let him Win \n");
	Best_Selection(ttt,'O');
	//Not letting O win
	//Here No one is winning so, searching for best place where computer can put 'X' 
	Best_Selection(ttt,'X');
	//printf("\nAt this point No one is winning\n");
	//source =s ;des = d;
	print_opo(ttt,source,des);
	//Best_Selection(ttt,'X');
 //   getch();
    return 0;
}
