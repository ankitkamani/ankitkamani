/*3. C program to write even, odd and prime numbers to separate file.*/

#include <stdio.h>
#include <stdlib.h>

int isEven(const int NUM);
int isPrime(const int NUM);


void main()
{
    FILE * fPtrIn,
         * fPtrEven, 
         * fPtrOdd, 
         * fPtrPrime;

    
    int num, success;

    fPtrIn   = fopen("numbers.txt", "r");
    fPtrEven = fopen("even-numbers.txt" , "w");
    fPtrOdd  = fopen("odd-numbers.txt"  , "w");
    fPtrPrime= fopen("prime-numbers.txt", "w");

    if(fPtrIn == NULL || fPtrEven == NULL || fPtrOdd == NULL || fPtrPrime == NULL)
    {
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read/write privilege.\n");
        exit(EXIT_FAILURE);
    }

    printf("File opened successfully. Reading integers from file. \n\n");

    while (fscanf(fPtrIn, "%d", &num) != -1)
    {
    
        if (isPrime(num))
            fprintf(fPtrPrime, "%d\n", num);
        else if (isEven(num))
            fprintf(fPtrEven, "%d\n", num);
        else
            fprintf(fPtrOdd, "%d\n", num);

    }

    fclose(fPtrIn);
    fclose(fPtrEven);
    fclose(fPtrOdd);
    fclose(fPtrPrime);

    printf("Data written to files successfully.");

}


int isEven(const int NUM)
{
    return !(NUM & 1);
}


int isPrime(const int NUM)
{
    int i;  
    if (NUM < 0)
        return 0;
      
    for ( i=2; i<=NUM/2; i++ )    
    {    
        if (NUM % i == 0)    
        {  
            return 0;  
        }    
    }   
      
    return 1;  
}