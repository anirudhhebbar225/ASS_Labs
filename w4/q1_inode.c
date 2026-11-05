#include <stdio.h>
#include <sys/stat.h>
int main() {
    char name[256];
    struct stat st;
    printf("Enter filename: ");
    scanf("%s", name);
    if (stat(name, &st) == -1) { perror("stat"); return 1; }
    printf("Inode number of %s = %lu\n", name, st.st_ino);
    return 0;
}
