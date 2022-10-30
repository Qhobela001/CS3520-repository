/*
==================================================================================
Names : Qhobela B
Student # : 202004682
Program: A program to determine and print the first 10 reversable prime squares
==================================================================================
*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
# include<stdbool.h>

// A functiont that reverses an integer

int Reverse (int num)
{
	int remainder, Reverse = 0;
	while(num!=0)
	{
		remainder=num%10;
		Reverse = (Reverse * 10) + remainder;
		num = num/10;
	}
	return Reverse;
}


//Function to check if a number is prime or not...	
bool primeChecker(int num)
	{
		int i;
		
		bool isPrime = true;
		
		if(num==0 || num==1)		//neither 0 or 1 is prime
			{
				isPrime = false;
			}
		
		for(i=2; i<=(num)/2; i++)	//if the reminder of int num devided by i(in raange {2, num/2}) is not 0
			{
				if(num%i == 0)
					{
						isPrime=false;
						break;
					}
			}
			return isPrime;
	}

//function to check if the number is a perfect square or not
bool perfect_squre(int num)
{
	int i;
	for (i=1; i*i <= num; i++)
	{
		if ((num%i == 0) && (num/i == i))
		{
			return true;
		}
	}
	return false;
}

//function to check whether the reversed square number and original number are not the same
bool Palindrome(int num)
{
	bool isPalindrome = true;
	
	if(Reverse(num) == num)
		{
			isPalindrome = false;
		}
		return isPalindrome;
}


int main() 
{
	int j=0, x;
	int sqr_of_num, reverse_of_num, sqr_of_reverse_of_num;
	
	for(x=0; x>=0; x++)     //declaring x of range (0 - infinity)
		{
			int reverse_of_num = Reverse(x);		//reversing x and storing it in the reverse reversePrimeSquare
			
			if(perfect_squre(x) == true && perfect_squre(reverse_of_num) == true) //checking if both the prime square and its reverse are perfect squares
			{
				sqr_of_num = sqrt(x);
				sqr_of_reverse_of_num = sqrt(reverse_of_num);
				
				if (primeChecker(sqr_of_num) == true && primeChecker(sqr_of_reverse_of_num) == true)
				{
					if(Palindrome(x))
					{
						printf("%i \n", x);
						j++;
						if(j==10)
						{
							break;
						}
					}
				}
			}
		}
	return 0;
}