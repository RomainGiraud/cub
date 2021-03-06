#version 120

// Per vertex
attribute vec3 in_Position;
attribute vec3 in_Normal;
attribute vec2 in_TexCoord;

// Per batch
uniform mat4 mvMatrix;
uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;

// To fragment shader
varying vec3 ex_Position;
varying vec3 ex_Normal;
varying vec2 ex_TexCoord;

void main(void)
{
    ex_Normal = normalize(normalMatrix * in_Normal);
    ex_Position = vec3(mvMatrix * vec4(in_Position, 1.0));
    ex_TexCoord = in_TexCoord;

    gl_Position = mvpMatrix * vec4(in_Position, 1.0);
}