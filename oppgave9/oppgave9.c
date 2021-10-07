#include<stdio.h>

int main() {
    int totaltSekunder = 312304,
        timer,
        minutter,
        tmp,
        sekunder;

    
    tmp = totaltSekunder % 3600;
    sekunder = (totaltSekunder % 3600) % 60;
    minutter = (totaltSekunder % 3600) / 60;
    timer = totaltSekunder / 3600;
    printf("Timer = %i\n", timer);
    printf("Minutter = %i\n", minutter);
    printf("Sekunder = %i\n", sekunder);
    printf("Tmp ingnore this, for debug = %i\n", tmp);
    return 0;
}