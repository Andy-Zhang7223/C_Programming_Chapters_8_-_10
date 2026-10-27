#include <stdio.h>

//NUM_RATES is the amount of items in the array
#define NUM_RATES ((int) (sizeof(value)/sizeof(value[0])))
//Initial Balance
#define INITIAL_BALANCE 100.00

int main(void)
{
    int i, low_rate,num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    //This Prints the interest rates on the top of the chart
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    //This prints the chart itself, doesn't do any calculation that's editable with a simple for loop, tried that
    //For loop did work, it's just that if you use i in both places it isn't happy. I might be a little silly
    for (year = 1; year <= num_years; year++) {
        printf("%3d     ",year);
        //NUM_RATES is used here to get the other interest rates,
        //Say the rate is 6%, the loop runs when the interest is 6%
        //Then the loop runs again with low_rate+i, i = 1, interest rate that loop would be 7%
        //Continues until all rates have been hit
        for (i = 0; i < NUM_RATES; i++) {
            //Calculates the value after interest, Try to repeat this 12 times for 12 months in a year...
            for (int x = 0; x < 12; x++) {
                value[i] += (low_rate + i) / 100.00 * value[i];
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }
    return 0;
}
