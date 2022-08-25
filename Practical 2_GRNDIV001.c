#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Defined constants*/
#define TITLE "DECIMAL TO RADIX-i converter"     //#define defines constant values for a given variable
#define AUTHOR "Divan Grundlingh"                //strings are quoted " " and integers are just inserted as is
#define YEAR 2022

int main() {
    
    printf("*****************************\n");                         //prints each text on a new line using \n
    printf(" %s\n Written by: %s\n Date: %d\n", TITLE, AUTHOR, YEAR);  //instead having a printf() for each line, we can add all the lines into 1 printf() using \n. Strings are printed using the %s specifier and integers using %d.
    printf("*****************************\n");
    
    int decV=0, radix;                               //initialising variable decV and radix as an integer, decimal value = 0  to actually start the while loop
    while(decV >= 0){                               //while loop that only loops if decimal value >= 0
        printf("Enter a decimal number: ");         //prints the sentence where it would then ask for the decV to be entered
        scanf("%d", &decV);                       //the operater '&' specifies the memory adress of decV and stores the value the there
        if (decV<0) break;                         //Breaks if decimal value is < 0
        printf("The number you have entered is %d\n", decV);    //Prints the number just inserted (stored) by the user 
        
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        if ((radix<2) || (radix>16)){                            //check if radix is between 2 and 16, otherwise print error message and exit loop
            printf("Radix value should be between 2 and 16\n");
            break;
        }
        printf("The radix you have entered is %d\n", radix);
        
        printf("The log2 of the number is %0.2f\n", log2(decV));         //printing the result of log2(decimal value), %f to store as float and 0.2f prints to 2 decimal points
        
        printf("The integer result of the number divided by %d is %d\n", radix, decV/radix);  //division of decimal value and radix value
        
        printf("The remainder is %d\n", decV%radix);   //printing the remainder of decimal value - division value
        
        if (decV != 0) Dec2RadixI(decV, radix);                    //check if decimal value = 0, if decV=0 program runs Dec2RadixI function otherwise prints a 0
        else printf("The radix-%d value is %c\n", radix, 48);
    }

    printf("EXIT");              //if while loop is broken (exit) prints "EXIT" and exits program
    exit;
    
    return 0;
}

void Dec2RadixI(int decValue, int radValue){          //void function created that converts to any base between 2 and 16
    
    printf("The radix-%d value is ", radValue);
    int bits = floor(log10(decValue)/log10(radValue));   //log10(base)/log10(radix) gives the log form log_radix(decimal value)
    do{                                               //do-while loop that iterates when bits value is >= 0
        int n = pow(radValue,bits);               //get base (radix)^(bits)
        int divV = floor(decValue/n);             //divides to see if new power number fits within decimal value
        if (divV < 1){                         //if division is < 1, program prints a 0 (remainder)
            printf("%c", divV = 48);          //prints 0 as a char rather than decimal value as char is only 8 bits where decimal value is 32 bits, so it saves memory
            bits -= 1;                        //decrease bits value to check new power
        }
        else{
            if (divV>9){                        //if division > 9, prints the char values for A,B,C,D,E,F,G
               printf("%c", divV+55);
               decValue = decValue - (n*divV);   //decreases the value with a multiplier of the previous value to get a new value to compare
               bits -= 1;
            }
            else{                            //prints decimal values also as char to spare memory
                printf("%c", divV+48);
                decValue = decValue - (n*divV);
                bits -= 1;
            }
        }
    } while(bits>=0); 
    printf("\n");            //prints new line
}
