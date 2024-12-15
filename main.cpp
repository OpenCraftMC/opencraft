#include <GLES2/gl2.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

const char* vertexShaderSource = R"(
    attribute vec4 a_Position;
    void main() {
        gl_Position = a_Position;
    }
)";

const char* fragmentShaderSource = R"(
    precision mediump float;
    uniform vec4 u_Color;
    void main() {
        gl_FragColor = u_Color;
    }
)";

GLuint shaderProgram;
GLuint positionAttr;
GLuint colorUniform;
GLuint vertexBuffer;

void initOpenGL() {
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);
    
    positionAttr = glGetAttribLocation(shaderProgram, "a_Position");
    colorUniform = glGetUniformLocation(shaderProgram, "u_Color");

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.5f, 0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };
    
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glEnableVertexAttribArray(positionAttr);
    glVertexAttribPointer(positionAttr, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glUniform4f(colorUniform, 0.0f, 1.0f, 0.0f, 1.0f);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableVertexAttribArray(positionAttr);
}

int main() {
    initOpenGL();
    
#ifdef EMSCRIPTEN
    emscripten_set_main_loop(renderFrame, 0, 1);
#else
    while (true) {
        renderFrame();
    }
#endif
    return 0;
}
