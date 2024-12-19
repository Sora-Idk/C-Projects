#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>


int binaryToDecimal(char binary[])
{
    int i, power = 0, decimal = 0;

    for(i = strlen(binary)-1;i>=0;i--)
    {
        if(binary[i] == '1')
        {
            decimal += pow(2,power);/*adds 2^power value so for 2^0 = 1, 2^1 = 2 etc*/
        }
        power+=1;
    }
    return decimal;
}

int octalToDecimal(int octal)
{
    int last_digit,power = 0, decimal = 0;
    while(octal>0)
    {
        last_digit = octal%10;
        decimal+= last_digit * pow(8,power);
        octal/=10;
        power+=1;
    }
    return decimal;
}

int hexadecimalToDecimal(char hex[])
{
    int decimal = 0, base = 1, i = 0;
    while (hex[i] != '\0')
        {
        int value = 0;
        if (hex[i] >= '0' && hex[i] <= '9')
            {
                value = hex[i] - '0';
            }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            {
                value = hex[i] - 'A' + 10;
            }
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            {
                value = hex[i] - 'a' + 10;
            }
        decimal += value * base;
        base *= 16;
        i++;
    }
    return decimal;
}

int decimalToBinary(int decimal) {
    int binary = 0, base = 1, remainder;

    while (decimal > 0) {
        remainder = decimal % 2;
        binary += remainder * base;
        base *= 10;
        decimal /= 2;
    }
    return binary;
}

void convertTo(int val_inDecimal)
{
    int ch2;
    int bool_ch2_chosen = 0;

    while(bool_ch2_chosen == 0)
    {
        printf("What would you like this to be converted into?\n");
        printf("1.binary\n2.Decimal\n3.Octal\n4.Hexadecimal\n");
        printf("Enter the number corresponding to your choice:");
        scanf("%d",&ch2);
        switch(ch2)
        {
        case 1:
            bool_ch2_chosen++;
            clrscr();
            printf("On converting to Binary, Input = %d", decimalToBinary(val_inDecimal));
            break;
        case 2:
            bool_ch2_chosen++;
            clrscr();
            printf("On converting to decimal, Input = %d",val_inDecimal);
            break;
        case 3:
            bool_ch2_chosen++;
            clrscr();
            printf("On converting to Octal, Input = %o",val_inDecimal);
            break;e
        case 4:
            bool_ch2_chosen++;
            clrscr();
            printf("On converting to Hexadecimal, Input = %x", val_inDecimal);
            break;
        default:
            clrscr();
            printf("#######################################################################\n");
            printf("INVALID CHOICE TRY AGAIN\n");
            printf("#######################################################################\n");
        }
    }
}

void main()
{
    int ch1;
    int bool_ch1_chosen = 0;
    char str_inp[10];
    int int_inp;

    int val_convToDecimal;/*stores the value after its been converted to decimal(we do this to every value as we can convert
    to and from decimal to all other formats)*/

    printf("\t*Number System Conversion*");
    while(bool_ch1_chosen == 0)
    {
        printf("What format will your input be in?\n");
        printf("1.Binary\n2.Decimal\n3.Octal\n4.Hexadecimal\n");
        printf("Enter the number corresponding to your choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            bool_ch1_chosen++;
            clrscr();
            printf("Enter your binary value(max 10 digits):");
            scanf("%s",&str_inp);
            printf("\n");
            val_convToDecimal = binaryToDecimal(str_inp);
            convertTo(val_convToDecimal);
            break;
        case 2:
            bool_ch1_chosen++;
            clrscr();
            printf("Enter your decimal value(Base 10 not floating point):");
            scanf("%d",&int_inp);
            printf("\n");
            val_convToDecimal = int_inp;
            convertTo(val_convToDecimal);
            break;
        case 3:
            bool_ch1_chosen++;
            clrscr();
            printf("Enter your octal value(max 5 digits with 0-7 numbers):");
            scanf("%d",&int_inp);
            printf("\n");
            val_convToDecimal = octalToDecimal(int_inp);
            convertTo(val_convToDecimal);
            break;
        case 4:
            bool_ch1_chosen++;
            clrscr();
            printf("Enter your hexadecimal value:");
            scanf("%s",&str_inp);
            printf("\n");
            val_convToDecimal = hexadecimalToDecimal(str_inp);
            convertTo(val_convToDecimal);
            break;
        default:
            clrscr();
            printf("#######################################################################\n");
            printf("INVALID CHOICE TRY AGAIN\n");
            printf("#######################################################################\n");
        }
    }

    getch();
}
