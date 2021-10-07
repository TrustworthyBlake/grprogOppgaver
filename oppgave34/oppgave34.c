#include<stdio.h>
#include<string.h>
void finnTegn(const char *t, char *f, char *m, char *s);

int main() {
    char str[] = {"Skraaipapk"}, f, m, s;
    finnTegn(str, &f, &m, &s);
    printf("\n%c %c %c\n", f, m, s);
    return 0;
}

void finnTegn(const char *t, char *f, char *m, char *s){
    int x = strlen(t), midt = x / 2;

    for (int i = 0; i < x; i++)
    {
        if(i == 0) *f = *t;
        else if(i == midt) *m = *t;
        else if(i < x) *s = *t;
        t++;
    }
    
}