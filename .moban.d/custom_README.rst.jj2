{%extends 'BASIC-README.rst.jj2' %}

{%block documentation_link%}
{%endblock%}

{%block features%}
**{{name}}** is {{description|lower}} And it only support writing strings for now.
{%endblock%}

{%block custom_installation%}

First of all, please `install libxlsxwriter <http://libxlsxwriter.github.io/getting_started.html>`_. 

You can clone it and install it:

.. code-block:: bash

    $ git clone http://github.com/{{organisation}}/{{name}}.git
    $ cd {{name}}
    $ python setup.py build
    $ python setup.py install

{%endblock%}


{%block usage%}
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

{%endblock%}
