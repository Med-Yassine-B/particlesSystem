#include "renderer.hpp"
#include "particle.hpp"
#include <vector>
class App{
    public:
        bool running=true;
        Renderer *renderer;
        bool crashed;
        std::vector<ParticleSource> p_sources;
    App(Renderer *renderer);
    void run();
    ~App();

};
