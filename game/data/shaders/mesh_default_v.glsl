#version 330 core

struct SVertex
{
	vec3 position;
	vec3 normal;
	vec2 uv;
	vec4 color;
};

struct SPixel
{
	vec3 normal;
	vec3 worldNormal;
	vec2 uv;
	vec4 color;
};

layout(location = 0) in SVertex VS;

out SPixel PS;

uniform mat4 u_matWorld;
uniform mat4 u_matView;
uniform mat4 u_matProj;
uniform mat4 u_matWorldViewProj;

void main()
{
	gl_Position = u_matWorldViewProj * vec4(VS.position,1);
	PS.normal = VS.normal * 0.5 + 0.5;
	PS.worldNormal = (u_matWorld * vec4( VS.normal, 0.0 )).xyz * 0.5 + 0.5;
	PS.color = VS.color;
	PS.uv = VS.uv;
}





