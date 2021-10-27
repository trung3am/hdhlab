#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {



    pid_t b = fork();
    
    if(b == 0){
      printf("\nProcess B %i, ",getpid());
      printf("my parent id %i \n", getppid());
        pid_t e = fork();
        if(e == 0){
          printf("\nProcess E %i, ",getpid());
          printf("my parent id %i \n", getppid());
            pid_t i = fork();
            if(i == 0){
            
                printf("\nProcess I %i, ",getpid());
                printf("my parent id %i \n", getppid());
                
                return 0;
            }
            else{
                wait(NULL);
                return 0;
            }
        }
        else{
            pid_t f = fork();

            if(f == 0) {

                printf("\nProcess F %i, ",getpid());
                printf("my parent id %i \n", getppid());
                return 0;
            }
            else{
                wait(NULL);
                return 0;
            }
        }
    }
    else{
    
        pid_t c = fork();
        if(c == 0){
          printf("\nProcess C %i, ",getpid());
          printf("my parent id %i \n", getppid());
            pid_t g = fork();
            if(g == 0) {
                
                printf("\nProcess G %i, ",getpid());
                printf("my parent id %i \n", getppid());
                return 0;
            
            }
            else {
            
                wait(NULL);
                return 0;
            }

        }
        else{
            pid_t d = fork();
            if(d == 0) {
                printf("\nProcess D %i, ",getpid());
                printf("my parent id %i \n", getppid());
                return 0;
        
            }
            else{
            wait(NULL);
            printf("\nProcess A %i, ",getpid());  
            return 0;

            }
        }
        wait(NULL);
        return 0;
    }

}
