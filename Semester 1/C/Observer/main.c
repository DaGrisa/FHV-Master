#include <stdlib.h>
#include <stdio.h>
#include "observer.h"

int notify1(const Message_t message){
    printf("Notify 1: %s\n",message.message);
    return EXIT_SUCCESS;
}

int notify2(const Message_t message){
    printf("Notify 2: %s\n",message.message);
    return EXIT_SUCCESS;
}

int notify3(const Message_t message){
    printf("Notify 3: %s\n",message.message);
    return EXIT_SUCCESS;
}

int main(){
    NotifyFunction_t pNotify1 = notify1;
    observer_register(pNotify1);

    NotifyFunction_t pNotify2 = notify2;
    observer_register(pNotify2);

    NotifyFunction_t pNotify3 = notify3;
    observer_register(pNotify3);

    Message_t message = {"Testnachricht"};
    observer_notifyAll(&message);

    return EXIT_SUCCESS;
}