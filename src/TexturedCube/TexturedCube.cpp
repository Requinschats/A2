#include "TexturedCube.h"
#include "glm/glm.hpp"
//import opengl
#include <GL/glew.h>

using namespace glm;

struct TexturedColoredVertex {
    TexturedColoredVertex(vec3 _position, vec3 _color, vec2 _uv)
            : position(_position), color(_color), uv(_uv) {}

    vec3 position;
    vec3 color;
    vec2 uv;
};

const TexturedColoredVertex texturedCubeVertexArray[] = {  // position,                            color
        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)), //left - red
        TexturedColoredVertex(vec3(-0.5f, -0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),

        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f, 0.0f, 0.0f), vec2(1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)), // far - blue
        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f)), // bottom - turquoise
        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, -0.5f, -0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, -0.5f, -0.5f), vec3(0.0f, 1.0f, 1.0f), vec2(0.0f, 0.0f)),

        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f)), // near - green
        TexturedColoredVertex(vec3(-0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f)),
        TexturedColoredVertex(vec3(0.5f, -0.5f, 0.5f), vec3(0.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)), // right - purple
        TexturedColoredVertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, -0.5f, -0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(0.5f, -0.5f, 0.5f), vec3(1.0f, 0.0f, 1.0f), vec2(0.0f, 1.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)), // top - yellow
        TexturedColoredVertex(vec3(0.5f, 0.5f, -0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)),

        TexturedColoredVertex(vec3(0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(1.0f, 1.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, -0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 0.0f)),
        TexturedColoredVertex(vec3(-0.5f, 0.5f, 0.5f), vec3(1.0f, 1.0f, 0.0f), vec2(0.0f, 1.0f))
};

int createTexturedCubeVertexArrayObject() {
    GLuint vertexArrayObject;
    glGenVertexArrays(1, &vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    GLuint vertexBufferObject;
    glGenBuffers(1, &vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER, sizeof(texturedCubeVertexArray), texturedCubeVertexArray, GL_STATIC_DRAW);

    glVertexAttribPointer(0,                   // attribute 0 matches aPos in Vertex Shader
                          3,                   // size
                          GL_FLOAT,            // type
                          GL_FALSE,            // normalized?
                          sizeof(TexturedColoredVertex), // stride - each vertex contain 2 vec3 (position, color)
                          (void *) 0             // array buffer offset
    );
    glEnableVertexAttribArray(0);


    glVertexAttribPointer(1,                            // attribute 1 matches aColor in Vertex Shader
                          3,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void *) sizeof(vec3)      // color is offseted a vec3 (comes after position)
    );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2,                            // attribute 2 matches aUV in Vertex Shader
                          2,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(TexturedColoredVertex),
                          (void *) (2 * sizeof(vec3))      // uv is offseted by 2 vec3 (comes after position and color)
    );
    glEnableVertexAttribArray(2);

    return vertexArrayObject;
}

void DrawTexturedCube(int vertexArrayObject) {
    int texturedShaderProgram = compileAndLinkShaders(getTexturedVertexShaderSource(),
                                                      getTexturedFragmentShaderSource());
    int texturedCubeVAO = createTexturedCubeVertexArrayObject();
    glBindVertexArray(texturedCubeVAO);
    glUseProgram(texturedShaderProgram);
}

