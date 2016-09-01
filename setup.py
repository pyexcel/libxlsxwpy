from distutils.core import setup, Extension

NAME = 'libxlsxwpy'
AUTHOR = 'C.W.'
VERSION = '0.0.1'
EMAIL = 'wangc_2011 (at) hotmail.com'
LICENSE = 'New BSD'
DESCRIPTION = (
    'A plain python wrapper for libxlsxwriter, a C library.' +
    ''
)
KEYWORDS = [
    'excel',
    'python',
    'pyexcel',
    'xlsx'
]

CLASSIFIERS = [
    'Topic :: Office/Business',
    'Topic :: Utilities',
    'Topic :: Software Development :: Libraries',
    'Programming Language :: Python',
    'License :: OSI Approved :: BSD License',
    'Intended Audience :: Developers',
    'Development Status :: 3 - Alpha',
    'Programming Language :: Python :: 2.6',
    'Programming Language :: Python :: 2.7',
    'Programming Language :: Python :: 3.3',
    'Programming Language :: Python :: 3.4',
    'Programming Language :: Python :: Implementation :: PyPy'
]

INSTALL_REQUIRES = [
    'xlsxwriter',
]


PYMODULE = Extension(
    'libxlsxwpy',
    sources=[
        'pymodule.c',
        'book.c',
        'sheet.c',
    ],
    libraries=INSTALL_REQUIRES
)


def read_files(*files):
    """Read files into setup"""
    text = ""
    for single_file in files:
        text = text + read(single_file) + "\n"
    return text


def read(afile):
    """Read a file into setup"""
    with open(afile, 'r') as opened_file:
        return opened_file.read()


if __name__ == '__main__':
    setup(
        name=NAME,
        author=AUTHOR,
        version=VERSION,
        author_email=EMAIL,
        description=DESCRIPTION,
        long_description=read_files('README.rst', 'CHANGELOG.rst'),
        license=LICENSE,
        keywords=KEYWORDS,
        ext_modules=[PYMODULE],
        classifiers=CLASSIFIERS
    )
