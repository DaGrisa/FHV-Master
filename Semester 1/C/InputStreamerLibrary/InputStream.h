//
// Created by Daniel on 28.01.17.
//

#ifndef INPUTSTREAMERLIBRARY_INPUTSTREAM_H
#define INPUTSTREAMERLIBRARY_INPUTSTREAM_H

typedef struct {
    int (*hasNext) (void);
    char (*next) (void);
    void (*deleteAll) (void);
} InputStream;

#endif //INPUTSTREAMERLIBRARY_INPUTSTREAM_H
