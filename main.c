#include <stdio.h>
#include <stdlib.h>


int main(int argc, char ** argv) {
    char buff[255];
    int count = 0;
    pid_t pid;
    FILE *fp = fopen("numbers.txt", "r");
    pid = fork();
    if(pid == 0){
        while(fgets(buff,255,(FILE*)fp)){
            if(atoi(buff) % 2 == 0){
                count++;
            }

        }
        printf("%d\n", count);
        return 0;
    }
    else{
        
        while(fgets(buff,255,(FILE*)fp)){
            if(atoi(buff) % 3 == 0){
                count++;
            }
        }
        printf("%d\n", count);
        rewind(fp);
        wait(NULL);
        return 0;
    }
    return 0;
}
