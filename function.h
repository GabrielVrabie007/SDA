
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
#endif