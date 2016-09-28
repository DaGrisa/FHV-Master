#include <stdio.h>

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
int main(int argc, char **argv){
    int fahr, celsius;

    if(argc == 2){
        sscanf(argv[1], "%d", &celsius);
        fahr = celsius * 9 / 5 + 32;
        printf("%d°C are %d°F\n", celsius, fahr);
    } else {
        int lower, upper, step;

        lower = 0;
        upper = 300;
        step = 20;

        fahr = lower;
        printf("°F\t°C\n");
        while(fahr <= upper){
            celsius = 5 * (fahr - 32) / 9;
            printf("%d\t%d\n", fahr, celsius);
            fahr += step;
        }
    }
}