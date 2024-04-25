#include <stdio.h>

#include "function.h"

    int main() {

    Job *head=NULL;
    int optiune;

    do {
            printf("\nMenu:\n");
            printf("1. Introducere informatii\n");
            printf("2. Afisare informatii\n");
            printf("3. Cautare element in tablou\n");
            printf("4. Sortare tablou\n");
            printf("5. Adaugare element la inceput\n");
            printf("6. Inserare element la pozitia X\n");
            printf("7. Stergere element dupa numele angajatului\n");
            printf("8. Inversarea ordinii in lista\n");
            printf("9. Stergerea listei\n");
            printf("0. Iesire din program\n");
            printf("Optiune: ");
            scanf_s("%d", &optiune);

            switch (optiune) {
                case 1:{
                    Job *newJob = readList();
                    if (head == NULL) {
                        head = newJob;
                    } else {
                        Job *current = head;
                        while (current->next != NULL) {
                            current = current->next;
                        }
                        current->next = newJob;
                    }
                    break;
                }
                case 2:{
                    if (head == NULL) {
                        printf("Lista de joburi este goala.\n");
                    } else {
                        printf("Lista de joburi:\n");
                        printList(head);
                    }
                    break;
                }
                case 3: {
                    char nameToSearch[35];
                    printf("Introduceti numele angajatului de cautat: ");
                    scanf("%s", nameToSearch);
                    int position = searchJobByName(head, nameToSearch);
                    if (position != -1) {
                        printf("Jobul \"%s\" a fost gasit la pozitia %d.\n", nameToSearch, position);
                    } else {
                        printf("Jobul \"%s\" nu a fost gasit.\n", nameToSearch);
                    }
                    break;
                }

                case 4: {
                    if (head == NULL) {
                        printf("Lista de joburi este goala.\n");
                    } else {
                        Job *sorted= sortListBySalary(head);
                        printf("Lista de joburi sortata dupa salariu:\n");
                      printList(sorted);
                    }
                    break;
                }

                case 5:{
                    push_front(&head);//face push la elementul introdus
                    printList(head);//si printeaza tabelul actualizat
                    break;
                }
                case 6:{
                    int position;
                    printf("Introduceti pozitia la care doriti sa adaugati:(0-...) ");
                    scanf_s("%d", &position);
                    insert_at_position(&head, position);
                    break;
                }
                case 7:{
                    char nume[30];
                printf("Introduceti numele angajatului de sters: ");
                    scanf("%s",nume);
                    delete_by_name(&head,nume);

                    break;
                }
                case 8:{
                    head = reverseList(head);
                    break;
                }

                case 9:{
                    deleteList(&head);
                    break;
                }

                default:{
                    printf("Invalid option!!!");
                }
            }
    } while (optiune != 0);

    return 0;

}
=======
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

