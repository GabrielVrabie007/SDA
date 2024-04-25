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
=======
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



