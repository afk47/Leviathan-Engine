#type vertex
#version 330 core

layout(location = 0) in vec3 a_Position;
layout(location = 1) in vec2 a_TexCoord;

uniform mat4 transformMatrix;
uniform mat4 projectionMatrix;

out mat4 transform;
out vec3 v_Position;
out vec4 v_Color;
out vec2 v_TexCoord;
void main()
{
	transform = transformMatrix;
	v_Position = a_Position;
	v_TexCoord = a_TexCoord;
	gl_Position = projectionMatrix * transformMatrix * vec4(a_Position, 1.0);	
}


#type fragment
#version 330 core

layout(location = 0) out vec4 color;
in mat4 transform;
in vec3 v_Position;
in vec4 v_Color;

in vec2 v_TexCoord;
uniform sampler2D u_Texture;
void main()
{
	color = v_Color;
	color = vec4(v_Position * 0.5 + 0.5, 1.0);
	color = texture(u_Texture, v_TexCoord);
}
