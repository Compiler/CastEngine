#version 460
#extension GL_ARB_separate_shader_objects : enable


layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec4 a_position;
layout(location = 1) in vec4 a_color;
layout(location = 2) in vec4 a_normal;
layout(location = 3) in mat4 a_model;


layout(location = 0) out vec4 o_color;
layout(location = 1) out vec4 o_normal;
layout(location = 2) out vec4 o_fragPos;

void main() {
    gl_Position = ubo.proj * ubo.view * a_model * a_position;
    o_fragPos = a_model * a_position;
    o_color = a_color;
    o_normal = a_model * a_normal;
}