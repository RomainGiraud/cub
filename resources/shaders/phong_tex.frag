#version 120

// From vertex shader
varying vec3 ex_Position;
varying vec3 ex_Normal;
varying vec2 ex_TexCoord;

// Light
struct LightInfo
{
    vec4 Position;  // Light position in eye coords
    vec3 Intensity; // Ambient light intensity
};
uniform LightInfo Light;

struct MaterialInfo
{
    vec3 Ka; // Ambient reflectivity
    vec3 Kd; // Diffuse reflectivity
    vec3 Ks; // Specular reflectivity
    float Shininess; // Specular shininess factor
};
uniform MaterialInfo Material;

uniform sampler2D Tex1;

// Output color
//out vec4 color;

vec4 phongModel(vec3 position, vec3 norm, vec4 texColor)
{
    //vec3 s = normalize(vec3(Light.Position) - position);

    // W == 0 => directionnal light source
    vec3 s;
	if (Light.Position.w == 0.0)
		s = normalize(vec3(Light.Position));
	else
    	s = normalize(vec3(Light.Position) - position);

    vec3 v = normalize(-position);
    //vec3 r = reflect(-s, norm);
    vec3 h = normalize(v + s);

    vec3 ambient = Light.Intensity * Material.Ka;
    float sDotN = max(dot(s, norm), 0.0);
    vec3 diffuse = Light.Intensity * Material.Kd * sDotN;
    vec3 spec = vec3(0.0);
    
    // Without halfway vector
    //if (sDotN > 0.0)
    //    spec = Light.Intensity * Material.Ks * pow(max(dot(r,v), 0.0), Material.Shininess);
    // With halfway vector
    if (sDotN > 0.0)
        spec = Light.Intensity * Material.Ks * pow(max(dot(h,norm), 0.0), Material.Shininess);


    return vec4(ambient + diffuse, 1.0) * texColor + vec4(spec, 1.0);
}

void main(void)
{
	vec3 n = normalize(ex_Normal);
    vec4 tex = texture2D(Tex1, ex_TexCoord);

    if (gl_FrontFacing)
    	gl_FragColor = phongModel(ex_Position, n, tex);
    else
    	gl_FragColor = phongModel(ex_Position, -n, tex);
}