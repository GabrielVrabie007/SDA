#include <stdio.h>
#include <stdlib.h>
#include "function.h"


int main() {
    //in caz ca de la inceput nu dam dimensiunea la tablou
    Muzeu *tab = NULL;
    int dimensiune = 0;
    int optiune;
    char denumirea[50];

    do {
        printf("\nMenu:\n");
        printf("1. Alocare dinamica a memoriei pentru tablou\n");
        printf("2. Introducere informatii\n");
        printf("3. Afisare informatii\n");
        printf("4. Cautare element in tablou\n");
        printf("5. Sortare tablou\n");
        printf("6. Adaugare element la sfarsit\n");
        printf("7. Adaugare element la inceput\n");
        printf("8. Inserare element dupa alt element\n");
        printf("9. Stergere element\n");
        printf("10. Eliberare memorie alocata pentru tablou\n");
        printf("0. Iesire din program\n");
        printf("Optiune: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                printf("Introduceti dimensiunea tabloului: ");
                scanf("%d", &dimensiune);
                tab = alocare_memorie(dimensiune);
                break;
            case 2:
                introducere_informaii(tab, dimensiune);
                break;
            case 3:
                afisare_informaii(tab, dimensiune);
                break;
            case 4:
                printf("Introduceti denumirea muzeului de cautat: ");
                scanf("%s", denumirea);
                printf("Muzeul se afla pe pozitia: %d\n", cautare_element(tab, dimensiune, denumirea) + 1);
                break;

            case 5:
                sortare_tablou(tab, dimensiune);
                break;
            case 6:
                adaugare_sfarsit(&tab, &dimensiune);
                break;
            case 7:
                adaugare_inceput(tab, &dimensiune);
                break;
            case 8:
                printf("Introduceti denumirea muzeului dupa care se va insera noul element: ");
                scanf("%s", denumirea);
                inserare_dupa(tab, &dimensiune, denumirea);
                break;
            case 9:
                printf("Introduceti denumirea muzeului de sters: ");
                scanf("%s", denumirea);
                stergere_element(tab, &dimensiune, denumirea);
                break;
            case 10:
                eliberare_memorie(tab);
                tab = NULL;
                dimensiune = 0;
                break;
            case 0:
                printf("Iesire din program.\n");
                break;
            default:
                printf("Optiune invalida.\n");
        }
    } while (optiune != 0);



    return 0;
}
