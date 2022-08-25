#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Divan Grundlingh"
#define YEAR 2022

int main() {
    
    printf("*****************************\n");
    printf(" %s\n Written by: %s\n Date: %d\n", TITLE, AUTHOR, YEAR);
    printf("*****************************\n");
    
    int decV=0, radix;
    while(decV >= 0){
        printf("Enter a decimal number: ");
        scanf("%d", &decV);
        if (decV<0) break;
        printf("The number you have entered is %d\n", decV);
        
        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        if ((radix<2) || (radix>16)){
            printf("Radix value should be between 2 and 16\n");
            break;
        }
        printf("The radix you have entered is %d\n", radix);
        
        printf("The log2 of the number is %0.2f\n", log2(decV));
        
        printf("The integer result of the number divided by %d is %d\n", radix, decV/radix);
        
        printf("The remainder is %d\n", decV%radix);
        
        if (decV != 0) Dec2RadixI(decV, radix);
        else printf("The radix-%d value is %c\n", radix, 48);
    }

    printf("EXIT");
    exit;
    
    return 0;
}

void Dec2RadixI(int decValue, int radValue){
    
    printf("The radix-%d value is ", radValue);
    int bits = floor(log10(decValue)/log10(radValue));
    do{
        int n = pow(radValue,bits);
        int divV = floor(decValue/n);
        if (divV < 1){
            printf("%c", divV = 48);
            bits -= 1;
        }
        else{
            if (divV>9){
               printf("%c", divV+55);
               decValue = decValue - (n*divV);
               bits -= 1;
            }
            else{
                printf("%c", divV+48);
                decValue = decValue - (n*divV);
                bits -= 1;
            }
        }
    } while(bits>=0); 
    printf("\n");
}