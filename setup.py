from setuptools import setup, Extension
from Cython.Build import cythonize

import platform
import os
import re

packagedir = "./pyompeval"

with open(os.path.join(packagedir, '__init__.py'), 'r') as initfile:
    version = re.search(r'^__version__\s*=\s*[\'"]([^\'"]*)[\'"]',
                        initfile.read(), re.MULTILINE).group(1)

extensions = [Extension('pyompeval.ompeval', ['./pyompeval/ompeval.pyx'],
                        include_dirs=["./"],
                        library_dirs=["./build/"],
                        libraries=['ompeval'],
                        extra_compile_args=[],
                        extra_link_args=[]
                        )]
extensions = cythonize(extensions)

setup(
    name="PyOmpEval",
    version=version,
    ext_modules=extensions,
    language="c++",
    packages=['pyompeval'],
    package_dir={'pyompeval': packagedir},
    package_data={'pyompeval': ['ompeval.pyx', 'ompeval.pxd']})
