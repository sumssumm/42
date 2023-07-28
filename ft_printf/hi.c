#include <stdio.h>
#include <unistd.h>

int main()
{
    int a = 0;
    fclose(stdout);
    a = printf("%d", 1);

    FILE *f1 = fopen("asdf.txt", "w");
    fprintf(f1, "%d", a);
    return 0;
}