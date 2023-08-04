#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int random(int mini, int maxi)
{
	bool isFirst = true;
	if(isFirst)
	{
		//Seed the random number generator with the current time
    	srand(static_cast<unsigned int>(time(0))); 
	}
	return mini+rand() % (maxi-mini+1);
}

int dice()
{
	return random(1,6);
}
int main()
{
//	int ladder[] = {5,20,35,50,63,81,94};
//	int snake[] = {15,29,37,52,68,77,85,98};
	bool first = false;
	bool second = false;
	pair<int, int> ladder[] = {{4,25},{21,39},{29,74},{43,76},{63,80}, {71,97}};
	pair<int, int> snake[] = {{30,7},{47,15},{56,19},{73,51},{82,42},{92,75},{98,55}};
	
	string str;
	int board = 100;	// size of 100 (1-100 numbers on board)
	int maxPlayer = 2;
	bool gameOver = false;
	int current[maxPlayer] = {0}; // Starting position for both players is 0;
	int player = 0;
	
	while(str != "start")
	{
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t\t     **SNAKE AND LADDER GAME**" << endl;
		cout << "\n\t\t         **RULES OF THE GAME** " << endl;
		cout << "\t\t    1. Game Starts when a player got a six." << endl;
		cout << "\t\t    2. If your counter lands at the bottom of a ladder, you can move up to the top of the ladder" << endl;
		cout << "\t\t    3. If your counter lands on the head of a snake, you must slide down to the bottom of the snake.\n" << endl;
		cout << "\n\t To Start the Game , type 'start' in lowercase : ";
		cin >> str;
	}
	while(!gameOver)
	{
		system("cls");
		cout << "\n\n" << endl;
		cout << "\t\t     **SNAKE AND LADDER GAME**" << endl;
		cout << "\n\t\t         **RULES OF THE GAME** " << endl;
		cout << "\t\t    1. Game Starts when a player got a six." << endl;
		cout << "\t\t    2. If your counter lands at the bottom of a ladder, you can move up to the top of the ladder" << endl;
		cout << "\t\t    3. If your counter lands on the head of a snake, you must slide down to the bottom of the snake." << endl;
		cout << "\n\t\t\t Current Player " << player+1 << endl;
		cout << "\t\t\t-----------------------------" << endl;
		cout << "\t\t\t Player : " << player+1 << " rolled a " << dice() << endl;
		cout << "\t\t\t-----------------------------" << endl << endl;
		if((player+1) == 1 && first == false)
		{
			if(dice() == 6) {
				current[player] = 1;
				cout << "\n\t\t\t **Player " << player+1 << " enters the game** \n" << endl;
				first = true;
			}
			else{
				current[player] = 0;
			}
		}
		else if((player+1) == 1 && first == true)
		{
			if(current[player] + dice() <= 100){
				current[player] += dice();	
			}
		}
		else if((player+1) == 2 && second == false)
		{
			if(dice() == 6) {
				current[player] = 1;
				cout << "\n\t\t\t **Player " << player+1 << " enters the game** \n" << endl;
				second = true;
			}
			else{
				current[player] = 0;
			}
		}
		else if((player+1) == 2 && second == true)
		{
			if(current[player] + dice() <= 100){
				current[player] += dice();	
			}
		}
			
		cout << "\t\t\t-----------------------------" << endl;
		for(int i = 0; i < maxPlayer; i++)
		{
			cout << "\t\t\t Player " << i+1 << " is at position : " << current[i] << endl;
		}
		cout << "\t\t\t-----------------------------" << endl << endl;
		
		if(current[player] == board)
		{
			cout << "\n\n\t\t\t **Player " << player+1 << " wins** " << endl << endl;
			gameOver = true;
		}
		int size = sizeof(ladder)/ sizeof(ladder[0]);
		for(int i = 0; i < size; i++)
		{
			if(current[player] == ladder[i].first)
			{
				cout << endl;
				cout << "\t\t\t Player " << player+1 << " climbed a ladder " << endl << endl;
				cout << "\t\t\t     "<<ladder[i].second << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |__|" << endl;
				cout << "\t\t\t    |  |" << endl;;
				cout << "\t\t\t     "<<ladder[i].first << endl;
				cout << endl;
				current[player] = ladder[i].second;
			}
		}
		
		size = sizeof(snake)/ sizeof(snake[0]);
		for(int i = 0; i < size; i++)
		{
			if(current[player] == snake[i].first)
			{
				cout << endl;
				cout << "\t\t\t Player " << player+1 << " is bitten by snake " << endl << endl;
				cout << "\t\t\t      "<<snake[i].first << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      |" << endl;
				cout << "\t\t\t      V" << endl;
				cout << "\t\t\t      "<<snake[i].second << endl;
				cout << endl;
				current[player] = snake[i].second;
			}
		}
		player = (player+1) % maxPlayer; // turn of players changes alternatively;
		cout << endl;
		system("pause"); // pause after one turn
	}
	return 0;
}
