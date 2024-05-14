/*
Type your name and student ID here
    - Name: HUI Rocky   
    - Student ID: 1155172012
*/



#include "Dependencies/glew/glew.h"
#include "Dependencies/GLFW/glfw3.h"

#include "Dependencies/glm/glm.hpp"
#include "Dependencies/glm/gtc/matrix_transform.hpp"

#include <iostream>
#include <fstream>


GLuint programID;
float x_delta = 0.0f;
float z_delta = 0.0f;
float obj_scale = 1.0f;

float x_eye = 0.0f;
float y_eye = 3.0f;
float z_eye = 5.0f;
float eye_hangle_delta = 0.01f;
float eye_vangle_delta = 0.01f;
float x_center = 0.0f;
float y_center = 3.0f;
float z_center = 0.0f;

GLuint vao[2];
GLuint vbo[2];
GLuint vbo_idx[2];

bool reverse = false;
float planets_angle = 0.0f;


void get_OpenGL_info() {
    // OpenGL information
    const GLubyte* name = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* glversion = glGetString(GL_VERSION);
    std::cout << "OpenGL company: " << name << std::endl;
    std::cout << "Renderer name: " << renderer << std::endl;
    std::cout << "OpenGL version: " << glversion << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}



void sendDataToOpenGL() {

    glGenVertexArrays(2, vao);
    glGenBuffers(2, vbo);
    glGenBuffers(2, vbo_idx);

    // Runway
    const GLfloat runway[] = {
        -5.0f, +0.0f, -20.0f,    // 0
        +0.78f, +0.78f, +0.78f,

        +5.0f, +0.0f, -20.0f,    // 1
        +0.78f, +0.78f, +0.78f,

        -5.0f, +0.0f, +20.0f,    // 2
        +0.78f, +0.78f, +0.78f,

        +5.0f, +0.0f, +20.0f,    // 3
        +0.78f, +0.78f, +0.78f,

        +0.25f, +0.01f, -18.0f,  // 4
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, -14.0f,  // 5
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -14.0f, // 6
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -18.0f, // 7
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, -12.0f,  // 8
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, -8.0f,  // 9
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -8.0f, // 10
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -12.0f, // 11
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, -6.0f,  // 12
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, -2.0f,  // 13
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -2.0f, // 14
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, -6.0f, // 15
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +0.0f,  // 16
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +4.0f,  // 17
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +4.0f, // 18
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +0.0f, // 19
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +6.0f,  // 20
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +10.0f,  // 21
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +10.0f, // 22
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +6.0f, // 23
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +12.0f,  // 24
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +16.0f,  // 25
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +16.0f, // 26
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +12.0f, // 27
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +18.0f,  // 28
        +1.0f, +1.0f, +1.0f,

        +0.25f, +0.01f, +20.0f,  // 29
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +20.0f, // 30
        +1.0f, +1.0f, +1.0f,

        -0.25f, +0.01f, +18.0f, // 31
        +1.0f, +1.0f, +1.0f,
    };
    GLushort runway_idx[] = {
        0, 1, 2, 
        2, 3, 1,
        4, 5, 6,
        4, 7, 6,
        8, 9, 10,
        8, 11, 10,
        12, 13, 14,
        12, 15, 14,
        16, 17, 18,
        16, 19, 18,
        20, 21, 22,
        20, 23, 22,
        24, 25, 26,
        24, 27, 26,
        28, 29, 30,
        28, 31, 30,
    };

    glBindVertexArray(vao[0]);  //first VAO
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(runway), runway, GL_STATIC_DRAW);
    // vertex position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    // vertex color
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (char*)(3 * sizeof(float)));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_idx[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(runway_idx), runway_idx, GL_STATIC_DRAW);
    glBindVertexArray(0);

    //// OBJ
    const GLfloat triangle[] =
    {
        +0.0f, +1.0f, +2.0f,  // pos 0
        +1.0f, +0.0f, +0.0f,

        +0.0f, +1.0f, +0.0f,  // pos 1
        +1.0f, +0.0f, +0.0f,

        +0.1f, +1.5f, +1.75f,  // pos 2
        +1.0f, +0.0f, +0.0f,

        -0.1f, +1.5f, +1.75f,  // pos 3
        +1.0f, +0.0f, +0.0f,

        +0.1f, +1.5f, +0.0f,  // pos 4
        +1.0f, +0.0f, +0.0f,

        -0.1f, +1.5f, +0.0f,  // pos 5
        +1.0f, +0.0f, +0.0f,

        +1.1f, +1.5f, +0.0f,  // pos 6
        +1.0f, +0.0f, +0.0f,

        -1.1f, +1.5f, +0.0f,  // pos 7
        +1.0f, +0.0f, +0.0f,
    };
    GLushort tri_idx[] = {
        6, 4, 2,
        2, 0, 1,
        1, 4, 2,
        0, 3, 1,
        1, 5, 3,
        3, 7, 5,
    };
    glBindVertexArray(vao[1]); 
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    //// vertex position
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    //// vertex color
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (char*)(3 * sizeof(float)));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo_idx[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(tri_idx), tri_idx, GL_STATIC_DRAW);
    glBindVertexArray(0);

}

bool checkStatus(
    GLuint objectID,
    PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
    PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
    GLenum statusType)
{
    GLint status;
    objectPropertyGetterFunc(objectID, statusType, &status);
    if (status != GL_TRUE)
    {
        GLint infoLogLength;
        objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* buffer = new GLchar[infoLogLength];

        GLsizei bufferSize;
        getInfoLogFunc(objectID, infoLogLength, &bufferSize, buffer);
        std::cout << buffer << std::endl;

        delete[] buffer;
        return false;
    }
    return true;
}

bool checkShaderStatus(GLuint shaderID) {
    return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool checkProgramStatus(GLuint programID) {
    return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS);
}

std::string readShaderCode(const char* fileName) {
    std::ifstream meInput(fileName);
    if (!meInput.good()) {
        std::cout << "File failed to load ... " << fileName << std::endl;
        exit(1);
    }
    return std::string(
        std::istreambuf_iterator<char>(meInput),
        std::istreambuf_iterator<char>()
    );
}

void installShaders() {
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* adapter[1];
    //adapter[0] = vertexShaderCode;
    std::string temp = readShaderCode("VertexShaderCode.glsl");
    adapter[0] = temp.c_str();
    glShaderSource(vertexShaderID, 1, adapter, 0);
    //adapter[0] = fragmentShaderCode;
    temp = readShaderCode("FragmentShaderCode.glsl");
    adapter[0] = temp.c_str();
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);

    if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
        return;

    programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    if (!checkProgramStatus(programID))
        return;
    glUseProgram(programID);

}

void initializedGL(void) {
    // run only once
    sendDataToOpenGL();
    installShaders();
}

void paintGL(void) {
    // always run
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);  //specify the background color
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(x_eye, y_eye, z_eye), glm::vec3(x_center, y_center, z_center), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projectionMatrix = glm::perspective(glm::radians(45.0f), 8.0f / 6.0f, 0.1f, 100.0f);

    


    // Runway
    glBindVertexArray(vao[0]);
    glm::mat4 modelTransformMatrix = glm::mat4(1.0f);
    modelTransformMatrix = projectionMatrix * viewMatrix * modelTransformMatrix;
    GLint modelTransformMatrixUniformLocation = glGetUniformLocation(programID, "modelTransformMatrix");
    glUniformMatrix4fv(modelTransformMatrixUniformLocation, 1, GL_FALSE, &modelTransformMatrix[0][0]);
    glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);


    // Triangle
    glBindVertexArray(vao[1]);
    modelTransformMatrix = glm::mat4(1.0f);
    modelTransformMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(x_delta, 0.0f, z_delta)) * glm::scale(glm::mat4(1.0f), glm::vec3(obj_scale));
    modelTransformMatrix = projectionMatrix * viewMatrix * modelTransformMatrix;
    modelTransformMatrixUniformLocation = glGetUniformLocation(programID, "modelTransformMatrix");
    glUniformMatrix4fv(modelTransformMatrixUniformLocation, 1, GL_FALSE, &modelTransformMatrix[0][0]);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, 0);
    glBindVertexArray(0);


}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (key == GLFW_KEY_Q && action == GLFW_PRESS) {
        obj_scale++;
    }
    if (key == GLFW_KEY_E && action == GLFW_PRESS && obj_scale > 1.0f) {
        obj_scale--;
    }
    if (key == GLFW_KEY_W && action == GLFW_PRESS && z_delta > -19.0f) {
        z_delta == 6.0f ? z_delta -= 2 : z_delta--;
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS && z_delta < 19.0f) {
        z_delta == 4.0f ? z_delta += 2 : z_delta++;
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS && x_delta > -19.0f) {
        x_delta--;
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS && x_delta < 19.0f) {
        x_delta++;
    }
}


double old_xpos, old_ypos;
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (old_xpos && old_ypos) {
        glm::vec4 v = glm::vec4(glm::vec3(x_center, y_center, z_center), 1.0f);
        v = glm::translate(glm::mat4(1.0f), glm::vec3(-x_eye, -y_eye, -z_eye)) * v;  // Translate the eye to the origin
        float xspeed = eye_hangle_delta * (old_xpos - xpos);
        float yspeed = eye_vangle_delta * (old_ypos - ypos);
        v = glm::rotate(glm::mat4(1.0f), xspeed, glm::vec3(0.0f, 1.0f, 0.0f)) * v;  // To horizontally control the view

        // To vertically control the view
        float radius = glm::distance(glm::vec3(x_eye, y_eye, z_eye), glm::vec3(x_center, y_center, z_center));
        float eye_hangle = glm::asin(v.x / radius);
        eye_hangle = v.z > 0 ? glm::radians(180.0f) - eye_hangle : eye_hangle;
        v = glm::rotate(glm::mat4(1.0f), eye_hangle, glm::vec3(0.0f, 1.0f, 0.0f)) * v;  // Rotate the view towards z-negative
        v = glm::rotate(glm::mat4(1.0f), yspeed, glm::vec3(1.0f, 0.0f, 0.0f)) * v;
        float eye_vangle = glm::acos(glm::abs(v.y) / radius);
        // To prevent the view going over the head or the legs
        if (eye_vangle < 0.1f) {
            if (v.y < 0)
                v = glm::rotate(glm::mat4(1.0f), 0.1f - eye_vangle, glm::vec3(1.0f, 0.0f, 0.0f)) * v;
            else
                v = glm::rotate(glm::mat4(1.0f), eye_vangle - 0.1f, glm::vec3(1.0f, 0.0f, 0.0f)) * v;
        }

        // Go back to the original position
        v = glm::translate(glm::mat4(1.0f), glm::vec3(x_eye, y_eye, z_eye)) * glm::rotate(glm::mat4(1.0f), -eye_hangle, glm::vec3(0.0f, 1.0f, 0.0f)) * v;
        x_center = v.x;
        y_center = v.y;
        z_center = v.z;
    }
    old_xpos = xpos;
    old_ypos = ypos;
}

int main(int argc, char* argv[]) {
    GLFWwindow* window;

    /* Initialize the glfw */
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }
    /* glfw: configure; necessary for MAC */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    /* do not allow resizing */
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Assignment 1", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);


    // Enable raw mouse motion
    if (glfwRawMouseMotionSupported())
        glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);

    /* Initialize the glew */
    if (GLEW_OK != glewInit()) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return -1;
    }
    get_OpenGL_info();
    initializedGL();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        paintGL();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
