#version 330 core

struct SPixel
{
	vec3 normal;
	vec3 worldNormal;
	vec2 uv;
	vec4 color;
};

in SPixel PS;

out vec4 out_color;

void main()
{
	out_color = vec4(PS.worldNormal, 1.0);
}