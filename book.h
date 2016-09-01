#ifndef __LIBXLPY_BOOK__
#define __LIBXLPY_BOOK__

#include "xlsxwriter.h"

typedef struct {
  PyObject_HEAD
  lxw_workbook *handler;
} PyXLSXBook;

#endif
