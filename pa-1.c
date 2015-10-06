// add includes
#include "pa-1.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

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

//5
int f_str_search(char *pattern, char *text)
{
    int occurrences=0, length_pattern=0, length_text=0, x=0, i=0, counter=0; //variable declaration
    length_pattern = strlen(pattern); //sets the length of the pattern searching for to an int value
    length_text = strlen(text); //sets the length of the text to be searched to an int value

    for (; i <= length_text; i++) //for loop counting along the text length
    {

        for(x=0; x < length_pattern; x++) //for loop counting the pattern length
        {
            if (counter == length_pattern) //if the counter value is equal to the length of the pattern, it counts as 1 occurence of the pattern
            {
                occurrences++; //total number of occurences
                counter = 0; //resets the counter value
            }
            if (pattern[x] == text[i]) //if the pattern value is equal to the text being searched value, the counter goes up by one
            {
                counter++; //counter
                break; //if statement ends when a match is found.
            }

        }
    }

    return occurrences; //returns total number of occurrences.
}

//6
int f_collatz_count(int n)
{
    int count=0; //count starts at 0

    do //want it to loop at least once
    {
        if (n % 2 == 1) //determine if the number is odd by modulus
        {
            n = (n*3)+1; //multiply by 3 and add by one
            count++; //count up
        }
        if (n % 2 == 0) //determine if number is even by modulus
        {
            n = n/2; //divide n by 2
            count++; //count up
        }
    } while (n > 1); //when n reaches one the count stops

    return count; //return final count value
}

//7
float f_array(int n)
{
    int a[n]; //array with size n integers
    int i=0; //initialize for for loop
    double average=0, counter=0, avg_count=0;; //variables for counting
    int length = n-1; //length  of array
    srand(time(NULL)); //seed for random numbers using system time
    for(i=0; i < n; i++) //for loop populating the array
    {
        int r = rand() % 99; //random number between 0-100
        a[i] = r; //element in array takes a random number
        a[i] = a[i] * 2; //multiplies each element by 2
    }

    for(i=0; i < n; i++)//loop to iterate through array
    {
        if (a[i] % 3 == 0 && counter < 5) //if element is divisible by 3, for the first 5 numbers that are divisible by 3
        {
            avg_count = avg_count + a[i]; //add the element to the average
            counter++; //count up
        }
    }

    average = avg_count/counter; //average is the average / the counter variable
    printf("The final count is %g from %g values.\nThe average of these values is %g / %g = %g\n\n", avg_count, counter, avg_count, counter, average);
}

//8
void f_strings(char* s1, char* s2, char* s3)
{
    int s1_length = strlen(s1); //gets the length of strings and captures it in an int
    int s2_length = strlen(s2);
    int i=0; //counter that cant be declared in for loops
    char string1_copy [s1_length]; //copy of the strings
    char string2_copy [s2_length];
    char* string_extended = malloc((s1_length*2+s2_length*2)); //making a a large string that can fit at most every string that could be put in it.

    if (s1_length > 50 || s2_length > 50 || s1_length==s2_length) //stop the function if the strings are equal in length or are greater than 50 characters
    {
        printf("Warning: Strings must be of length 50 characters or less, and not of equal length.\n");
        return;
    }
    if (s1_length < s2_length) //if string 2 is longer
    {
        for (; i < s1_length; i++) //copy string one into string copy
        {
            string1_copy[i] = s1[i];
        }
        strcpy(string_extended, s1); //copy s1 into string extended
        strcat(string_extended, s2); //copies s2 (longer) in the middle
        strcat(string_extended, s1); //puts another s1 at the end to create the syntax <v><w><v>
    }
    else
    {
        for (i=0; i < s2_length; i++) //does the same as above if s1 is longer
        {
            string2_copy[i] = s2[i];
        }
        strcpy(string_extended, s2);
        strcat(string_extended, s1);
        strcat(string_extended, s2);
    }

    strcpy(s3, string_extended); //copies string extended to s3
    return s3; //returns s3


}

//9
void f_sort(int x, int y, int z, int* list)
{
    if (x<y && x<z) //if statements for the 6 possible combinations of any 3 numbers mixed up
    {
        list[0] = x;  //if x is smallest, set to the first number in the list
        if (y>x && y<z)
        {
            list[1] = y; //if y is smaller than z, set y to second in list
            list[2] = z; //and z to third

        }
        else if (y>x && y>z)
        {
            list[1] = z; //if z is larger, set z to second
            list[2] = y; //and y to third
        }
    }

    if (y<x && y<z)
    {
        list[0] = y; //if y is the smallest of the three, set it to the first in the list
        if (x>y && x<z)
        {
            list[1] = x; //if x is smaller than z, set to the second in the list
            list[2] = z; //and z to the third
        }
        else if (x>y && x>z)
        {
            list[1] = z; //if z is larger than x set to second in the list
            list[2] = x; //and x to the third
        }
    }

    if (z<x && z<y)
    {
        list[0] = z; //if z is the smallest number set it to first in the list
        if (x>z && x<y)
        {
            list[1] = x; //if x is smaller than y set it to second in the list
            list[2] = y; //and set y to the third
        }
        else if (y>z && y<x)
        {
            list[1] = y; //if y is smaller than x set it to second in the list
            list[2] = x; //and set x to the third
        }
    }


    return; //return the function with the values in the correct order
}

//10

char* f_cubes_sum(int n)
{
    int a=0,i=0,temp=0, x=0,y=0;
    int a_holder[15]={0};
    int b_holder[15] ={0};

    for(a; pow(a,3)<n; a++)
    {
        temp = pow(a,3);
        a_holder[i]=temp;
        b_holder[i++]=temp;
    }

    char *arr_return = (int *)malloc(2*sizeof(int));
    for (x; x<i; x++)
    {
        for(y=0; y<i; y++)
        {
            if(a_holder[x] + b_holder[y] == n)
            {
                arr_return[0] = a_holder[x];
                arr_return[1] = b_holder[y];
            }
        }
    }

    if (arr_return[0]+arr_return[1] != n)
    {
        arr_return[0] = NULL;
        arr_return[1] = NULL;
    }
    return arr_return;
}

