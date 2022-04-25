#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomatic_t flag = 0; 
void my_function(int sig){
    flag = 1; 
}

int main(){
    signal(SIGINT, my_function); 
    while(pause()){
        if(flag){
            printf("funciona"); 
            flag = 0; 
        }
    }
    return 0; 
}