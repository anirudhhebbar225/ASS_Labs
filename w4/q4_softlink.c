#include <stdio.h>
#include <unistd.h>
int main() {
    char old[256], new[256], target[256];
    printf("Enter existing file: ");
    scanf("%s", old);
    printf("Enter new link name: ");
    scanf("%s", new);
    if (symlink(old, new) == -1) { perror("symlink"); return 1; }
    int n = readlink(new, target, sizeof target - 1);  // where does the link point?
    target[n] = '\0';
    printf("Soft link created: %s -> %s\n", new, target);
    unlink(new);
    printf("Unlinked %s\n", new);
    return 0;
}
