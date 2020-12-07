#include "application.h"

int main() {
    Application application(Loader(), Renderer(Level(""), HUD()));
    application.runMainMenu();
    return 0;
}