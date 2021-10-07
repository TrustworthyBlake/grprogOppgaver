#include <stdio.h>

struct Brok {
    int
        nevner,
        teller;
};

struct Brok lesBrok();
int lesTall(const int min, const int max);
void skrivBrok(const struct Brok b);
struct Brok addisjon(const struct Brok b, const struct Brok b2);
struct Brok substraktsjon(const struct Brok b, const struct Brok b2);
struct Brok multiplikasjon(const struct Brok b, const struct Brok b2);
struct Brok divisjon(const struct Brok b, const struct Brok b2);

int main() {
    struct Brok brok, brok2, svar;
    
    brok = lesBrok();
    brok2 = lesBrok();

    svar = addisjon(brok, brok2);
    skrivBrok(svar);

    svar = substraktsjon(brok, brok2);
    skrivBrok(svar);

    svar = multiplikasjon(brok, brok2);
    skrivBrok(svar);

    svar = divisjon(brok, brok2);
    skrivBrok(svar);

    return 0;
}

struct Brok lesBrok() {
    struct Brok b;
    printf("\nSkriv teller: ");
    b.teller = lesTall(-9999, 9999);
    printf("\nSkriv inn nevner: ");
    b.nevner = lesTall(1, 9999);
    return b;
}

int lesTall(const int min, const int max) {
    int tall = 0;
    do {
        scanf("%i", &tall);
    } while (tall < min || tall > max);
    return tall;
}

void skrivBrok(const struct Brok b) {
    printf("\n%i / %i\n", b.teller, b.nevner);
}

struct Brok addisjon(const struct Brok b, const struct Brok b2) {
    struct Brok b3;
    b3.teller = (b.teller * b2.nevner) + (b.nevner * b2.teller);
    b3.nevner = b.nevner * b2.nevner;
    return b3;
}

struct Brok substraktsjon(const struct Brok b, const struct Brok b2) {
    struct Brok b3;
    b3.teller = (b.teller * b2.nevner) - (b.nevner * b2.teller);
    b3.nevner = b.nevner * b2.nevner;
    return b3;
}

struct Brok multiplikasjon(const struct Brok b, const struct Brok b2) {
    struct Brok b3;
    b3.teller = b.teller * b2.teller;
    b3.nevner = b.nevner * b2.nevner;
    return b3;
}

struct Brok divisjon(const struct Brok b, const struct Brok b2){
    struct Brok b3;
    b3.teller = b.teller * b2.nevner;
    b3.nevner = b.nevner * b2.teller;
    return b3;
}