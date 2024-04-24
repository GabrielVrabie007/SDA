#ifndef FUNC
#define FUNC

typedef struct Document {
    int ID;
    char *name;
    int total_rows;
    int left_rows;
    bool printed;
    struct Document *next;
} Document;

typedef struct Printer{
    int ID;
    int power;
    Document *current_doc;
    struct Printer *next;
}Printer;

//Prototipurile la functii
Document* read_documents_from_file();
Printer* read_printers_from_file();
Document* add_document_to_print(Document **docList, Document *newDoc,int printer_id);
bool _is_printer_available(Printer *printerList);
Printer *get_most_efficient_and_available_printer(Printer *printerList);
void print_document(Printer **printerList, Document **docList, Document *docToAdd);
int all_documents_printed(Document *docList);

#endif


