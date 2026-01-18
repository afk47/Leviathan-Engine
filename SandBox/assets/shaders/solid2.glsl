#type vertex
#version 330 core

struct Material {
   	// Ambient Color
	vec3 ambient;
	// Diffuse Color
	vec3 diffuse;
	// Specular Color
	vec3 specular;
	// Specular Exponent
	float shininess;
	// Optical Density
	float Ni;
	// Dissolve
	float d;
	// Illumination
	int illum;
}; 
  
layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec3 a_Normal;



uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;

out mat4 transform;
out vec3 v_Position;
out vec3 v_Normal;

void main()
{
	transform = transformMatrix;
	v_Position = a_Position;
	v_Normal = a_Normal;


	gl_Position = projectionMatrix * transformMatrix * vec4(a_Position, 1.0);	
}


#type fragment
#version 330 core

struct Material {
   	// Ambient Color
	vec3 ambient;
	// Diffuse Color
	vec3 diffuse;
	// Specular Color
	vec3 specular;
	// Specular Exponent
	float shininess;
	// Optical Density
	float Ni;
	// Dissolve
	float d;
	// Illumination
	int illum;
};

layout(location = 0) out vec4 color;
uniform Material material;
uniform vec3 viewPos;
in mat4 transform;
in vec3 v_Position;
in vec3 v_Normal;


void main()
{
	
	vec3 lightPos = vec3(20,20,0);
	vec3 lightColor = vec3(1);
	

	// ambient
    vec3 ambient = material.diffuse * vec3(0.2);
  	
    // diffuse 
    vec3 norm = normalize(v_Normal);
    vec3 lightDir = normalize(lightPos - v_Position);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = lightColor * (diff * material.diffuse);
    
    // specular
    vec3 viewDir = normalize(viewPos - v_Position);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = lightColor * (spec * material.specular);  
        
    vec3 result = (material.illum * ambient) + diffuse + specular;
	color = vec4(result, 1.0);
	

}
