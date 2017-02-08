#version 330 core

struct SPixel
{
	vec3 normal;
	vec2 uv;
	vec4 color;
};

in SPixel PS;

out vec4 out_color;

void main()
{
	out_color = vec4(PS.normal, 1.0);
}