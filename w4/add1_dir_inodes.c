#include <stdio.h>
#include <dirent.h>
int main() {
    char dname[256];
    printf("Enter directory name: ");
    scanf("%s", dname);
    DIR *d = opendir(dname);
    if (d == NULL) { perror("opendir"); return 1; }
    struct dirent *e;
    while ((e = readdir(d)) != NULL)
        printf("%-20s inode = %lu\n", e->d_name, e->d_ino);
    closedir(d);
    return 0;
}
