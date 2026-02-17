#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char line[200];
    int count = 1;

    fp = fopen("input.c", "r");

    if(fp == NULL)
    {
        printf("File cannot be opened");
        return 0;
    }

    while(fgets(line, sizeof(line), fp))
    {
        printf("%d %s", count, line);
        count++;
    }

    fclose(fp);
    return 0;
}
