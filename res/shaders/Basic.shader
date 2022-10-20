#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec2 textCo;

out vec2 v_TextCo;

void main() 
{
	gl_Position = position;
	v_TextCo = textCo;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec2 v_TextCo;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
	vec4 textCoolor = texture(u_Texture, textCo)
	color = textColor;
};