#include<stdio.h>
#include <stdlib.h> 
#include<time.h>

int no_throws=2;

//Function that rolls die and return outcome
int rollDice()
{
	return rand()%(6)+1;
}

int player_turn()
{
	int roll1,roll2,roll3,sum;
	char choice;
	//Hit enter
	printf("Player's Turn:(hit enter)");
	getchar();
	//roll two dies
	roll1=rollDice();
	roll2=rollDice();
	printf("You throw: %d,%d\n",roll1,roll2);
	sum=roll1+roll2;
	printf("The sum is: %d\n",sum);
	//ask for extra roll
	printf("Do you wish to throw again? [Y or N] N: ");
	scanf("%c",&choice);
	no_throws=2;
	//If human wants extra roll
	if(choice=='Y')
	{
		//Increment number of rows
		no_throws=3;
		printf("New Throw:\n");
		//roll die
		roll3=rollDice();
		printf("You throw: %d\n",roll3);
		sum=sum+roll3;
	}
	//If sum greater than 13 then score is 0
	sum=sum>13?0:sum;
	printf("Score for the round: %d\n",sum);
	//return score
	return sum;
}

//computers turn
int computer_turn()
{
	int roll1,roll2,roll3,sum;
	printf("Computer's Turn:(hit enter)");
	getchar();
	getchar();
	if(no_throws==2)
	{
		roll1=rollDice();
		roll2=rollDice();
		printf("Computer throws two dice\n");
		sum=roll1+roll2;
		printf("Computer throws: %d, %d; sum=%d\n", roll1, roll2, sum);
	}
	else if(no_throws==3)
	{
		roll1=rollDice();
		roll2=rollDice();
		roll3=rollDice();
		printf("Computer throws three dice\n");
		sum=roll1+roll2+roll3;
		printf("Computer throws: %d, %d, %d; sum = %d\n", roll1, roll2, roll3, sum);
	}
	return sum;
}

int main()
{
	srand(time(0)); 
	int i,human=0,computer=0, player_score, computer_score;
	//Do 7 rounds
	for(i=0;i<7;i++)
	{
		printf("Round %d\n",i+1);
		//get scores of human and computer
		player_score=player_turn();
		computer_score=computer_turn();
		//If human wins the round
		if(player_score>computer_score)
		{
			human++;
			printf("Player wins the round. human: %d. computer: %d\n",human,computer);
		}
		//computer wins the round
		else
		{
			computer++;
			printf("Computer wins the round. human: %d. computer: %d\n",human,computer);	
		}
	}
	//If human wins the game
	if(human>computer)
	{
		printf("The human wins the game!\n");	
	}
	else
	{
		printf("The Computer wins the game!\n");	
	}
	return 0;
}