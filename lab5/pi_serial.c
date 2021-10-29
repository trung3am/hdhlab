#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double count = 0.0;

int main(int argc, char *argv[])
{
    clock_t begin;
    begin = clock();
    double number = strtod(argv[1],NULL);
    
    srand((unsigned int)time(NULL));

    float a = 2.0;
    for (double i=0.0;i<number;i++){
        if(sqrt((pow((((float)rand()/(float)(RAND_MAX)) * a)-1,2.0))+(pow((((float)rand()/(float)(RAND_MAX)) * a)-1,2.0))) <=1){
            count++;    
        }
    }
    clock_t end;
    end = clock();    
    printf("%lf \n",4*count/number);
    printf("Execution time: %f", (double)(end-begin));
    return 0;
}
