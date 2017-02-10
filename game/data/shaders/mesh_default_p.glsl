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

uniform sampler2D u_textureSampler;

void main()
{
	out_color = texture(u_textureSampler, PS.uv);
}