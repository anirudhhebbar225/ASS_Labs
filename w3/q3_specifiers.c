#include <stdio.h>
int main() {
    int n = 255; float f = 3.14159; char c = 'A'; char s[] = "Manipal";
    printf("%%d  int        : %d\n", n);
    printf("%%i  int        : %i\n", n);
    printf("%%u  unsigned   : %u\n", n);
    printf("%%o  octal      : %o\n", n);
    printf("%%x  hex        : %x\n", n);
    printf("%%X  HEX        : %X\n", n);
    printf("%%c  char       : %c\n", c);
    printf("%%s  string     : %s\n", s);
    printf("%%f  float      : %f\n", f);
    printf("%%.2f 2 decimals: %.2f\n", f);
    printf("%%e  scientific : %e\n", f);
    printf("%%g  shortest   : %g\n", f);
    printf("%%5d width 5    : [%5d]\n", 42);
    printf("%%-5d left      : [%-5d]\n", 42);
    printf("%%p  pointer    : %p\n", (void *)&n);
    printf("%%%%  percent    : %%\n");
    return 0;
}
