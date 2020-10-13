#include <Python.h>
#include "xlsxwriter.h"
#include "sheet.h"

static int
init(PyXLSXSheet *self)
{
  self->handler = NULL;
  return 0;
}

static void
dealloc(PyXLSXSheet *self)
{
  PyObject_Free(self);
}

static PyObject *
write_string(PyXLSXSheet *self, PyObject *args)
{
  int row, col;
  const char *val;

  if(!PyArg_ParseTuple(args, "iis", &row, &col, &val)) return NULL;
  worksheet_write_string(self->handler, row, col, val, NULL);

  Py_RETURN_TRUE;
    
}

static PyMethodDef methods[] = {
  {"write_string", (PyCFunction) write_string, METH_VARARGS,
   "Random write a string into a cell"
   "Returns False if error occurs."},
  {NULL}
};


PyTypeObject SheetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "book",
    .tp_doc = "book definition",
    .tp_basicsize = sizeof(PyXLSXSheet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) init,
    .tp_dealloc = (destructor) dealloc,
    .tp_methods = methods,
};
