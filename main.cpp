#include <GLES2/gl2.h>

#ifdef EMSCRIPTEN
#include <emscripten.h>
#endif

void renderFrame() {
    glClear(GL_COLOR_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

int main() {
    #ifdef EMSCRIPTEN
    emscripten_set_main_loop(renderFrame, 0, 1);
    #endif
    return 0;
}
