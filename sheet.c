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
  self->ob_type->tp_free((PyObject*)self);
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



PyTypeObject
PyXLSXSheetType = {
  PyObject_HEAD_INIT(NULL)
  0,                         /* ob_size */
  "PyXLSXSheet",             /* tp_name */
  sizeof(PyXLSXSheet),       /* tp_basicsize */
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
  "Py XLSX Sheet",           /* tp_doc */
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

