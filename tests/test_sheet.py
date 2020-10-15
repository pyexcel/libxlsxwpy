import os
from collections import OrderedDict
from datetime import datetime

from nose.tools import eq_, raises
from pyexcel_xlsx import get_data

from libxlsxwpy import Book


def test_sheet():
    test_file = "test_sheet.xlsx"
    book = Book()
    book.open(test_file)
    sheet = book.add_worksheet("hello world")
    data = [
        ["h", "e", "l", "l", "o"],
        [1, 2, 3, 4, 5],
        [True, False, True, False, True],
        [
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
        ],
    ]
    string_row = 0
    for col, col_data in enumerate(data[string_row]):
        sheet.write_string(string_row, col, col_data)
    number_row = 1
    for col, col_data in enumerate(data[number_row]):
        sheet.write_number(number_row, col, col_data)
    boolean_row = 2
    for col, col_data in enumerate(data[boolean_row]):
        sheet.write_boolean(boolean_row, col, col_data)
    datetime_row = 3
    for col, col_data in enumerate(data[datetime_row]):
        sheet.write_datetime(
            datetime_row,
            col,
            col_data.year,
            col_data.month,
            col_data.day,
            col_data.hour,
            col_data.minute,
            col_data.second,
        )
    book.close()
    actual_data = get_data(test_file)
    os.unlink(test_file)

    expected = OrderedDict()
    expected["hello world"] = [
        ["h", "e", "l", "l", "o"],
        [1, 2, 3, 4, 5],
        [1, 0, 1, 0, 1],
        [
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
            datetime(2020, 1, 1, 1, 1, 2),
        ],
    ]
    eq_(actual_data, expected)


@raises(RuntimeError)
def test_sheet_exception():
    book = Book()
    book.add_worksheet("hello world")
