#include <stdbool.h>
#include <stdio.h>

const int STRLEN = 100;

int mstrlen(const char s[]);
void mstrcpy(char s[], const char t[]);
void mstrcat(char s[], const char t[]);
int mstrcmp(const char s[], const char t[]);

int main() {
    char arr[] = {"Ding"}, str[STRLEN];  //, arr2[] = {"Dong"};
    printf("\nStrLen: %i", mstrlen("asadasdsaas"));
    mstrcpy(str, "arr256");
    printf("\n%s", str);
    mstrcat(str, " why gae");
    printf("\n%s", str);
    printf("\n%i", mstrcmp(str, "arr256 why gae 11"));

    printf("\n\n");
    return 0;
}

// Finner ant elementer/lengde
int mstrlen(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// Kopierer str2 over til str1 å overskriver str1
void mstrcpy(char s[], const char t[]) {
    for (int i = 0; i < mstrlen(t); i++) {
        s[i] = t[i];
    }
    s[mstrlen(t)] = '\0';   // '\0' i C er NULL for char array puttes på slutten av stringen
}

// str1 + str2
void mstrcat(char s[], const char t[]) {
    int i = mstrlen(s), j = 0;

    while (t[j] != '\0') {
        s[i] = t[j];
        i++;
        j++;
    }
    s[i] = '\0';
}

// Sammenligner 2stk str
int mstrcmp(const char s[], const char t[]) {
    int i = 0;
    while (s[i] != '\0'  &&  t[i] != '\0'  &&  s[i] == t[i])
       i++;
    return ((int)s[i] - (int)t[i]);
}
