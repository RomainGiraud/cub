#version 120

// From vertex shader
varying vec3 ex_Position;
varying vec3 ex_Normal;

// Light
struct LightInfo
{
    vec4 Position;  // Light position in eye coords
    vec3 La;        // Ambient light intensity
    vec3 Ld;        // Diffuse light intensity
    vec3 Ls;        // Specular light intensity
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

// Output color
//out vec4 color;

vec3 phongModel(vec3 position, vec3 norm)
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

    vec3 ambient = Light.La * Material.Ka;
    float sDotN = max(dot(s, norm), 0.0);
    vec3 diffuse = Light.Ld * Material.Kd * sDotN;
    vec3 spec = vec3(0.0);
    
    // Without halfway vector
    //if (sDotN > 0.0)
    //    spec = Light.Ls * Material.Ks * pow(max(dot(r,v), 0.0), Material.Shininess);
    // With halfway vector
    if (sDotN > 0.0)
        spec = Light.Ls * Material.Ks * pow(max(dot(h,norm), 0.0), Material.Shininess);


    return ambient + diffuse + spec;
}

void main(void)
{
	vec3 n = normalize(ex_Normal);
    
    if (gl_FrontFacing)
    	gl_FragColor = vec4(phongModel(ex_Position, n), 1.0);
    else
    	gl_FragColor = vec4(phongModel(ex_Position, -n), 1.0);
}