// Show .c files in current dir, ask to give others read permission
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
int main() {
    DIR *d = opendir(".");
    struct dirent *e;
    struct stat st;
    char ans;
    while ((e = readdir(d)) != NULL) {
        int len = strlen(e->d_name);
        if (len > 2 && strcmp(e->d_name + len - 2, ".c") == 0) {
            printf("%s : give read permission to others? (y/n) ", e->d_name);
            scanf(" %c", &ans);
            if (ans == 'y') {
                stat(e->d_name, &st);
                chmod(e->d_name, st.st_mode | S_IRGRP | S_IROTH);  // add r for group & others
                printf("Permission granted\n");
            }
        }
    }
    closedir(d);
    return 0;
}
