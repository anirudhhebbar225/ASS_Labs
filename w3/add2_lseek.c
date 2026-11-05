// Usage: ./a.out file  -> copies first, middle, last 10 bytes to 3 files
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
void copy_part(int fd, off_t pos, char *outname) {
    char buf[10];
    lseek(fd, pos, SEEK_SET);                 // jump to position
    int n = read(fd, buf, 10);
    int out = open(outname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(out, buf, n);
    close(out);
}
int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) { printf("Cannot open\n"); return 1; }
    off_t size = lseek(fd, 0, SEEK_END);      // file size
    copy_part(fd, 0, "first.txt");
    copy_part(fd, size / 2, "middle.txt");
    copy_part(fd, size - 10, "last.txt");
    close(fd);
    printf("Done: first.txt middle.txt last.txt\n");
    return 0;
}
