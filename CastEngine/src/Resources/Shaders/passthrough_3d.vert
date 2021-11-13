#version 460
#extension GL_ARB_separate_shader_objects : enable


layout(binding = 0) uniform UniformBufferObject {
    mat4 model;
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec4 a_position;
layout(location = 1) in vec4 a_color;

layout(location = 0) out vec4 o_color;

void main() {
    gl_Position = ubo.proj * ubo.view * ubo.model * vec4(a_position.xy, 0.0, 1.0);
    o_color = a_color;
}