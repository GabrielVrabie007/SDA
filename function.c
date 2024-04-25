#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <string.h>


Job *readList() {
    Job *newJob = (Job *) malloc(sizeof(Job));
    if (newJob == NULL) {
        printf("Memorie insuficienta!\n");
        exit(1);
    }
    newJob->name = name_alloc();
    printf("Nume: ");
    scanf("%s", newJob->name);
    newJob->position = position_alloc();
    printf("Pozitie: ");
    scanf("%s", newJob->position);
    printf("Experienta: ");
    scanf_s("%d", &newJob->experience);

    newJob->responsability = responsability_alloc();
    printf("Responsabilitate: ");
    scanf("%s", newJob->responsability);
    printf("Salariu: ");
    scanf_s("%d", &newJob->salary);

    //adaugam la sfaristul listei astfel incat pointer de urm element sa fie NULL
    newJob->next = NULL;

    return newJob;
}

void printList(Job *head) {
    Job *current = head;//adica PRIMUL ELEMENT DIN LISTA
    while (current != NULL) {
        printf("\n");
        printf("Nume: %s\n", current->name);
        printf("Pozitie: %s\n", current->position);
        printf("Experienta: %d\n", current->experience);
        printf("Responsabilitate: %s\n", current->responsability);
        printf("Salariu: %d\n", current->salary);
        printf("\n");
        current = current->next;
    }
}

int searchJobByName(Job *head, char *nameToSearch) {
    Job *current = head;
    int position = 1; // poziția elementului de la 1
    while (current != NULL) {
        if (strcmp(current->name, nameToSearch) == 0) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}

//selection sort
Job *sortListBySalary(Job *head) {
    if (head == NULL || head->next == NULL)
        return head;

    Job *current = head;

    while (current->next != NULL) {
        Job *minSalary = current;
        Job *temp = current->next;

        while (temp != NULL) {
            if (temp->salary < minSalary->salary) {
                minSalary = temp;
            }
            temp = temp->next;
        }

        if (minSalary != current) {
            int tempSalary = current->salary;
            current->salary = minSalary->salary;
            minSalary->salary = tempSalary;
        }

        current = current->next;
    }

    return head;
}

void push_front(Job **head) {
    Job *new_job = readList();//alocam memorie
    new_job->next = *head;
    *head = new_job;
}

//incepe a numara de la 0
void insert_at_position(Job **head, int position) {
    if (position < 0) {
        printf("Pozitie invalida!\n");
        return;
    }
    if (position == 0) {

        push_front(head);
        return;
    }
    Job *new_job = readList();
    if (*head == NULL && position != 0) {

        printf("Lista este goala, nu se poate adauga la pozitia specificata.\n");
        return;
    }
    Job *current = *head;
    int current_position = 0;

    // Parcurge lista pana la pozitia anterioara a celei specificate
    while (current_position < position - 1 && current->next != NULL) {
        current = current->next;
        current_position++;
    }
    if (current_position < position - 1) {
        printf("Pozitie prea mare, lista nu are atatea elemente.\n");
        free(new_job);
        return;
    }

    new_job->next = current->next;
    current->next = new_job;
}

void delete_by_name(Job **head, char name[]) {
    Job *prev = NULL;
    Job *current = *head;
    int found = 0;

    while (current != NULL && !found) {
        if (strcmp(current->name, name) == 0) {
            found = 1;
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->name);
            free(current);
        } else {
            prev = current;
            current = current->next;
        }
    }

    if (!found) {
        printf("Jobul %s nu a fost gasit in lista.\n", name);
    }
}

void deleteList(Job **head) {
    Job *current = *head;
    Job *next;

    while (current != NULL) {
        next = current->next;
        free(current->name);
        free(current);
        current = next;
    }

    *head = NULL;
}

Job *reverseList(Job *head) {
    Job *prev = NULL;
    Job *current = head;
    Job *urm = NULL;

    while (current != NULL) {

        urm = current->next;
        current = urm;
        current->next = prev;
        prev = current;

    }

    head = prev;
    return head;
}

char *name_alloc() {
    return (char *) calloc(30, sizeof(char));
}

char *position_alloc() {
    return (char *) calloc(30, sizeof(char));
}

char *responsability_alloc() {
    return (char *) calloc(30, sizeof(char));
}