#include "app.hpp"

App::App(Renderer *renderer){
        this->renderer=renderer;
        crashed=this->renderer->crashed;
        ParticleSource source;
        p_sources.push_back(source);

}
//======================================================

void App::run(){
    while(running && !renderer->should_close){
        renderer->start_render();

        for(int i=0;i<p_sources.size();i++){
            p_sources[i].move_particels();
            renderer->render_particels(p_sources[i].data,p_sources[i].number);
        }
        renderer->end_render();
    }
}
//======================================================
App::~App(){
    //if renderer didnt set it to true (crashed==true looks clearer than just using crashed)
    if(crashed==true)
        crashed=false;
}
