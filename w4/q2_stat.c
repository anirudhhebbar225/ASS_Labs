// Usage: ./a.out file   (works for a directory too -> Additional Q2)
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
    struct stat st;
    if (stat(argv[1], &st) == -1) { perror("stat"); return 1; }
    printf("Device ID      : %lu\n", st.st_dev);
    printf("Inode          : %lu\n", st.st_ino);
    printf("Mode           : %o\n",  st.st_mode);
    printf("Hard links     : %lu\n", st.st_nlink);
    printf("User ID        : %u\n",  st.st_uid);
    printf("Group ID       : %u\n",  st.st_gid);
    printf("Device(special): %lu\n", st.st_rdev);
    printf("Size           : %ld bytes\n", st.st_size);
    printf("Block size     : %ld\n", st.st_blksize);
    printf("Blocks         : %ld\n", st.st_blocks);
    printf("Last access    : %s", ctime(&st.st_atime));
    printf("Last modify    : %s", ctime(&st.st_mtime));
    printf("Last change    : %s", ctime(&st.st_ctime));
    printf("Type           : %s\n", S_ISDIR(st.st_mode) ? "Directory" : "Regular file");
    return 0;
}
