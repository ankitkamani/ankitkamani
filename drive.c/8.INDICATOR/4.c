/*4. Program to find length of string using pointer*/

#include<stdio.h>
#include<conio.h>

int string_ln(char*);

int main()
{
   char str[20];
   int length;

   printf("Enter any string :: ");
   scanf("%s",str);

   length = string_ln(str);
   printf("\nThe length of the given string [ %s ] is : %d\n", str, length);

  return 0;
}

int string_ln(char*p)
{
   int count = 0;
   while (*p != '\0') {
      count++;
      p++;
   }
   return count;
}