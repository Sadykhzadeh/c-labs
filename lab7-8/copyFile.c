#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Missing arguments\n");
        return -1;
    }
    /* Text mode rewrites line endings on Windows, so this could not copy a
       binary file - or any file - byte for byte there. */
    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) return -1;
    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        /* The input handle used to leak on this path. */
        fclose(inputFile);
        return -1;
    }
    /* int buffer[9999] reserved 4 times the memory for the 9999 bytes that
       were actually read into it, and fread's size_t result was compared
       against an int. */
    char buffer[9999];
    size_t bytes;
    int status = 0;
    while ((bytes = fread(buffer, 1, sizeof buffer, inputFile)) > 0)
        if (fwrite(buffer, 1, bytes, outputFile) != bytes) {
            status = -1;
            break;
        }
    /* A short read from an I/O error looked exactly like end of file. */
    if (ferror(inputFile)) status = -1;
    fclose(inputFile);
    if (fclose(outputFile)) status = -1;
    return status;
}
