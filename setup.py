#!/usr/bin/env python3

"""
Template by pypi-mobans
"""

import os
import sys
import codecs
import locale
import platform
from shutil import rmtree

from distutils.core import setup, Extension


# Work around mbcs bug in distutils.
# http://bugs.python.org/issue10945
# This work around is only if a project supports Python < 3.4

# Work around for locale not being set
try:
    lc = locale.getlocale()
    pf = platform.system()
    if pf != "Windows" and lc == (None, None):
        locale.setlocale(locale.LC_ALL, "C.UTF-8")
except (ValueError, UnicodeError, locale.Error):
    locale.setlocale(locale.LC_ALL, "en_US.UTF-8")

NAME = "libxlsxwpy"
AUTHOR = "chfw"
VERSION = "0.0.1"
EMAIL = "info@pyexcel.org"
LICENSE = "New BSD"
DESCRIPTION = (
    "A plain python wrapper for libxlsxwriter, a C library."
)
URL = "https://github.com/pyexcel/libxlsxwpy"
DOWNLOAD_URL = "%s/archive/0.0.1.tar.gz" % URL
FILES = ["README.rst", "CHANGELOG.rst"]
KEYWORDS = [
    "python",
    'xlsx'
]

CLASSIFIERS = [
    "Topic :: Software Development :: Libraries",
    "Programming Language :: Python",
    "Intended Audience :: Developers",

    "Programming Language :: Python :: 3 :: Only",



    "Programming Language :: Python :: 3.6",
    "Programming Language :: Python :: 3.7",
    "Programming Language :: Python :: 3.8",

    'Development Status :: 3 - Alpha',
    'Programming Language :: Python :: 2.6',
    'Programming Language :: Python :: 2.7',
    'Programming Language :: Python :: 3.3',
    'Programming Language :: Python :: 3.4',
    'Programming Language :: Python :: Implementation :: PyPy'
]

PYTHON_REQUIRES = ">=3.6"

INSTALL_REQUIRES = [
    "xlsxwriter",
]
SETUP_COMMANDS = {}

PYMODULE = Extension(
    'libxlsxwpy',
    sources=[
        "pymodule.c",
        "book.c",
        "sheet.c",
    ],
    libraries=INSTALL_REQUIRES
)
# You do not need to read beyond this line
PUBLISH_COMMAND = "{0} setup.py sdist bdist_wheel upload -r pypi".format(sys.executable)
HERE = os.path.abspath(os.path.dirname(__file__))


def has_gease():
    """
    test if github release command is installed

    visit http://github.com/moremoban/gease for more info
    """
    try:
        import gease  # noqa
        return True
    except ImportError:
        return False


def read_files(*files):
    """Read files into setup"""
    text = ""
    for single_file in files:
        content = read(single_file)
        text = text + content + "\n"
    return text


def read(afile):
    """Read a file into setup"""
    the_relative_file = os.path.join(HERE, afile)
    with codecs.open(the_relative_file, "r", "utf-8") as opened_file:
        content = filter_out_test_code(opened_file)
        content = "".join(list(content))
        return content


def filter_out_test_code(file_handle):
    found_test_code = False
    for line in file_handle.readlines():
        if line.startswith(".. testcode:"):
            found_test_code = True
            continue
        if found_test_code is True:
            if line.startswith("  "):
                continue
            else:
                empty_line = line.strip()
                if len(empty_line) == 0:
                    continue
                else:
                    found_test_code = False
                    yield line
        else:
            for keyword in ["|version|", "|today|"]:
                if keyword in line:
                    break
            else:
                yield line


if __name__ == "__main__":
    setup(
        test_suite="tests",
        name=NAME,
        author=AUTHOR,
        version=VERSION,
        author_email=EMAIL,
        description=DESCRIPTION,
        url=URL,
        download_url=DOWNLOAD_URL,
        long_description=read_files(*FILES),
        license=LICENSE,
        keywords=KEYWORDS,
        ext_modules=[PYMODULE],
        classifiers=CLASSIFIERS,
    )
