================================================================================
libxlsxwpy - Let you focus on data, instead of file formats
================================================================================

.. image:: https://api.travis-ci.org/pyexcel/libxlsxwpy.svg?branch=master
   :target: http://travis-ci.org/pyexcel/libxlsxwpy

.. image:: https://codecov.io/github/pyexcel/libxlsxwpy/coverage.png
    :target: https://codecov.io/github/pyexcel/libxlsxwpy


**libxlsxwpy** is a plain python wrapper for libxlsxwriter, a c library. And it only support writing strings for now.

Known constraints
==================

Fonts, colors and charts are not supported.


Installation
================================================================================

First of all, please `install libxlsxwriter <http://libxlsxwriter.github.io/getting_started.html>`_. 

You can clone it and install it:

.. code-block:: bash

    $ git clone http://github.com/pyexcel/libxlsxwpy.git
    $ cd libxlsxwpy
    $ python setup.py build
    $ python setup.py install



Usage
--------------------

Here is the python code for `the equivalent C code <http://libxlsxwriter.github.io/getting_started.html>`_:

.. code-block:: python

    >>> from libxlsxwpy import Book
    >>> book = Book()
    >>> book.open("myexcel.xlsx")
    True
    >>> sheet = book.add_sheet()
    >>> sheet.write_string(0, 0, "Hello me!")
    True
    >>> book.close()
    True

.. testcode::
   :hide:

    >>> import os
    >>> os.unlink("myexcel.xlsx")


License
================================================================================

New BSD License
