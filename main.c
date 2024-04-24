#include <stdio.h>
#include "func.h"

int main() {

    Document *doc_list = read_documents_from_file();
    Printer *printer_list = read_printers_from_file();

    while (!all_documents_printed(doc_list)) {
        printf("Checking for most efficient printer...\n");
        Printer *faster_printer = get_most_efficient_and_available_printer(printer_list);

        if (_is_printer_available(printer_list)) {
            printf("Adding document to print...\n");
            Document *new_document = add_document_to_print(&doc_list, NULL, faster_printer->ID);

            if (new_document != NULL) {
                printf("Printing document...\n");
                print_document(&printer_list, &doc_list, new_document);
            }
        }
    }

    return 0;
}


