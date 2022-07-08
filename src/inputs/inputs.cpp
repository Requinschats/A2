#include "../Grid/Grid.h"
#include "glm/glm.hpp"
#include "inputs.h"
#include "glm/ext/matrix_transform.hpp"

using namespace glm;
float cameraSpeed = 5.0f;

void handleViewInputs(GLFWwindow *window,
                      int shaderProgram,
                      vec3 *cameraPosition,
                      vec3 *cameraLookAt,
                      vec3 *cameraUp,
                      float dt) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        glm::mat4 viewMatrix = glm::mat4(1.0f);

        GLuint viewMatrixLocation = glGetUniformLocation(shaderProgram, "viewMatrix");
        glUniformMatrix4fv(viewMatrixLocation, 1, GL_FALSE, &viewMatrix[0][0]);
    }

    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        cameraPosition->x -= cameraSpeed * dt;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        cameraPosition->x += cameraSpeed * dt;
    }
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraPosition->z -= cameraSpeed * dt;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraPosition->z += cameraSpeed * dt;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        
    }

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        cameraPosition->y += cameraSpeed * dt;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        cameraPosition->y -= cameraSpeed * dt;
    }
}

void handleActionInputs(GLFWwindow *window, float *olafXPosition, float *olafZPosition, float *olafScale) {
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        *olafXPosition = Grid::getRandomGridCoordinate();
        *olafZPosition = Grid::getRandomGridCoordinate();
    }
    if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
        *olafScale += 0.1f;
    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
        *olafScale -= 0.1f;
    }
}