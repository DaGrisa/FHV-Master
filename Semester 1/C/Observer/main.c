#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

int notify1(const Message_t* message){
    printf("Notify 1: %s\n",message->message);
    return EXIT_SUCCESS;
}

int notify2(const Message_t* message){
    printf("Notify 2: %s\n",message->message);
    return EXIT_SUCCESS;
}

int notify3(const Message_t* message){
    printf("Notify 3: %s\n",message->message);
    return EXIT_SUCCESS;
}

int main(){
    observer_register(notify1);
    observer_register(notify2);
    observer_register(notify3);

    Message_t message = {"Testnachricht"};
    observer_notifyAll(&message);

    return EXIT_SUCCESS;
}