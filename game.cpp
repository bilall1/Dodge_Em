//============================================================================
// Name        : game.cpp
// Author      : Hassan Mustafa and Muhammad Bilal
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...				
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<stdlib.h>
//==================================================================================================/
using namespace std;
int main(int argc, char*argv[]);
void GameDisplay();		//Declaring some global variables
void PrintableKeys(unsigned char key, int x, int y);
string lif_es;
int lifes=3;
int key=0;
int score=0;
int signal=0;
string scoree;
int counterfood=64;
int level=1;
float g_x = 330; // Your car
float g_y = 30; 	
float g_x1=470;	 //Opponent car.
float g_y1=30;
float g_x2=340;
float g_y2=230;
int speed_player=10;
int speed_opp=4;
int speed_opp2=8;
int min_x=40,max_x=750,max_y=750,min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
int min_ox=40,max_ox=750,max_oy=750,min_oy=30;//For opponent car.
int min_ox1=240,max_ox1=550,max_oy1=550,min_oy1=230;//For second car in level4.
int track_opp=1,track_player=1;
int track_opp2=3;
int food_x[64];
int food_y[64];
int x_food=62;
int y_food=50;
bool boolean=true;
bool restart=false;
//==================================================================================================/

void newgame()					// New game function.
{

	int main(int, char**);			//Calling main function to start new game.

}

//==================================================================================================/

void highscores()
{



}
//==================================================================================================/

void help()   //Displaying some set of rules.
{
glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
glClear (GL_COLOR_BUFFER_BIT); //Update the colors
DrawString( 340, 800, "DODGE'EM", colors[YELLOW]);

DrawString( 50, 600, "THERE ARE SOME SET OF RULES!!!", colors[MISTY_ROSE]);
DrawString( 50, 550, "YOU SHOULD DODGE THE OPPONENT CAR.", colors[MISTY_ROSE]);
DrawString( 50, 500, "PRESS SPACE BAR TO SPEED UP ", colors[MISTY_ROSE]);
DrawString( 50, 450, "OPPONENT MOVE IN ANY DIRECTION DEPENDING UPON LEVELS.", colors[MISTY_ROSE]);
DrawString( 50, 400, "FROM THREE LIFES.IF YOU HIT THE OPPONENT ONE LIFE IS LOST", colors[MISTY_ROSE]);
DrawString( 50, 350, "YOU HAVE BROWN CAR AND YOU MOVE CLOCKWISE", colors[MISTY_ROSE]);
DrawString( 50, 300, "YOU SHOULD PICKUP FOOD TO SCORE HIGH", colors[MISTY_ROSE]);
DrawString( 50, 250, "BEST OF LUCK!!!", colors[MISTY_ROSE]);
DrawString( 50, 150, "PRESS B TO GO BACK TO Menu", colors[MISTY_ROSE]);
}	
	


//==================================================================================================/

int exit()				//Program will exit without any function call.
{
	exit(1);
} 

//==================================================================================================/

void menu()
{
DrawString( 330, 800, "DODGE'EM", colors[YELLOW]);
DrawString( 50, 600, "1) Start a new game", colors[MISTY_ROSE]);
DrawString( 50, 500, "2) See high-scores", colors[MISTY_ROSE]);
DrawString( 50, 400, "3) Help", colors[MISTY_ROSE]);
DrawString( 50, 300, "4) Exit", colors[MISTY_ROSE]);
}

void menu2()
{
DrawString( 330, 800, "DODGE'EM", colors[YELLOW]);
DrawString( 50, 700, "0) Continue", colors[MISTY_ROSE]);
DrawString( 50, 600, "1) Start a new game", colors[MISTY_ROSE]);
DrawString( 50, 500, "2) See high-scores", colors[MISTY_ROSE]);
DrawString( 50, 400, "3) Help", colors[MISTY_ROSE]);
DrawString( 50, 300, "4) Exit", colors[MISTY_ROSE]);
}
void pausee()
{
	signal=0;
	boolean=false;
	key==51;
}

void cont()
{
signal=1;
}
//==================================================================================================/

void movement()					//Controllin movement of player.
{
		
			//Loop control.	
			
			if(g_x>=min_x && g_y<=min_y)		//Here min_x means maximum value of x axis and vice versa.
				g_x=g_x-speed_player;
			if(g_x<=min_x && g_y<=max_y )
				g_y=g_y+speed_player;
			if(g_x<=max_x && g_y>=max_y )
				g_x=g_x+speed_player;
			if(g_x>=max_x && g_y>=min_y)
				g_y=g_y-speed_player;
		
		
}
//==================================================================================================/

void opponent_follow_me()
{
	if(track_player<track_opp)
	{
		if(level==1)
		{
		 if((g_x1>=397 && g_x1<=497 ) && (g_y1==450 || g_y1==550 || g_y1==650))	//up
			{
			track_opp--;
			g_y1=g_y1+100;g_x1=g_x1-100;//To Avoid Double jump off opponent 
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			
			}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1== 130 || g_y1==230 || g_y1==330))	//down
			{
			track_opp--;
			g_y1=g_y1-100;g_x1=g_x1+100;//To Avoid Double jump off opponent
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			}
		}
		if(level==2 || level==3 || level==4)
		{
		if((g_y1>=397 && g_y1<=497) && (g_x1==140 || g_x1==240 || g_x1==340))		//right
			{
			track_opp--;
			g_x1=g_x1-100; g_y1=g_y1-100;//To Avoid Double jump off opponent
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			
			
			}
		else if((g_y1>=397 && g_y1<=497 ) && (g_x1==650 || g_x1==550 || g_x1==450))	//left
			{
			track_opp--;
			g_x1=g_x1+100;g_y1=g_y1+100;//To Avoid Double jump off opponent
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			
			}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1==450 || g_y1==550 || g_y1==650))	//up
			{
			track_opp--;
			g_y1=g_y1+100;g_x1=g_x1-100;//To Avoid Double jump off opponent
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			
			}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1== 130 || g_y1==230 || g_y1==330))	//down
			{
			track_opp--;
			g_y1=g_y1-100;g_x1=g_x1+100;//To Avoid Double jump off opponent
			min_ox=min_ox-100;max_ox=max_ox+100;
			min_oy=min_oy-100;max_oy=max_oy+100;
			}
		}
	}
	else if (track_player>track_opp)
	{
		if(level==1)
		{
		 if((g_x1>=397 && g_x1<=497 ) && (g_y1== 30 || g_y1==130 || g_y1==230))
				{
					track_opp++;
					g_y1=g_y1+100; g_x1=g_x1+100;//To Avoid Double jump off opponent
					min_ox=min_ox+100;max_ox=max_ox-100;
					min_oy=min_oy+100;max_oy=max_oy-100;
					
		
				}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1==550 || g_y1==650 || g_y1==750))  
				{
					track_opp++;
					g_y1=g_y1-100; g_x1=g_x1-100;							   
					min_ox=min_ox+100;max_ox=max_ox-100;
					min_oy=min_oy+100;max_oy=max_oy-100;					
				}
		}
		if(level==2 || level==3 || level==4)
		{
		if((g_y1>=397 && g_y1<=497) && (g_x1==750 || g_x1==650 || g_x1==550))
				{
					track_opp++;
					g_x1=g_x1-100; g_y1=g_y1+100;	//To Avoid Double jump off opponent
					min_ox=min_ox+100;max_ox=max_ox-100;
					min_oy=min_oy+100;max_oy=max_oy-100;
					
				}
	 	else if((g_y1>=397 && g_y1<=497 ) && (g_x1== 40 || g_x1==140 || g_x1==240))
				{
				track_opp++;
				g_x1=g_x1+100; g_y1=g_y1-100;	//To Avoid Double jump off opponent
				min_ox=min_ox+100;max_ox=max_ox-100;
				min_oy=min_oy+100;max_oy=max_oy-100;

				}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1== 30 || g_y1==130 || g_y1==230))
				{
					track_opp++;
					g_y1=g_y1+100; g_x1=g_x1+100;//To Avoid Double jump off opponent
					min_ox=min_ox+100;max_ox=max_ox-100;
					min_oy=min_oy+100;max_oy=max_oy-100;
					
		
				}
		else if((g_x1>=397 && g_x1<=497 ) && (g_y1==550 || g_y1==650 || g_y1==750))  
				{
					track_opp++;
					g_y1=g_y1-100; g_x1=g_x1-100;						   
					min_ox=min_ox+100;max_ox=max_ox-100;
					min_oy=min_oy+100;max_oy=max_oy-100;					
				}
		}
	}
}


void opponent_follow_me2()
{
	if(track_opp2>track_player)
	{
		
		if(level==4)
		{
		if((g_y2>=397 && g_y2<=497) && (g_x2==140 || g_x2==240 || g_x2==340))
			{
			track_opp2--;
			g_x2=g_x2-100; g_y2=g_y2-100;		//To Avoid Double jump off opponent
			min_ox1=min_ox1-100;max_ox1=max_ox1+100;
			min_oy1=min_oy1-100;max_oy1=max_oy1+100;
			
			}
		else if((g_y2>=397 && g_y2<=497 ) && (g_x2==650 || g_x2==550 || g_x2==450))
			{
			track_opp2--;
			g_x2=g_x2+100;g_y2=g_y2+100;		//To Avoid Double jump off opponent
			min_ox1=min_ox1-100;max_ox1=max_ox1+100;
			min_oy1=min_oy1-100;max_oy1=max_oy1+100;
			
			}
		else if((g_x2>=397 && g_x2<=497 ) && (g_y2==450 || g_y2==550 || g_y2==650))
			{
			track_opp2--;
			g_y2=g_y2+100;g_x2=g_x2-100;		//To Avoid Double jump off opponent
			min_ox1=min_ox1-100;max_ox1=max_ox1+100;
			min_oy1=min_oy1-100;max_oy1=max_oy1+100;
			
			}
		else if((g_x2>=397 && g_x2<=497 ) && (g_y2== 130 || g_y2==230 || g_y2==330))
			{
			track_opp2--;
			g_y2=g_y2-100;g_x2=g_x2+100;		//To Avoid Double jump off opponent
			min_ox1=min_ox1-100;max_ox1=max_ox1+100;
			min_oy1=min_oy1-100;max_oy1=max_oy1+100;
			}
		}
	}
	else if (track_opp2<track_player)
	{
	
		if(level==2 || level==3 || level==4)
		{
		if((g_y2>=397 && g_y2<=497) && (g_x2==750 || g_x2==650 || g_x2==550))
				{
					track_opp2++;
					g_x2=g_x2-100; g_y2=g_y2+100;	//To Avoid Double jump off opponent
					min_ox1=min_ox1+100;max_ox1=max_ox1-100;
					min_oy1=min_oy1+100;max_oy1=max_oy1-100;
					
				}
	 	else if((g_y2>=397 && g_y2<=497 ) && (g_x2== 40 || g_x2==140 || g_x2==240))
				{
				track_opp2++;
				g_x2=g_x2+100; g_y2=g_y2-100;		//To Avoid Double jump off opponent
				min_ox1=min_ox1+100;max_ox1=max_ox1-100;
				min_oy1=min_oy1+100;max_oy1=max_oy1-100;

				}
		else if((g_x2>=397 && g_x2<=497 ) && (g_y2== 30 || g_y2==130 || g_y2==230))
				{
					track_opp2++;
					g_y2=g_y2+100; g_x2=g_x2+100;	//To Avoid Double jump off opponent
					min_ox1=min_ox1+100;max_ox1=max_ox1-100;
					min_oy1=min_oy1+100;max_oy1=max_oy1-100;
					
		
				}
		else if((g_x2>=397 && g_x2<=497 ) && (g_y2==550 || g_y2==650 || g_y2==750))  
				{
					track_opp2++;			//To Avoid Double jump off opponent
					g_y2=g_y2-100; g_x2=g_x2-100;							   
					min_ox1=min_ox1+100;max_ox1=max_ox1-100;
					min_oy1=min_oy1+100;max_oy1=max_oy1-100;					
				}
		}
	}
}
//==================================================================================================/

void movementopp()					//Controllin movement of player.
{
	if(level==3 || level==4)
	{
	speed_opp=8;
	}
		
			if(g_x1<=max_ox && g_y1<=min_oy)		
			g_x1=g_x1+speed_opp;
			if(g_x1>=max_ox && g_y1<=max_oy )
			g_y1=g_y1+speed_opp;
			if(g_y1>=max_oy && g_x1>=min_ox)
			g_x1=g_x1-speed_opp;
			if(g_x1<=min_ox && g_y1>=min_oy)
			g_y1=g_y1-speed_opp;
}

void movementopp2()					//Controllin movement of player.
{

			if(g_x2<=max_ox1 && g_y2<=min_oy1)		
			g_x2=g_x2+speed_opp2;
			if(g_x2>=max_ox1 && g_y2<=max_oy1 )
			g_y2=g_y2+speed_opp2;
			if(g_y2>=max_oy1 && g_x2>=min_ox1)
			g_x2=g_x2-speed_opp2;
			if(g_x2<=min_ox1 && g_y2>=min_oy1)
			g_y2=g_y2-speed_opp2;
}
//==================================================================================================/

void fooddisplay()
{
	for(int i=0; i<64; i++)			//x axis cordinates of food in array
		{
		food_x[i]=x_food;
		if(x_food==762){
		x_food=62;
		}
		else
		x_food+=100;		
	        }
	
	int counter=0;
	for(int i=0; i<64; i++)			//y axis cordinates of food in array
	{	

		if(counter==8)
		{
		y_food+=105;
		counter=0;
		}
		counter++;
		food_y[i]=y_food;		
	
	}

}

//==================================================================================================/

void food_eat()
{
	//Food
	for (int i=0; i<64; i++)
	DrawLine( food_x[i] , food_y[i] , food_x[i]+14  , food_y[i] , 10 , colors[PINK] );
	int i=0;
	while (i<64)
	{	if (   ((g_x<=food_x[i]+25) && (g_x>=food_x[i]-25))   &&    ((g_y<=food_y[i]+45) && (g_y>=food_y[i]-45))    )
		{	food_x[i]=-30;
			food_y[i]=-30;
			counterfood--;
			score+=10;
			cout<<"\a"<<endl;		//beep sound
			scoree=Num2Str(score);	//Function from util.cpp
		}
	i++;

	}
}


//==================================================================================================/

void car_vs_car()
{
	if(  ((g_x<=g_x1+25) && (g_x>=g_x1-25))  && ((g_y<=g_y1+25) && (g_y>=g_y1-25)) )
		{
			if(lifes>0)
			{
				g_x = 330; // Your car
				g_y = 30; 	
				g_x1=470; //Opponent car.
				g_y1=30;
				sleep(2);
				lifes--;
				min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
				min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
				x_food=62; y_food=50;
				track_opp=1;
				track_player=1;
				track_opp2=3;
				if(lifes>=1)
					{
					fooddisplay();
					counterfood=64;
					}
				
			}
			else
			{
			g_x = 330; // Your car
			g_y = 30; 	
			g_x1=470; //Opponent car.
			g_y1=30;
			}
		}

}

void car_vs_car2()
{
	if(  ((g_x<=g_x2+25) && (g_x>=g_x2-25))  && ((g_y<=g_y2+25) && (g_y>=g_y2-25)) )
		{
			if(lifes>0)
			{
				g_x = 330; // Your car
				g_y = 30; 	
				g_x1=470; //Opponent car.
				g_y1=30;
				g_x2=340;
				g_y2=230;
				sleep(2);
				lifes--;
				min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
				min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
				min_ox1=240,max_ox1=550,max_oy1=550,min_oy1=230;//For second car in level4.
				x_food=62; y_food=50;
				track_opp=1;
				track_player=1;
				track_opp2=3;
				if(lifes>=1)
					{
					fooddisplay();
					counterfood=64;
					}
				
			}
			else
			{
			g_x = 330; // Your car
			g_y = 30; 	
			g_x1=470; //Opponent car.
			g_y1=30;
			g_x2=340;
			g_y2=230;
			}
		}

}
//==================================================================================================/

void messeges()
{	
	lif_es=Num2Str(lifes);		//Variables for lives	
	DrawString( 600, 800, "Lifes = ", colors[MISTY_ROSE]); // score
	DrawString( 700, 800, lif_es, colors[MISTY_ROSE]); // lives	
	if(lifes==0)
	{
		DrawString( 350, 460 , "Game Over !!!", colors[MISTY_ROSE]); // score	
	}
}

void level2()
{
			level=2;		
			g_x = 330; // Your car
			g_y = 30; 	
			g_x1=470; //Opponent car.
			g_y1=30;
			DrawString( 350, 460 , "LEVEL 2 !!!", colors[RED]); // score
			min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
			min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
			x_food=62; y_food=50;
			sleep(1);
			track_opp=1;
			track_player=1;
			track_opp2=3;
			if(lifes>=1)
			{
			fooddisplay();
			counterfood=64;
			}

}

void level3()
{

			level=3;	
			g_x = 330; // Your car
			g_y = 30; 	
			g_x1=470; //Opponent car.
			g_y1=30;
			glClear (GL_COLOR_BUFFER_BIT); //Update the colors.
			DrawString( 350, 460 , "LEVEL 3 !!!", colors[RED]); // score
			min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
			min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
			x_food=62; y_food=50;
			track_opp=1;
			track_player=1;
			track_opp2=3;
			sleep(1);
			if(lifes>=1)
			{
			fooddisplay();
			counterfood=64;
			}
}

void level4()
{
	
			level=4;	
			g_x = 330; // Your car
			g_y = 30; 	
			g_x1=470; //Opponent car.
			g_y1=30;
			glClear (GL_COLOR_BUFFER_BIT); //Update the colors.
			DrawString( 350, 460 , "LEVEL 3 !!!", colors[RED]); // score
			min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
			min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
			x_food=62; y_food=50;
			track_opp=1;
			track_player=1;
			track_opp2=3;
			sleep(1);
			if(lifes>=1)
			{
			fooddisplay();
			counterfood=64;
			}
			
}
//==================================================================================================/
/*void clear()
{
glClear (GL_COLOR_BUFFER_BIT); //Update the colors
}*/
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
 
//==================================================================================================/

 
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

//==================================================================================================/

/*
 * Main Canvas drawing function.
 * */
//Board *b;

void GameDisplay()/**/{
if(signal==0 && boolean==true)
	{
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	menu();
	}

if(signal==1)
{
	if(counterfood==0 && lifes>=1 && level==1)
		{	
			
		level2();
		}
	if(counterfood==0 && lifes>=1 && level==2)
		{	
		level3();
		}	
		
	if(counterfood==0 && lifes>=1 && level==3)
		{	
		level4();
		}
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors.
	
//==================================================================================================/
	food_eat();	//Calling food function.
	movement();	//Calling movement function 
	opponent_follow_me();//Opponent car to follow you.
	movementopp();	//Opponent movement
	
	if(level==4)
	{
		movementopp2();
	}
	if(level==4)
	{
		opponent_follow_me2();
	}
	car_vs_car();	//Car vs Car.
	
	if(level==4)
	{
		car_vs_car2();
	}
	messeges();	//Calling messeges function to display score and lifes
		
//==================================================================================================/	
	
	if (lifes<1 || restart==true)
		{
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		DrawString( 150, 700, "YOU LOST!!! BETTER LUCK NEXT TIME!!!", colors[MISTY_ROSE]); // scores
				g_x = 330; // Your car
				g_y = 30; 	
				g_x1=470; //Opponent car.
				g_y1=30;
				sleep(2);
				min_x=40;max_x=750;max_y=750;min_y=30; //lOOP CONTROL IN MOVEMENT for players car.
				min_ox=40;max_ox=750;max_oy=750;min_oy=30;//For opponent car.
				min_ox1=240,max_ox1=550,max_oy1=550,min_oy1=230;//For second car in level4.
				x_food=62; y_food=50;
				fooddisplay();
				counterfood=64;
				level=1;
				lifes=3;
				key=0;
				score=0;
				signal=0;
				track_opp=1;
				speed_opp=4;
				track_player=1;
				track_opp2=3;
				boolean=true;
				
		
		}
	else {
		DrawString( 40, 800, "Score = ", colors[MISTY_ROSE]);
		DrawString( 140, 800, scoree, colors[MISTY_ROSE]); // score


//==================================================================================================/
	
	// Drawing opponent car
	
	float width = 10; 
	float height = 10;
	float* color = colors[BLUE]; 
	float radius = 5.0;
	DrawRoundRect(g_x1,g_y1,width,height,color,radius); // bottom left tyre
	DrawRoundRect(g_x1+width*3,g_y1,width,height,color,radius); // bottom right tyre
	DrawRoundRect(g_x1+width*3,g_y1+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(g_x1,g_y1+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(g_x1, g_y1+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(g_x1+width, g_y1+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(g_x1+width*3, g_y1+height*2, width, height, color, radius/2); // body right rect


if(level==4)
{
	float width = 10; 
	float height = 10;
	float* color = colors[BLUE]; 
	float radius = 5.0;
	DrawRoundRect(g_x2,g_y2,width,height,color,radius); // bottom left tyre
	DrawRoundRect(g_x2+width*3,g_y2,width,height,color,radius); // bottom right tyre
	DrawRoundRect(g_x2+width*3,g_y2+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(g_x2,g_y2+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(g_x2, g_y2+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(g_x2+width, g_y2+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(g_x2+width*3, g_y2+height*2, width, height, color, radius/2); // body right rect
}
	//Drawing my car.
	
	width = 10; 
	height = 10;
	color = colors[BROWN]; 
	radius = 5.0;
	DrawRoundRect(g_x,g_y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(g_x+width*3,g_y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(g_x+width*3,g_y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(g_x,g_y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(g_x, g_y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(g_x+width, g_y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(g_x+width*3, g_y+height*2, width, height, color, radius/2); // body right rect

//==================================================================================================/

	// Drawing Arena
	int gap_turn = 130;
	int sx = 20;
	int sy = 10;
	int temp=800;
	int swidth = temp/2 - gap_turn/2; // half width
	int sheight = 10;
	float *scolor = colors[YELLOW];
	
		for(int i=1;i<=5;i++)
		{
				DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
				DrawRectangle(sx + swidth + gap_turn, sy, swidth+sheight*2, sheight, scolor); // bottom right
				DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*2, swidth, scolor); // right down
				DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*2, swidth+sheight, scolor); //right
				DrawRectangle(sx + swidth + gap_turn, sy+(temp+10), swidth, sheight, scolor); // top left
				DrawRectangle(sx, sy+(temp+10), swidth, sheight, scolor); // top right
				DrawRectangle(sx-sheight*2, sy+sheight+swidth+gap_turn, sheight*2, swidth+sheight, scolor); // left up
				DrawRectangle(sx-sheight*2, sy+sheight, sheight*2, swidth, scolor); // left down
				if(i!=4)
				{	sx+=100;
					sy+=100;
					temp-=200;
					swidth = temp/2 - gap_turn/2;
				}
				else
				{
					gap_turn=0;
					sx+=75; sy+=80;
					temp-=150;
					swidth = temp/2 - gap_turn/2;
					sheight = 5;
				}
		}
	
	

		}		
	}		
	glutSwapBuffers(); // do not modify this line.. or draw anything below this line
}



void NonPrintableKeys(int key,int x,int y) {

//left
	if (key== GLUT_KEY_LEFT  ) {
			if((g_y>=325 && g_y<=497) && (g_x==750 || g_x==650 || g_x==550))
			{
			track_player++;
			g_x=g_x-100;
			min_x=min_x+100;max_x=max_x-100;
			min_y=min_y+100;max_y=max_y-100;
			
			}
			else if((g_y>=325 && g_y<=497) && (g_x==140 || g_x==240 || g_x==340))
			{
			track_player--;
			g_x=g_x-100;
			min_x=min_x-100;max_x=max_x+100;
			min_y=min_y-100;max_y=max_y+100;
			}
//right		
	} else if (key== GLUT_KEY_RIGHT  )
	{
			if((g_y>=325 && g_y<=497 ) && (g_x== 40 || g_x==140 || g_x==240))
			{
			track_player++;
			g_x=g_x+100;
			min_x=min_x+100;max_x=max_x-100;
			min_y=min_y+100;max_y=max_y-100;
			
			}
			else if((g_y>=325 && g_y<=497 ) && (g_x==650 || g_x==550 || g_x==450))
			{
			track_player--;
			g_x=g_x+100;
			min_x=min_x-100;max_x=max_x+100;
			min_y=min_y-100;max_y=max_y+100;
		
			}

	}
//Up
	 else if (key== GLUT_KEY_UP) 
	{
			if((g_x>=325 && g_x<=497 ) && (g_y== 30 || g_y==130 || g_y==230))
			{
			track_player++;
			g_y=g_y+100;
			min_x=min_x+100;max_x=max_x-100;
			min_y=min_y+100;max_y=max_y-100;
			
			}
			else if((g_x>=325 && g_x<=497 ) && (g_y==450 || g_y==550 || g_y==650))
			{
			track_player--;
			g_y=g_y+100;
			min_x=min_x-100;max_x=max_x+100;
			min_y=min_y-100;max_y=max_y+100;
			
			}
//down.
	}
	else if (key== GLUT_KEY_DOWN ) 
	{
			if((g_x>=325 && g_x<=497 ) && (g_y==550 || g_y==650 || g_y==750))  
			{
			track_player++;
			g_y=g_y-100;							   
			min_x=min_x+100;max_x=max_x-100;
			min_y=min_y+100;max_y=max_y-100;
			
			}
			else if((g_x>=325 && g_x<=497 ) && (g_y == 130 || g_y==230 || g_y==330))
			{
			track_player--;
			g_y=g_y-100;
			min_x=min_x-100;max_x=max_x+100;
			min_y=min_y-100;max_y=max_y+100;
			
			}
		
	}
		
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}
	if(key == 49 )
	{
	signal=1;
	}
	if(key== 50)
	{
	highscores();
	}
	if(key==51)
	{
	lifes=0;
	boolean=false;
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	help();
	}
	if(key==52)
	{
	exit(1);
	}
	if (key == 'b' || key == 'B')
	{
	boolean=true;
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	menu();

	}
	if (key == 'p' || key == 'P')
	{

	
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	pausee();
	menu2();
	}
	if(key==48)
	{
	cont();
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	glutPostRedisplay();

	// once again we tell the library to call our Timer function after next 1000/FPS	
	glutTimerFunc(30.0, Timer, 0);
	
	
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {
	fooddisplay();
	//b = new Board(60, 60); // create a new board object to use in the Display Function ..
	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
