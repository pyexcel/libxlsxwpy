import os
from libxlsxwpy import Book
from nose.tools import raises


def test_sheet():
    test_file = "test_sheet.xlsx"
    book = Book()
    book.open(test_file)
    sheet = book.add_sheet("hello world")
    data = [
        ['h', 'e', 'l', 'l', 'o'],
        ['w', 'o', 'r', 'l', 'd']
    ]
    for row, row_data in enumerate(data):
        for col, col_data in enumerate(row_data):
            sheet.write_string(row, col, col_data)
    book.close()
    os.unlink(test_file)


@raises(RuntimeError)
def test_sheet_exception():
    book = Book()
    book.add_sheet("hello world")
