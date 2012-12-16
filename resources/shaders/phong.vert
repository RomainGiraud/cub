#version 130

// Per vertex
in vec3 in_Position;
in vec3 in_Normal;

// Per batch
uniform mat4 mvMatrix;
uniform mat4 mvpMatrix;
uniform mat3 normalMatrix;

// To fragment shader
out vec3 ex_Position;
out vec3 ex_Normal;

void main(void)
{
    ex_Normal = normalize(normalMatrix * in_Normal);
    ex_Position = mvMatrix * vec4(in_Position, 1.0);

    gl_Position = mvpMatrix * vec4(in_Position, 1.0);
}