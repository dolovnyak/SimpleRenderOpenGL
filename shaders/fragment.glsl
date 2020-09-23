#version 400 core

smooth in vec4 smoothColor;
flat in vec4 flatColor;
in vec2 Texture_coord;

out vec4 color;

uniform sampler2D ourTexture;
uniform int colorFlag;
uniform int flatFlag;

void main()
{
    if (colorFlag == 1)
    {
        if (flatFlag == 1)
            color = flatColor;
        else
            color = smoothColor;
    }
    else
        color = texture(ourTexture, Texture_coord);
}