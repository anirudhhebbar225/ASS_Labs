// Usage: ./a.out word file
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char line[1024];
    FILE *fp = fopen(argv[2], "r");
    if (fp == NULL) { printf("Cannot open file\n"); return 1; }
    while (fgets(line, sizeof line, fp))
        if (strstr(line, argv[1]))      // word found in line?
            printf("%s", line);
    fclose(fp);
    return 0;
}
