#include <Python.h>
#include "xlsxwriter.h"
#include "book.h"
#include "sheet.h"

extern PyTypeObject PyXLSXSheetType;

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

  lxw_worksheet *sheet = workbook_add_worksheet(self->handler, name);
  if (!sheet) Py_RETURN_NONE;
  
  PyXLSXSheet *obj = PyObject_New(PyXLSXSheet, &PyXLSXSheetType);
  obj->handler = sheet;
  return (PyObject *)obj;
}


static void
dealloc(PyXLSXBook *self)
{
  self->ob_type->tp_free((PyObject*)self);
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
  {"add_sheet", (PyCFunction) add_worksheet, METH_VARARGS,
   "Add a sheet into the book"
   "Returns False if error occurs."},
  {"close", (PyCFunction) close_book, METH_VARARGS,
   "Close the file."
   "Returns False if error occurs."},
  {NULL}
};


PyTypeObject
PyXLSXBookType = {
  PyObject_HEAD_INIT(NULL)
  0,                         /* ob_size */
  "PyXLSXBook",              /* tp_name */
  sizeof(PyXLSXBook),        /* tp_basicsize */
  0,                         /* tp_itemsize */
  (destructor)dealloc,       /* tp_dealloc */
  0,                         /* tp_print */
  0,                         /* tp_getattr */
  0,                         /* tp_setattr */
  0,                         /* tp_compare */
  0,                         /* tp_repr */
  0,                         /* tp_as_number */
  0,                         /* tp_as_sequence */
  0,                         /* tp_as_mapping */
  0,                         /* tp_hash */
  0,                         /* tp_call */
  0,                         /* tp_str */
  0,                         /* tp_getattro */
  0,                         /* tp_setattro */
  0,                         /* tp_as_buffer */
  Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags*/
  "Py XLSX Book",            /* tp_doc */
  0,                         /* tp_traverse */
  0,                         /* tp_clear */
  0,                         /* tp_richcompare */
  0,                         /* tp_weaklistoffset */
  0,                         /* tp_iter */
  0,                         /* tp_iternext */
  methods,                   /* tp_methods */
  0,                         /* tp_members */
  0,                         /* tp_getset */
  0,                         /* tp_base */
  0,                         /* tp_dict */
  0,                         /* tp_descr_get */
  0,                         /* tp_descr_set */
  0,                         /* tp_dictoffset */
  (initproc)init,            /* tp_init */
  0,                         /* tp_alloc */
  0,                         /* tp_new */
};

