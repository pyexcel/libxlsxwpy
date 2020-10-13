================================================================================
libxlsxwpy - Let you focus on data, instead of file formats
================================================================================

.. image:: https://raw.githubusercontent.com/pyexcel/pyexcel.github.io/master/images/patreon.png
   :target: https://www.patreon.com/chfw

.. image:: https://cdn.rawgit.com/sindresorhus/awesome/d7305f38d29fed78fa85652e3a63e154dd8e8829/media/badge.svg
   :target: https://awesome-python.com/#specific-formats-processing

.. image:: https://travis-ci.org/pyexcel/libxlsxwpy.svg?branch=master
   :target: http://travis-ci.org/pyexcel/libxlsxwpy

.. image:: https://codecov.io/gh/pyexcel/libxlsxwpy/branch/master/graph/badge.svg
   :target: https://codecov.io/gh/pyexcel/libxlsxwpy

.. image:: https://badge.fury.io/py/libxlsxwpy.svg
   :target: https://pypi.org/project/libxlsxwpy


.. image:: https://pepy.tech/badge/libxlsxwpy/month
   :target: https://pepy.tech/project/libxlsxwpy/month


.. image:: https://img.shields.io/gitter/room/gitterHQ/gitter.svg
   :target: https://gitter.im/pyexcel/Lobby

.. image:: https://img.shields.io/static/v1?label=continuous%20templating&message=%E6%A8%A1%E7%89%88%E6%9B%B4%E6%96%B0&color=blue&style=flat-square
    :target: https://moban.readthedocs.io/en/latest/#at-scale-continous-templating-for-open-source-projects

.. image:: https://img.shields.io/static/v1?label=coding%20style&message=black&color=black&style=flat-square
    :target: https://github.com/psf/black

Support the project
================================================================================

If your company has embedded pyexcel and its components into a revenue generating
product, please support me on github, `patreon <https://www.patreon.com/bePatron?u=5537627>`_
or `bounty source <https://salt.bountysource.com/teams/chfw-pyexcel>`_ to maintain
the project and develop it further.

If you are an individual, you are welcome to support me too and for however long
you feel like. As my backer, you will receive
`early access to pyexcel related contents <https://www.patreon.com/pyexcel/posts>`_.

And your issues will get prioritized if you would like to become my patreon as `pyexcel pro user`.

With your financial support, I will be able to invest
a little bit more time in coding, documentation and writing interesting posts.


Known constraints
==================

Fonts, colors and charts are not supported.

Introduction
================================================================================
**libxlsxwpy** is a plain python wrapper for libxlsxwriter, a c library. And it only support writing strings for now.



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


Development guide
================================================================================

Development steps for code changes

#. git clone https://github.com/pyexcel/libxlsxwpy.git
#. cd libxlsxwpy

Upgrade your setup tools and pip. They are needed for development and testing only:

#. pip install --upgrade setuptools pip

Then install relevant development requirements:

#. pip install -r rnd_requirements.txt # if such a file exists
#. pip install -r requirements.txt
#. pip install -r tests/requirements.txt

Once you have finished your changes, please provide test case(s), relevant documentation
and update CHANGELOG.rst.

.. note::

    As to rnd_requirements.txt, usually, it is created when a dependent
    library is not released. Once the dependecy is installed
    (will be released), the future
    version of the dependency in the requirements.txt will be valid.


How to test your contribution
------------------------------

Although `nose` and `doctest` are both used in code testing, it is adviable that unit tests are put in tests. `doctest` is incorporated only to make sure the code examples in documentation remain valid across different development releases.

On Linux/Unix systems, please launch your tests like this::

    $ make

On Windows systems, please issue this command::

    > test.bat


Before you commit
------------------------------

Please run::

    $ make format

so as to beautify your code otherwise travis-ci may fail your unit test.




License
================================================================================

New BSD License
