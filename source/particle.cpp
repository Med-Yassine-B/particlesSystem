#include "particle.hpp"

ParticleSource::ParticleSource(){
    number=50;//default
    size=0.02;
    create();
    move_particels();
}
//======================================================
void ParticleSource::create(){
    srand(time(NULL));

    data=new float[number*6];
    velocitys=new float[number*2];
    
    for(int i=0;i<number;i++){
        
        data[i*6+0]=centerX-size;
        data[i*6+1]=centerY-size;

        data[i*6+2]=centerX-size;
        data[i*6+3]=centerY+size;

        data[i*6+4]=centerX+size;
        data[i*6+5]=centerY+size;

        int range=10;
        velocitys[i*2+0]=float(rand()%(2*range)-range)/1000;
        velocitys[i*2+1]=float(rand()%(2*range)-range)/1000;

    }

    for(int i=0;i<number*6;i++){
        std::cout<<data[i]<<" , ";
        if((i+1)%2==0)
            std::cout<<std::endl;
    }
}
//======================================================
void ParticleSource::move_particels(){
    for(int i=0;i<number;i++){
        if(sq_distance(centerX, centerY,data[i*6+0],data[i*6+1])>=max_dist){

            data[i*6+0]=centerX-size;
            data[i*6+1]=centerY-size;

            data[i*6+2]=centerX-size;
            data[i*6+3]=centerY+size;

            data[i*6+4]=centerX+size;
            data[i*6+5]=centerY+size;
        }

        data[i*6+0]+=velocitys[i*2+0];
        data[i*6+1]+=velocitys[i*2+1];

        data[i*6+2]+=velocitys[i*2+0];
        data[i*6+3]+=velocitys[i*2+1];

        data[i*6+4]+=velocitys[i*2+0];
        data[i*6+5]+=velocitys[i*2+1];
    }
}

//======================================================

float ParticleSource::sq_distance(float x, float y,float x2,float y2){
    float dx=x-x2,dy=y-y2;
    return dx*dx+dy*dy;
}
