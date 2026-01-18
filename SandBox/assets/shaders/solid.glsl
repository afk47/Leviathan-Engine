#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;

uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;

out mat4 transform;
out vec3 v_Position;
out vec4 v_Color;
void main()
{
	transform = transformMatrix;
	v_Position = a_Position;
	gl_Position = projectionMatrix * transformMatrix * vec4(a_Position, 1.0);	
}


#type fragment
#version 330 core

layout(location = 0) out vec4 color;
in mat4 transform;
in vec3 v_Position;
in vec4 v_Color;


void main()
{
	color = v_Color;
	color = vec4(1.0, 0.0, 0.0, 1.0);

}
