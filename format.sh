isort $(find libxlsxwpy -name "*.py"|xargs echo) $(find tests -name "*.py"|xargs echo)
black -l 79 libxlsxwpy
black -l 79 tests
