#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture_coord;

flat out vec4 flatColor;
smooth out vec4 smoothColor;
out vec2 Texture_coord;

uniform mat4 transform;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * transform * vec4(position, 1.0);
    Texture_coord = texture_coord;
    flatColor = vec4(position.y * 0.4f + 0.4f, position.z * 0.6 + position.y * 0.6f + 0.2f, 0.4f, 1.0f);
    smoothColor = vec4(position.y * 0.4f + 0.4f, position.z * 0.6 + position.y * 0.6f + 0.2f, 0.4f, 1.0f);
}