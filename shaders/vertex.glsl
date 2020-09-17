#version 400 core

layout (location = 0) in vec3 position;
//layout (location = 1) in vec3 color;
layout (location = 1) in vec2 texture_coord;

out vec3 ourColor;
out vec2 Texture_coord;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * transform * vec4(position, 1.0);
//    ourColor = color;
    Texture_coord = texture_coord;
}