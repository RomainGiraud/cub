#version 120

// Per vertex
attribute vec3 in_Position;

// Per batch
uniform mat4 mvpMatrix;


void main(void)
{
    gl_Position = mvpMatrix * vec4(in_Position, 1.0);
}