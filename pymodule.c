#include <Python.h>
#include "xlsxwriter.h"
#include "book.h"


extern PyTypeObject PyXLSXBookType;
extern PyTypeObject PyXLSXSheetType;


#define INIT_TYPE(Type) \
  Type.tp_new = PyType_GenericNew; \
  if (PyType_Ready(&Type) < 0) return; \
  Py_INCREF(&Type)


PyMODINIT_FUNC
initlibxlsxwpy(void)
{
  PyObject *mod;
  mod = Py_InitModule3("libxlsxwpy", NULL, "libxlsxwriter for python");
  INIT_TYPE(PyXLSXBookType);  
  INIT_TYPE(PyXLSXSheetType);  
  PyModule_AddObject(mod, "Book", (PyObject* )&PyXLSXBookType);
  PyModule_AddObject(mod, "Sheet", (PyObject* )&PyXLSXSheetType);
}

