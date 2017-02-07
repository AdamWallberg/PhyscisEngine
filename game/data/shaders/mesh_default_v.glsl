#version 330 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec2 in_uv;
layout(location = 3) in vec4 in_color;

out vec3 normal;
//out vec2 out_uv;
out vec4 color;

uniform mat4 u_matWorld;
uniform mat4 u_matView;
uniform mat4 u_matProj;
uniform mat4 u_matWorldViewProj;

void main(){

	gl_Position = u_matWorldViewProj * vec4(in_position,1);
	normal = in_normal * 0.5 + 0.5;
	color = vec4(1.0, 1.0, 0.0, 1.0);
	//gl_Position = vec4(in_vertex,1);
	//out_uv = in_vertex.uv;
	//out_color = in_vertex.color;
}