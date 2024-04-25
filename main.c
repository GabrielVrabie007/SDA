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