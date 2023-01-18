#include <stdlib.h>

#include "utils/io.h"
#include "utils/logger.h"

int main(int argc, char **argv) {
    // printf("%d, %s\n", argc, argv[1]);
    InitLogger();
    LogInfo("Testando %s", "HelloWorld!");
    Print("Hello %s", "World!");
    return 0;
}
