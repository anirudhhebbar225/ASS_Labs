#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
int main() {
    char old[256], new[256];
    struct stat st;
    printf("Enter existing file: ");
    scanf("%s", old);
    printf("Enter new link name: ");
    scanf("%s", new);
    if (link(old, new) == -1) { perror("link"); return 1; }
    stat(old, &st);
    printf("Hard link created: %s -> %s (links now %lu)\n", new, old, st.st_nlink);
    unlink(new);
    stat(old, &st);
    printf("Unlinked %s (links now %lu)\n", new, st.st_nlink);
    return 0;
}
