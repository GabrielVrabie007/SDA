#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

//dimensiune -cate muzee avem scrise
Muzeu* alocare_memorie(int dimensiune) {
    return (Muzeu*)malloc(dimensiune * sizeof(Muzeu));
}

void introducere_informaii(Muzeu *tab, int dimensiune) {
    for (int i = 0; i < dimensiune; i++) {
        printf("Introduceti informatiile pentru muzeu %d:\n", i + 1);
        printf("Denumirea: ");
        scanf("%s", tab[i].denumirea);
        tab[i].adresa=calloc(sizeof(char),30);
        printf("Adresa: ");
        scanf("%s", tab[i].adresa);
        printf("Telefonul: ");
        scanf("%s", tab[i].telefonul);
        printf("Numarul de exponate: ");
        scanf_s("%d", &tab[i].numar_exponate);
        printf("Pretul biletului: ");
        scanf_s("%f", &tab[i].pret_bilet);

    }

}

void afisare_informaii(Muzeu *tab, int dimensiune) {
    for (int i = 0; i < dimensiune; i++) {
        printf("Muzeu %d:\n", i + 1);
        printf("Denumirea: %s\n", tab[i].denumirea);
        printf("Adresa: %s\n", tab[i].adresa);
        printf("Telefonul: %s\n", tab[i].telefonul);
        printf("Numarul de exponate: %d\n", tab[i].numar_exponate);
        printf("Pretul biletului: %.2f\n", tab[i].pret_bilet);
    }
}

int cautare_element(Muzeu *tab, int dimensiune, char *denumirea) {
    for (int i = 0; i < dimensiune; i++) {
        if (strcmp(tab[i].denumirea, denumirea) == 0) {
            return i;
        }
    }
    return -1; // Elementul nu a fost găsit
}

//sortare dupa denumirea muzeului
//bubble sort
//daca puneam la strcmp !=0 tot avea sa mearga
void sortare_tablou(Muzeu *tab, int dimensiune) {
    for (int i = 0; i < dimensiune - 1; i++) {
        for (int j = 0; j < dimensiune - i - 1; j++) {
            if (strcmp(tab[j].denumirea, tab[j + 1].denumirea) > 0) {
                Muzeu temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

void adaugare_sfarsit(Muzeu **tab, int *dimensiune) {
    (*dimensiune)++;
    *tab = (Muzeu *)realloc(*tab, (*dimensiune) * sizeof(Muzeu));
    if (*tab == NULL) {
        printf("\nMemory violation in adaugare_sfarsit\n");
        return;
    }
    printf("Introduceti informatiile pentru muzeul adaugat la sfarsit:\n");
    printf("Denumirea: ");
    scanf("%s", (*tab)[*dimensiune - 1].denumirea);
    (*tab)[*dimensiune - 1].adresa = (char *)calloc(30, sizeof(char));
    printf("Adresa: ");
    scanf("%s", (*tab)[*dimensiune - 1].adresa);
    printf("Telefonul: ");
    scanf("%s", (*tab)[*dimensiune - 1].telefonul);
    printf("Numarul de exponate: ");
    scanf("%d", &(*tab)[*dimensiune - 1].numar_exponate);
    printf("Pretul biletului: ");
    scanf("%f", &(*tab)[*dimensiune - 1].pret_bilet);
}

void adaugare_inceput(Muzeu *tab, int *dimensiune) {
    (*dimensiune)++;
    tab = (Muzeu*)realloc(tab, (*dimensiune) * sizeof(Muzeu));
    if(tab == NULL) {
        printf("\nMemory violation adaugare_inceput\n");
        return;
    }
    for (int i = *dimensiune - 1; i > 0; i--) {
        tab[i] = tab[i - 1];
    }
    printf("Introduceti informatiile pentru muzeul adaugat la inceput:\n");
    printf("Denumirea: ");
    scanf("%s", tab[0].denumirea);
    tab[0].adresa = calloc(sizeof(char) , 30);
    printf("Adresa: ");
    scanf("%s", tab[0].adresa);
    printf("Telefonul: ");
    scanf("%s", tab[0].telefonul);
    printf("Numarul de exponate: ");
    scanf_s("%d", &tab[0].numar_exponate);
    printf("Pretul biletului: ");
    scanf_s("%f", &tab[0].pret_bilet);
}

void inserare_dupa(Muzeu *tab, int *dimensiune, char *denumirea) {
    int index = cautare_element(tab, *dimensiune, denumirea);
    if (index != -1) {
        (*dimensiune)++;
        tab = (Muzeu*)realloc(tab, (*dimensiune) * sizeof(Muzeu));
        if(tab == NULL) {
            printf("\nMemory violation inserare_dupa\n");
            return;
        }
        for (int i = *dimensiune - 1; i > index; i--) {
            tab[i] = tab[i - 1];
        }
        printf("Introduceti informatiile pentru muzeul adaugat:\n");
        printf("Denumirea: ");
        scanf("%s", tab[index + 1].denumirea);
        tab[index + 1].adresa = calloc(sizeof(char) ,30);
        printf("Adresa: ");
        scanf("%s", tab[index + 1].adresa);
        printf("Telefonul: ");
        scanf("%s", tab[index + 1].telefonul);
        printf("Numarul de exponate: ");
        scanf_s("%d", &tab[index + 1].numar_exponate);
        printf("Pretul biletului: ");
        scanf_s("%f", &tab[index + 1].pret_bilet);
    } else {
        printf("Muzeul cu denumirea %s nu a fost gasit.\n", denumirea);
    }
}

void stergere_element(Muzeu *tab, int *dimensiune, char *denumirea) {
    int index = cautare_element(tab, *dimensiune, denumirea);
    if (index != -1) {
        free(tab[index].adresa);
        for (int i = index; i < *dimensiune - 1; i++) {
            tab[i] = tab[i + 1];
        }
        (*dimensiune)--;
        tab = (Muzeu*)realloc(tab, (*dimensiune) * sizeof(Muzeu));
        if(tab == NULL) {
            printf("\nMemory violation stergere_element\n");
            return;
        }
        printf("Muzeul cu denumirea %s a fost sters.\n", denumirea);
    } else {
        printf("Muzeul cu denumirea %s nu a fost gasit.\n", denumirea);
    }
}

void eliberare_memorie(Muzeu *tab) {
    free(tab);
}


