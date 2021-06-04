# SimpleRenderOpenGL

## MacOS - ![Build](https://github.com/dolovnyak/SimpleRenderOpenGL/actions/workflows/cmake.yml/badge.svg?branch=master)

This is the OpenGL render with a minimum of functionality.
-----------

Implemented:
---------
- ### self-written .bmp reader.
- ### self-written .obj reader.
- ### self-written matrix mathematics including projection matrix.
- ### textures.
- ### setting with json.
- ### work with a full OpenGL pipeline.

Build and run on `MacOS`:
---------
```
cmake -S . -B build -DINSTALL_DEPS=true
make -C build

./glsr jsons/'name.json'
```
