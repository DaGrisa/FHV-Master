//
// Created by Daniel on 04.01.17.
//

#include <stdlib.h>
#include "observer.h"

#define OBSERVER_SIZE 10

static int actualObserverPosition = 0;
static NotifyFunction_t observables[OBSERVER_SIZE];

int observer_register(NotifyFunction_t observable) {
    if(actualObserverPosition < OBSERVER_SIZE){
        observables[actualObserverPosition++] = observable;
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}

void observer_notifyAll(const Message_t *message) {
    for(int i = 0; i < actualObserverPosition; i++){
        observables[i](message);
    }
}
