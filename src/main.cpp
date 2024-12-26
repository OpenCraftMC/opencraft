#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <GL/glut.h>

void display() {
    bgfx::renderFrame();
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Multi-Platform Triangle");
    glutDisplayFunc(display);
    bgfx::init();
    bgfx::reset(800, 600);
    glutMainLoop();
    bgfx::shutdown();
    return 0;
}
