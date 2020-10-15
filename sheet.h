#ifndef __LIBXLPY_SHEET__
#define __LIBXLPY_SHEET__

#include "xlsxwriter.h"

typedef struct {
  PyObject_HEAD
  lxw_worksheet *handler;
  lxw_workbook *book;
} PyXLSXSheet;


#endif
