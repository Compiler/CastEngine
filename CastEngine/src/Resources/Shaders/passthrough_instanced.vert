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

// layout(location = 3) in vec4 a_model_c1;
// layout(location = 4) in vec4 a_model_c2;
// layout(location = 5) in vec4 a_model_c3;
// layout(location = 6) in vec4 a_model_c4;

layout(location = 0) out vec4 o_color;

void main() {
    // mat4 a_model = mat4(1);
    // a_model[0] = a_model_c1;
    // a_model[1] = a_model_c2;
    // a_model[2] = a_model_c3;
    // a_model[3] = a_model_c4;
    gl_Position = ubo.proj * ubo.view * a_model * vec4(a_position.xyz, 1.0);
    o_color = a_color;
}