#include "application.h"

template<typename T>
Application<T> Application<T>::getInstance() {
    return Application();
}

template<typename T>
void Application<T>::run() {

}
