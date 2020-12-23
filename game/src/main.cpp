#include "application.h"

int main() {
    Loader loader;
    Application application(loader);
    application.run();

    return 0;
}
