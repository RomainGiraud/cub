#version 120

// Per vertex
attribute vec3 in_Position;
attribute vec3 in_Normal;

// Per batch
uniform mat4 mvMatrix;
uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;

// To fragment shader
varying vec3 ex_Position;
varying vec3 ex_Normal;

void main(void)
{
    ex_Normal = normalize(normalMatrix * in_Normal);
    ex_Position = vec3(mvMatrix * vec4(in_Position, 1.0));

    gl_Position = mvpMatrix * vec4(in_Position, 1.0);
}