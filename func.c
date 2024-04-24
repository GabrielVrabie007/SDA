#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX_NAME_LENGTH 5


Document* read_documents_from_file() {
    FILE *file;
    Document *docs = NULL;
    int count = 0;
    file = fopen("C:\\Users\\Professional\\Documents\\Seminar_2_SDA\\documents.txt", "r");
    if (file == NULL) {
        printf("Documents file didn't open!");
        return NULL;
    }

    printf("\n\nID//Name//Total Rows//Left Rows\n");

    while (1) {
        Document document;
        document.name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char)); // Dynamically allocate memory for name
        if (document.name == NULL) {
            printf("Error allocating memory for name.\n");
            exit(1);
        }
        if (fscanf(file, "%d %4s %d %d", &document.ID,
                   document.name, &document.total_rows,
                   &document.left_rows) != 4) {
            break;
        }
        printf("%d %s %d %d\n", document.ID,
               document.name, document.total_rows,
               document.left_rows);
        count++;

        docs = (Document*)realloc(docs, count * sizeof(Document));
        if (docs == NULL) {
            printf("Error reallocating memory.\n");
            exit(1);
        }
        docs[count - 1] = document;
    }

    return docs;
}

Printer* read_printers_from_file() {
    FILE *file;
    Printer *printers = NULL; // Initialize printers to NULL
    int count = 0;

    file = fopen("C:\\Users\\Professional\\Documents\\Seminar_2_SDA\\printers.txt", "r");
    if (file == NULL) {
        printf("Printer file didn't open");
        return NULL;
    }
    printf("\n\nID//Power\n");
    while (1) {
        Printer machine;

        if (fscanf(file, "%d %d", &machine.ID, &machine.power) != 2) {
            break;
        }
        printf("%d %d\n", machine.ID,
               machine.power);
        count++;

        printers = (Printer*)realloc(printers, count * sizeof(Printer));
        if (printers == NULL) {
            printf("Error reallocating memory.\n");
            exit(1);
        }
        printers[count - 1] = machine;
    }

    return printers;
}

Document* add_document_to_print(Document **docList, Document *newDoc, int printer_id) {
    newDoc = (Document*)malloc(sizeof(Document)); // Allocate memory for the new document
    if (newDoc == NULL) {
        printf("Error allocating memory for new document.\n");
        exit(1);
    }
    newDoc->next = NULL;
    newDoc->left_rows = newDoc->total_rows; // Inițializează numărul de rânduri rămase cu totalul
    newDoc->printed = false; // Marchează documentul ca neimprimat
    if (*docList == NULL) {
        *docList = newDoc;
    } else {
        Document *temp = *docList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDoc;
    }
    return *docList;
}

bool _is_printer_available(Printer *printerList) {
    if (printerList == NULL || printerList->current_doc == NULL) {
        return true;
    }
    return false;
}

Printer *get_most_efficient_and_available_printer(Printer *printerList) {
    Printer *most_efficient_printer = NULL;
    Printer *printer_iterator = printerList;

    while (printer_iterator != NULL) {
        if (_is_printer_available(printer_iterator)) {
            if (most_efficient_printer == NULL || printer_iterator->power > most_efficient_printer->power) {
                most_efficient_printer = printer_iterator;
            }
        }
        printer_iterator = printer_iterator->next;
    }

    return most_efficient_printer;
}


void print_document(Printer **printerList, Document **docList, Document *docToAdd) {
    Document *doc_iterator = docToAdd;
    while (doc_iterator != NULL) {
        Printer *printer = get_most_efficient_and_available_printer(*printerList);
        if (printer == NULL) {
            printf("Nu exista o imprimanta disponibila sau toate sunt ocupate.\n");
            return;
        }

        printer->current_doc = doc_iterator;
        printf("Documentul \"%s\" a fost adaugat la imprimanta cu ID-ul %d.\n", doc_iterator->name, printer->ID);

        int rows_to_print = (printer->power < doc_iterator->left_rows) ? printer->power : doc_iterator->left_rows;
        doc_iterator->left_rows -= rows_to_print;
        printf("%d randuri au fost imprimate pentru documentul \"%s\"\n", rows_to_print, doc_iterator->name);

        if (doc_iterator->left_rows == 0) {
            // Eliminarea documentului din lista dacă acesta a fost complet imprimat
            Document *prev = NULL;
            Document *currentDoc = *docList;
            while (currentDoc != NULL) {
                if (currentDoc == doc_iterator) {
                    if (prev != NULL) {
                        prev->next = currentDoc->next;
                    } else {
                        *docList = currentDoc->next;
                    }
                    free(currentDoc);
                    break;
                }
                prev = currentDoc;
                currentDoc = currentDoc->next;
            }
        }

        printf("Documente ramase de printat:\n");
        Document *currentDoc = *docList;
        while (currentDoc != NULL) {
            printf("ID: %d, Nume: %s, Randuri ramase de printat: %d\n", currentDoc->ID, currentDoc->name, currentDoc->left_rows);
            currentDoc = currentDoc->next;
        }

        doc_iterator = doc_iterator->next;
    }
}


int all_documents_printed(Document *docList) {
    Document *currentDoc = docList;
    while (currentDoc != NULL) {
        if (!currentDoc->printed) {
            return 0; // Există cel puțin un document neimprimat complet
        }
        currentDoc = currentDoc->next;
    }
    printf("Toate documentele au fost imprimate complet.\n");
    return 1;
}
