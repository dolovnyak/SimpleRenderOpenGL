#version 400 core

in vec3 ourColor;
in vec2 Texture_coord;

out vec4 color;

//uniform vec4 coefs;
uniform sampler2D ourTexture;

void main()
{
//    color = vec4(ourColor * vec3(coefs), 1.0f);
    color = texture(ourTexture, Texture_coord);
}