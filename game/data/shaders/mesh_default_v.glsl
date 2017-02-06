#version 330 core

struct SVertex
{
	vec3 position;
	vec3 normal;
	vec2 uv;
	vec4 color;
};

layout(location = 0) in SVertex in_vertex;

out vec2 out_uv;
out vec4 out_color;

uniform mat4 u_matWorldViewProj;

void main(){

	//gl_Position = u_matWorldViewProj * vec4(in_vertex.position,1);
	gl_Position = vec4(in_vertex.position,1);
	out_uv = in_vertex.uv;
	out_color = in_vertex.color;
}