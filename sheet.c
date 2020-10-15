#include <Python.h>
#include "xlsxwriter.h"
#include "sheet.h"

static int
init(PyXLSXSheet *self)
{
  self->handler = NULL;
  self->book = NULL;
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

static PyObject *
write_number(PyXLSXSheet *self, PyObject *args)
{
  int row, col;
  double val;

  if(!PyArg_ParseTuple(args, "iid", &row, &col, &val)) return NULL;
  worksheet_write_number(self->handler, row, col, val, NULL);

  Py_RETURN_TRUE;
    
}

static PyObject *
write_boolean(PyXLSXSheet *self, PyObject *args)
{
  int row, col, val;

  if(!PyArg_ParseTuple(args, "iii", &row, &col, &val)) return NULL;
  worksheet_write_boolean(self->handler, row, col, val, NULL);

  Py_RETURN_TRUE;
    
}
static PyObject *
write_datetime(PyXLSXSheet *self, PyObject *args)
{
  int row, col, year, month, day, hour, minute;
  double second;

  if(!PyArg_ParseTuple(args, "iiiiiiid", &row, &col, &year, &month, &day, &hour, &minute, &second)) return NULL;
  lxw_datetime datetime = {year, month, day, hour, minute, second};
  lxw_format    *format    = workbook_add_format(self->book);
  format_set_num_format(format, "mmm d yyyy hh:mm AM/PM");
  worksheet_write_datetime(self->handler, row, col, &datetime, format);

  Py_RETURN_TRUE;
    
}

static PyMethodDef methods[] = {
  {"write_string", (PyCFunction) write_string, METH_VARARGS,
   "Random write a string into a cell"
   "Returns False if error occurs."},
  {"write_boolean", (PyCFunction) write_boolean, METH_VARARGS,
   "Random write a boolean into a cell"
   "Returns False if error occurs."},
  {"write_number", (PyCFunction) write_number, METH_VARARGS,
   "Random write a number into a cell"
   "Returns False if error occurs."},
  {"write_datetime", (PyCFunction) write_datetime, METH_VARARGS,
   "Random write a number into a cell"
   "Returns False if error occurs."},
  {NULL}
};


PyTypeObject SheetType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "sheet",
    .tp_doc = "sheet definition",
    .tp_basicsize = sizeof(PyXLSXSheet),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) init,
    .tp_dealloc = (destructor) dealloc,
    .tp_methods = methods,
};
