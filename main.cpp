#include "source/app.hpp"
int main(){
    Renderer renderer;
    App app(&renderer);
    app.run();
    return !app.crashed;
}
