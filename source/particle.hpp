#include <iostream>
#include <cstdlib>
class ParticleSource{
    public:
    float *data;
    int number;
    float size;
    float* velocitys;
    float max_dist=0.1;

    ParticleSource();
    void create();
    void move_particels();
    //distance squared (no sqrt())
    float sq_distance(float x, float y,float x2,float y2);;
    
};
