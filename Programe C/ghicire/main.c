#include <stdio.h>

int main()
{

		 int mybday = 5;		 		 		 		 		 		 //declare variable to be guessed
		 int guess;		 		 		 		 		 		 		 //declare variable to store guessed date
		 int max = 31;		 		 		 		 		 		 		 //declare variable to test for invalid input
		 int min = 1;		 		 		 		 		 		 		 //declare variable to test for invalid input

		 printf("Try to guess the day of my Birthday: ");		 		 //display the intro and directions
		 scanf("%d",&guess);		 		 		 		 		 		 //`get the users guess and store it in thevariable guess

		 if (guess == mybday)
		 {
		 		 printf("You Win!!");		 		 		 		 		 //print you win if guess is correct
		 }
		 else if (guess < min)
		 {
		 		 printf("Thats NOT A DATE!!");		 		 		 		 //print `Error for invalid input
		 }
		 else if (guess > max)
		 {
		 		 printf("There isn't %d days in a month!",guess);		 //print Error for invalid input
		 }
		 else if (guess > mybday)
		 {
		 		 printf("Too High!");		 		 		 		 		 //print too high if guess is above answer
		 }
		 else if (guess < mybday)
		 {
		 		 printf("Too Low!");		 		 		 		 		 //print too low if guess is below answer
		 }
		 else
		 {
		 		 printf("Try again!!");		 		 		 		 		 //Print try again if guess if all else is not true (not possible)
		 }

		 return 0;
}
