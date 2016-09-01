

pip freeze
nosetests --with-cov --cover-package libxlsxwpy --cover-package tests --with-doctest --doctest-extension=.rst tests README.rst  && flake8 . --exclude=.moban.d --builtins=unicode,xrange,long
