// Usage: ./a.out file1 file2 ...   (press Enter for next 20 lines)
#include <stdio.h>
int main(int argc, char *argv[]) {
    char line[1024];
    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) { printf("Cannot open %s\n", argv[i]); continue; }
        printf("----- %s -----\n", argv[i]);
        int count = 0;
        while (fgets(line, sizeof line, fp)) {
            printf("%s", line);
            if (++count % 20 == 0) {           // every 20 lines, wait for a key
                printf("--More--");
                getchar();
            }
        }
        fclose(fp);
    }
    return 0;
}
