#include <stdio.h>
#include <pthread.h>

int turn = 0;
void * hello(void * tid){
    while(1==1){
        if(turn == (int)tid){
            printf("Hello from thread %d\n", (int)tid);
            turn++;
            break;
        }
    }

}

int main() {
    pthread_t tid[10];
    int i;
    for (i = 0; i <10; i++){
        pthread_create(&tid[i],NULL,hello, (void*)i);
    }
    for (int j =0; j<10; j++){
        pthread_join(tid[j],NULL);
    }
    pthread_exit(NULL);
}
