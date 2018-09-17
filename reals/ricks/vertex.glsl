#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vpos;

void main(){

    gl_Position.xyz = vpos;
    gl_Position.w = 1.0;

}

