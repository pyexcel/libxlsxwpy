#include <Python.h>
#include "xlsxwriter.h"
#include "book.h"
#include "sheet.h"

extern PyTypeObject BookType;
extern PyTypeObject SheetType;
    
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "libxlsxwpy",     /* m_name */
        "libxlsxwriter for python",  /* m_doc */
        -1,                  /* m_size */
        NULL,    /* m_methods */
        NULL,                /* m_reload */
        NULL,                /* m_traverse */
        NULL,                /* m_clear */
        NULL,                /* m_free */
    };


PyMODINIT_FUNC
PyInit_libxlsxwpy(void)
{
  PyObject *m;
  if (PyType_Ready(&BookType) < 0)
    return NULL;
  if (PyType_Ready(&SheetType) < 0)
    return NULL;
  m = PyModule_Create(&moduledef);
  if (m == NULL)
    return NULL;

  Py_INCREF(&BookType);
  if (PyModule_AddObject(m, "Book", (PyObject *) &BookType) < 0) {
    Py_DECREF(&BookType);
    Py_DECREF(m);
    return NULL;
  }
  Py_INCREF(&SheetType);
  if (PyModule_AddObject(m, "Sheet", (PyObject *) &SheetType) < 0) {
    Py_DECREF(&SheetType);
    Py_DECREF(m);
    return NULL;
  }
  return m;
}

