#include <Python.h>
#include "xlsxwriter.h"
#include "book.h"
#include "sheet.h"

extern PyTypeObject SheetType;

static int
init(PyXLSXBook *self)
{
  self->handler = NULL;
  return 0;
}


static PyObject *
open_book(PyXLSXBook *self, PyObject *args)
{
  const char* fileName;
  if(!PyArg_ParseTuple(args, "s", &fileName))
    return NULL;
  self->handler = workbook_new(fileName);
  Py_RETURN_TRUE;
}


static PyObject *
add_worksheet(PyXLSXBook *self, PyObject *args)
{
  const char* name;
  if(!PyArg_ParseTuple(args, "|s", &name))
    return NULL;

  if(!self->handler){
    PyErr_SetString(PyExc_RuntimeError, "No file name specified");
    return NULL;
  }

  lxw_worksheet *sheet = workbook_add_worksheet(self->handler, name);
  if (!sheet) Py_RETURN_NONE;
  
  PyXLSXSheet *obj = PyObject_New(PyXLSXSheet, &SheetType);
  obj->handler = sheet;
  obj->book = self->handler;
  return (PyObject *)obj;
}


static void
dealloc(PyXLSXBook *self)
{
  PyObject_Free(self);
}


static PyObject *
close_book(PyXLSXBook *self)
{
  workbook_close(self->handler);
  Py_RETURN_TRUE;
}


static PyMethodDef methods[] = {
  {"open", (PyCFunction) open_book, METH_VARARGS,
   "Open a file for writing"
   "Returns False if error occurs."},
  {"add_worksheet", (PyCFunction) add_worksheet, METH_VARARGS,
   "Add a sheet into the book"
   "Returns False if error occurs."},
  {"close", (PyCFunction) close_book, METH_VARARGS,
   "Close the file."
   "Returns False if error occurs."},
  {NULL}
};

PyTypeObject BookType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "book",
    .tp_doc = "book definition",
    .tp_basicsize = sizeof(PyXLSXBook),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) init,
    .tp_dealloc = (destructor) dealloc,
    .tp_methods = methods,
};
