#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

vec2 haha = vec2(TexCoord.s, -1 * TexCoord.t);

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1, TexCoord), texture(texture2, haha), vec4(texture(texture2, haha)).q * 0.2);
}
