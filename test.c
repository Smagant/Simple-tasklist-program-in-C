#include <stdio.h>

int main() {
    int i = 0;
    int line = 5;
    char ch[100];
    char* a[] = {"antoine is the best", "bob is the worst", "corinne", "davy"};


    FILE *fp;
    fp = fopen("test.txt", "w+");
    if (fp == NULL) {
        printf("can not open file \n");
        return 1;
    }
    for (int j = 0; j < 4; j++) {
        fputs(a[j], fp);
        fputs("\n", fp);
    }

    fgets(*a, 100, fp);
/*
    while (line--) {
        fscanf(fp, "%s", &ch[i]);
        printf("\n%s", &ch[i]);
        i++;
    }
*/
    fclose(fp);
}


