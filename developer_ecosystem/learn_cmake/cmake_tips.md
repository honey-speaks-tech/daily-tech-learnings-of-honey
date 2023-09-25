# cmake wisdom nuggets

### Documentation in cmake module
#### Wisdom nugget 1:
- Comments in the following format in headers of `.cmake` are parsed as documentation
```
#[====================[.rst:

#]====================]
```
- Cmake implements a Sphinx extension module that adds a `cmake-module` directive. 
  - The directive is used by each Help/module/*.rst file to parse documentation blocks out of a .cmake file.

- Reference : [CMake forum](https://discourse.cmake.org/t/how-does-cmake-docs-use-sphinx-to-parse-comments-in-cmake-files/8593)
