// Usage: ./a.out source dest
#include <stdio.h>
int main(int argc, char *argv[]) {
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (in == NULL || out == NULL) { printf("File error\n"); return 1; }
    int ch;
    while ((ch = fgetc(in)) != EOF)   // read one char ...
        fputc(ch, out);               // ... write one char
    fclose(in); fclose(out);
    printf("Copied\n");
    return 0;
}
