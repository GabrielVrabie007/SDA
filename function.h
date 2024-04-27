

#ifndef JOB_H
#define JOB_H


typedef struct Job {

    char *name;
    char *position;
    int experience;
    char *responsability;
    int salary;
    struct Job *next;
}Job;

// Prototipurile funcțiilor
Job* readList();
void printList(Job *head);
int searchJobByName(Job *head,char *nameToSearch);
Job *sortListBySalary(Job *head);
void push_front(Job** head);
void insert_at_position(Job** head, int position);
void delete_by_name(Job **head,char name[]);
Job* reverseList(Job* head);
void deleteList(Job** head);
char* name_alloc();
char *position_alloc();
char *responsability_alloc();
=======
#ifndef MUZEU_H
#define MUZEU_H

typedef struct  {
    char denumirea[50];
    char *adresa;
    char telefonul[15];
    int numar_exponate;
    float pret_bilet;
} Muzeu;

// Prototipurile funcțiilor
Muzeu* alocare_memorie(int dimensiune);
void introducere_informaii(Muzeu *tab, int dimensiune);
void afisare_informaii(Muzeu *tab, int dimensiune);
int cautare_element(Muzeu *tab, int dimensiune, char *denumirea);
void sortare_tablou(Muzeu *tab, int dimensiune);
void adaugare_sfarsit(Muzeu **tab, int *dimensiune);
void adaugare_inceput(Muzeu *tab, int *dimensiune);
void inserare_dupa(Muzeu *tab, int *dimensiune, char *denumirea);
void stergere_element(Muzeu *tab, int *dimensiune, char *denumirea);
void eliberare_memorie(Muzeu *tab);

#endif