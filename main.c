/* 
 * File:   main.c
 * Author: Sebastien Robitaille
 *
 * Created on January 8, 2025, 9:15 a.m.
 * 
 * Asks the user to input a temperature followed by its unit. 
 * Then displays the temperature in Celsius, Fahrenheit, and kelvin.
 * 
 * Use C or c for Celsius, F or f fir Fahrenheit, and K or k for kelvin.
 * 
 * 
 * 
 * Program validated using the following data:
 * 
 * Input: 98.6F
 * Output: 310.150K = 37.000C = 98.600F
 * 
 * Input: -30C
 * Output: 243.150K = -30.000C = -22.000F
 * 
 * Input: 280K
 * Output: 280.000K = 6.850C = 45.015F
 * 
 * 
 * 
 * All output values are verified to be correct.
 * 
 * Input 45G
 * Output: Invalid unit: G
 * 
 */

#include <stdio.h>
#include <stdlib.h>

double inputTemp;

//To hold the unit after the temperature
char inputLine[11];

/*
 * 
 */
int main(int argc, char** argv) {
    
    //Receive the temperature and unit from the user
    printf("C = Celsius, F = Fahrenheit, K = Kelvin");
    printf("Input temperature(followed by C, F, K): ");
    scanf("%lf%10s", &inputTemp, inputLine);
    
    //Perform the required conversions and print out to the user based on the unit of the inputted temperature.
    switch(inputLine[0]){
        case 'C':
        case 'c':
            printf("%.3lfK = %.3lfC = %.3lfF",inputTemp + 273.15, inputTemp, (inputTemp * (9.0/5.0)) + 32);
            break;
        case 'F':
        case 'f':
            printf("%.3lfK = %.3lfC = %.3lfF",((inputTemp - 32.0) * (5.0/9.0)) + 273.15, (inputTemp - 32.0) * (5.0/9.0), inputTemp);
            break;
        case 'K':
        case 'k':
            printf("%.3lfK = %.3lfC = %.3lfF",inputTemp, inputTemp - 273.15, ((inputTemp  - 273.15) * (9.0/5.0)) + 32);
            break;
        default:
            printf("Invalid unit: %c", inputLine[0]);
            break;
    }

    return (EXIT_SUCCESS);
}

