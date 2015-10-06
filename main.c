#include "pa-1.h"
#include <stdio.h>
#include <string.h>

void text_output(int question_number, bool answer);

//
// This program is a driver to test the first assignment functions.
//  The first 4 are tested.
//
int main(int argc, char** argv)
{
  bool ans;
  int armstrong_test = 8;  // true
  char brackets[5] = "[[]]";  // true
  int perfect_test = 28; // true
  int rotate_test = 1234;
  int r = 1;
  int rotate_test_solution = 4123;
  int rotate_test_ans = 0;
  char pattern_test[] = "ana";
  char text_test[] = "ana ate the banana";
  int str_search_solution = 3;
  int str_search_ans =0;
  int collatz_count_ans = 0;
  int collatz_count_solution = 7;
  int collatz_test = 20;
  int f_array_test = 15;
  char string_1[6] = "HELLO";
  char string_2[3] = "hi";
  char string_result[10];
  char string_ans[10] = "hiHELLOhi";
  int num1=14, num2=13, num3=12;
  int ascending [3] = {0};
  int ascending_ans[3] = {12,13,14};
  int cube_sum_this_num = 54;


  printf("Testing functions:\n");


  //1
  ans = f_armstrong(armstrong_test);
  text_output(1, ans==true);

  //2
  ans = f_brackets(brackets);
  text_output(2, ans==true);

  //3
  ans = f_perfect(perfect_test);
  text_output(3, ans==true);

  //4
  rotate_test_ans = f_rotate(rotate_test,r);
  if(rotate_test_ans == rotate_test_solution)
  {
      ans = true;
  }
  else
  {
      ans = false;
  }
  text_output(4,ans);

  //5
  str_search_ans = f_str_search(&pattern_test, &text_test);
  if(str_search_ans == str_search_solution)
  {
      ans = true;
  }
  else
  {
      ans = false;
  }
  text_output(5,ans);

  //6
  collatz_count_ans = f_collatz_count(collatz_test);
    if(collatz_count_ans == collatz_count_solution)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    text_output(6,ans);

    //7
    text_output(7, ans);
    f_array(f_array_test);

    //8
    f_strings(&string_1, &string_2, &string_result);
    printf("The input strings were '%s' and '%s'.\n", string_1, string_2);
    printf("The answer should be '%s'\nYour answer is '%s'\n\n", string_ans, string_result);

    //9
    f_sort(num1, num2, num3, &ascending);
    if (ascending[0]==ascending_ans[0] && ascending[1]==ascending_ans[1] && ascending[2]==ascending_ans[2])
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    text_output(9,ans);

    //10
    if ((f_cubes_sum(cube_sum_this_num)[0] + f_cubes_sum(cube_sum_this_num)[1]) == cube_sum_this_num)
    {
        ans=true;
    }
    else
    {
        ans=false;
    }
    text_output(10,ans);
}

//
//  This function handles the output for the tests.
//
void text_output(int question_number, bool answer)
{
    printf("Question %d:\n", question_number);
    if(answer == true)
    {
        printf("   Passed!\n\n");
    }
    else
    {
        printf("   Failed!\n\n");
    }
}


