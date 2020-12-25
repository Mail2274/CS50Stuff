#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{
    //Get card number from the user

    long cardNumber;

    do
    {
        cardNumber = get_long("Number: ");
    }
    while (cardNumber <= 0);

    //Iterate through the card number

    int lastDigit;
    int secondLastDigit;
    int sum = 0;
    int doubleSum = 0;
    long workingCC = cardNumber;
    int checkSum;
    float count = 0;

    //Take every other number, starting from end, and add them together
    while (workingCC > 0)
    {
        lastDigit = workingCC % 10;
        sum = sum + lastDigit;
        workingCC = workingCC / 100;
    }

    //Take every other number, starting second from end, and add them together, then double that sum
    workingCC = cardNumber;
    while (workingCC > 0)
    {
        secondLastDigit = ((workingCC % 100) / 10);
        doubleSum = doubleSum + ((2 * secondLastDigit) / 10 + (2 * secondLastDigit % 10));
        
        workingCC = workingCC / 100;
    }

    //Combine normal sum and doubleSum

    checkSum = sum + doubleSum;

    //Get number of digits in card
    workingCC = cardNumber;
    while (workingCC > 0)
    {
        workingCC = workingCC / 10;
        count++;
    }

    //Apply tests to get card provider

    int firstDigit = cardNumber / pow(10, (count - 1));
    int firstTwoDigits = cardNumber / pow(10, (count - 2));
    
    if (checkSum % 10 == 0)
    {
        if ((firstTwoDigits == 34 || firstTwoDigits == 37) &&  count == 15)
        {
            printf("AMEX\n");
        }
        else if  ((firstTwoDigits == 51 || firstTwoDigits == 52 || firstTwoDigits == 53 || firstTwoDigits == 54 || firstTwoDigits == 55) && count == 16)
        {
            printf("MASTERCARD\n");
        }
        else if (firstDigit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
        }
        else 
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}