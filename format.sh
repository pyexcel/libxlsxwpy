isort $(find tests -name "*.py"|xargs echo)
black -l 79 tests
