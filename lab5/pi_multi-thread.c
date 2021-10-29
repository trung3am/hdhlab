#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>
#define NTHREADS 5
double count = 0.0;
void *calPi(void *param);

int main(int argc, char *argv[])
{
    clock_t begin;
    clock_t end;
    begin = clock();
    pthread_t tid[NTHREADS] ;
    double number = strtod(argv[1],NULL);
    pthread_attr_t attr[NTHREADS];
    if(argc!=2){
        fprintf(stderr, "usage a.out <integer valie>\n");
        return -1;
    }
    if(argv[1]<0){
        fprintf(stderr,"%d must be >=0 \n", atoi(argv[1]));
        return -1;
    }
    for(int i = 0; i < NTHREADS; i++){
    
        pthread_attr_init(&attr[i]);
        pthread_create(&tid[i], &attr[i], calPi,argv[1] );
    }
    for(int j =0; j < NTHREADS; j++){
    
        pthread_join(tid[j],NULL);
    }
    printf("%lf \n",4*count/number);
    end = clock();    
    printf("Execution time: %f", (double)(end-begin));
    return 0;
}

void *calPi(void *param){
    
    double number = strtod(param,NULL)/NTHREADS;
    float threadCount =0;
    srand((unsigned int)time(NULL));

    float a = 2.0;
    for (double i=0.0;i<number;i++){
        if(sqrt((pow((((float)rand()/(float)(RAND_MAX)) * a)-1,2.0))+(pow((((float)rand()/(float)(RAND_MAX)) * a)-1,2.0))) <=1){
           threadCount++;    
        }
    }
    count += threadCount;
    printf("count: %lf\n",count );
}
