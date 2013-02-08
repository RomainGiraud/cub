#version 120

// Per vertex
attribute vec3 in_Position;
attribute vec2 in_TexCoord;

// Per batch
uniform mat4 mvpMatrix;

// To fragment shader
varying vec2 ex_TexCoord;

void main(void)
{
    ex_TexCoord = in_TexCoord;
    gl_Position = mvpMatrix * vec4(in_Position, 1.0);
}