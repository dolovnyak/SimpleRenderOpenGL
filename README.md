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

Controls:
----------
- `up arrow`/`down arrow` - move current object to the up/down
- `left arrow`/`right arrow` - move current object to the left/right
- `shift` + `up arrow`/`down arrow` arrow - move current object to the forward/backward.
- `option` + `left arrow`/`right arrow` - rotate current object around the y axis.
- `option` + `up arrow`/`down arrow` arrow - rotate current object around the x axis.
- `1`/`2`/`3` - OpenGL draw mods: triangles/lines/points.
- `c` - switch to color mode.
- `t` - draw smoothly or with triangles in color mode.
- `>` - switch to next object.
- `<` - switch to previous object.

Build and run on `MacOS`:
---------
```
cmake -S . -B build -DINSTALL_DEPS=true
make -C build

./glsr jsons/'name.json'
```

Screenshots:
----------
![](https://github.com/dolovnyak/SimpleRenderOpenGL/blob/master/screenshots/mult_objs.gif)
![](https://github.com/dolovnyak/SimpleRenderOpenGL/blob/master/screenshots/awp1.png)
![](https://github.com/dolovnyak/SimpleRenderOpenGL/blob/master/screenshots/awp2.png)
![](https://github.com/dolovnyak/SimpleRenderOpenGL/blob/master/screenshots/awp3.png)
![](https://github.com/dolovnyak/SimpleRenderOpenGL/blob/master/screenshots/rock1.gif)
