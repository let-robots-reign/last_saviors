#include "application.h"

int main() {
    Loader loader;
    Application game(loader);
    game.run();
    return 0;
}
