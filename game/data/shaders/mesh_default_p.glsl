#version 330 core

//in vec2 in_uv;
in vec3 normal;
in vec4 color;

out vec4 out_color;

void main()
{
	out_color = vec4(normal, 1.0);
}