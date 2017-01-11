//
// Created by Daniel on 04.01.17.
//

#ifndef OBSERVER_OBSERVER_H
#define OBSERVER_OBSERVER_H

typedef struct {
    char message[256];
} Message_t;

typedef int (*NotifyFunction_t) (const Message_t message);

int observer_register(NotifyFunction_t observable);

void observer_notifyAll(const Message_t *message);

#endif //OBSERVER_OBSERVER_H
