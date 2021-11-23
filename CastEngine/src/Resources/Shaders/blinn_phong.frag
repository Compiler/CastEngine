#version 460
#extension GL_ARB_separate_shader_objects : enable


layout(location = 0) in vec4 o_color;
layout(location = 1) in vec4 o_normal;
layout(location = 2) in vec4 o_fragPos;

layout(location = 0) out vec4 FragColor;

void main(){

    vec3 lightPos = vec3(2.0f, 1.0f, 5.0f);
    vec3 lightColor = vec3(1.0f);
    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;
    vec3 norm = normalize(o_normal.xyz);
    vec3 lightDir = normalize(lightPos - o_fragPos.xyz);  

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (diffuse + ambient) * o_color.xyz;

    FragColor = vec4(result, o_color.w);
    
} 
