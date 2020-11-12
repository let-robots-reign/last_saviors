#include "application.h"

int main() {
    Loader loader{};
    LoaderManager loaderManager(loader);
    Application application(RendererManager(Renderer(Level(""), HUD({}), MainMenu)), loaderManager,
                                          UserInputManager(UserInput(MainMenu)));
    application.run();
    return 0;
}