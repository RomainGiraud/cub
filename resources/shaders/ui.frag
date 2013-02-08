#version 120

// From vertex shader
varying vec2 ex_TexCoord;

// Per batch
uniform sampler2D DiffuseTexture;

void main(void)
{
    gl_FragColor = texture2D(DiffuseTexture, ex_TexCoord);
}