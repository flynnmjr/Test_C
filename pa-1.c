// add includes
#include "pa-1.h"
//#include <stdlib.h>

bool f_armstrong(int n)
{
    int mod_num=0,cnt=0,final_num=0; //variable declaration
    int val = 1; //val cannot be 0
    val = n; //set value to entered number so n does not change
    while (val != 0)//while loop to get the number of digits in the number
    {
        val = val/10; //dividing an int by 10 removes the decimal place
        cnt++; //counting digits until val reaches 0
    }

    val = n;
    while (val != 0)//while loop to check for a narcissistic number
    {
        mod_num = val%10; // modulus operator gives the individual digits
        val = val/10; //dividing by 10 removes the "number" so the count can continue and the next mod_num can be generated
        final_num = final_num + pow(mod_num, cnt); //provides the narcissistic number by adding itself to mod_num to the power of the cnt, which is the number of digits to match the requirements of
    }                                               //being a narcissistic number

    if (final_num == n)//if n and final_num match return true, else return false
    {
        return true;
    }
    else
    {
        return false;
    }
}

//2
bool f_brackets(char *e)
{
    int balancer=0; //balancer variable
    int  cnt=0; //standard counter
    for (cnt=0; *(e+cnt) != '\0'; cnt++) //for loop to count through the pointed array until the end of it at \0
    {
        if (*(e + cnt) == '[') //if the point in the array has a [ count up one
        {
            balancer++;
        }
        else
        {
            balancer--; //if the point in the array is anything other than a [, decrement one
        }
    }

    if (balancer == 0) // balancer should always be 0 if a set of [[]] is balanced.
        return true; //returns true if balanced (0)
    else
        return false; // returns false if unbalanced
}

//3
bool f_perfect(int x)
{
    int cnt = 1; //counter
    int sum = 0; //counts the sum
    while (sum < x) //loop runs while the current sum is less than the test variable
    {
      if (x%cnt == 0) //mods the test variable by the current count to get the next "proper" divisor
          sum = sum + cnt; //if the result ==0, then the cnt value is added to the sum

      cnt++; //counts up for each iteration, even if the divisor was not proper
    }

    // checks the sum to be equal to the given test value
    if(x == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//4
int f_rotate(int n, int r)
{

    int val = 0, digits=0,sub=0;

    int reversal[4] = {0};

    val = n; //set value to entered number so n does not change
    while (val != 0)//while loop to get the number of digits in the number
    {
        val = val/10; //dividing an int by 10 removes the decimal place
        digits++; //counting digits until val reaches 0
    }

    int i = digits;  //have i be the value of the number of digits without changing the original value.
    val = n; //use val as a placeholder so n does not change
    while (i != 0) //swhile loop
    {
        sub = val % 10; //use sub so val does not change
        reversal [--i] = sub; //puts each digit into the first array
        val = val / 10;
    }

    i = digits-1; //for use with language digits(0-3), not real number digits(1-4)
    int holder [4] ={0}; //new holding array
    for (; i>=0; i--) //for loop
    {
        if ((r+i) >= digits) //if the number of places to be switched + the place in the array >= the number of digits,
        {
            int temp = (r+i-digits); //adding them and subtracting the digits amounts to the correct spot to be rotated in the new array
            holder[temp] = reversal[i]; //place the value of the original number n, into the holding array rotated by temp number of places.
        }
        else
        {
            holder[i+r] = reversal[i]; //otherwise the rotation is simple, the values are rotated by r number of places.
        }
    }
    int final_num=0; //holds the rotated int
    int x = 0; //cannot place this in the for loop in C?
    int eths = digits-1; //enths will hold the place of
    for (; x <= (digits-1); x++) //for loop rotates through holder array
    {
        final_num = final_num + (holder[x] * (pow(10, (eths)))); //takes each value of the array, and multiplies it by 10^ eths to get 4000, 400, 40, 4, etc.
        eths--; //decrements after each iteration to add the thousands, hundreths, tenths, and ones columns of the number.
    }
    n=final_num;

  return n; //returns rotated number
}

int f_str_search(char *pattern, char *text)
{
    int occurrences=0, length_pattern=0, length_text=0, x=0, i=0, counter=0;
    length_pattern = strlen(pattern);
    length_text = strlen(text);

    for (; i <= length_text; i++)
    {

        for(x=0; x < length_pattern; x++)
        {

            if (pattern[x] == text[i])
            {
                counter++;
                break;
            }
            if (counter == length_pattern)
            {
                occurrences++;
                counter = 0;
            }



        }
    }

    return occurrences;
}
/*
//6
//int f_collatz_count(int n);

//7
//float f_array(int n);

//8
//void f_strings(char* s1, char* s2, char* s3);

//9
//void f_sort(int x, int y, int z, char* list);

//10
//
//char* f_cubes_sum(int n);
*/
