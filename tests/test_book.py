import os
from libxlsxwpy import Book


def test_book():
    test_file = "test.xlsx"
    b = Book()
    b.open(test_file)
    b.close()
    os.unlink(test_file)
