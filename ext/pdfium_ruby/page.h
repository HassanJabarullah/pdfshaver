#ifndef __PAGE_H__
#define __PAGE_H__

// forward declaration since Page/Document classes are interdependent
class Document;
#include "pdfium_ruby.h"
#include "document.h"

class Page {
  public:
    Page();
    
    bool load(Document* document, int page_number);
    
    bool render();
    
    float aspect();
    
    double width();
    double height();
    
    ~Page();
    
  private:
    int page_number;
    bool opened;
    Document *document;
    FPDF_PAGE page;
};

void Define_Page();
VALUE initialize_page_internals(int arg_count, VALUE* args, VALUE self);
VALUE page_allocate(VALUE rb_PDFium_Page);
static void destroy_page(Page* page);

#endif