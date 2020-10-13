#/bin/bash
pip freeze
nosetests --with-coverage --cover-package libxlsxwpy --cover-package tests tests --with-doctest --doctest-extension=.rst README.rst docs/source 
