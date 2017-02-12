#include "../../../../ClionProjects/AphroCite/AphroCite.h"
#include "ByteArrayInputStream.h"
#include "UpperCaseInputStream.h"
#include "InputStream.h"

int main() {
    char* test = "hello123";
    char* output = malloc(8);

    InputStream* inputStream = getUpperCaseInputStream(getByteArrayInputStream(test));

    int i = 0;
    while(inputStream->hasNext()){
        output[i++] = inputStream->next();
    }

    printf("filter stream output: %s\n", output);
    return 0;
}