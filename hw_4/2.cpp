
#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14
class Shape{
 public:
    virtual float area()=0;
    virtual float volume()=0;
};
class Cube:public Shape{
 private:
    float edge;
 public:
    Cube();
    Cube(float e){
        edge = e;
    }
    ~Cube(){}
    float area(){
        return  6 * edge * edge;
    }
    float volume(){
        return pow(edge,3);
    }
};

class Sphere:public Shape{
    float radius;
 public:
    Sphere();
    Sphere(float r){
        radius = r;
    }
    ~Sphere(){}
    float area(){
        return 4*pi*radius*radius;
    }
    float volume(){
        return 4.0*pi*pow(radius,3)/3;
    }
};
class Volumn:public Shape{
    float radius, height;
 public:
    Volumn();
    Volumn(float r, float h){
        radius = r;
        height = h;
    }
    ~Volumn(){}
    float area(){
        return 2*pi*radius*height+2*pi*pow(radius,2);
    }
    float volume(){
        return pi*pow(radius,2)*height;
    }
};

int main(){
    Shape *p;
    Cube cube(2.0); //边⻓为2.0
    p=&cube;
    cout<<"Shape："<<"正⽅体"<<endl<<" ⾯积、体积："<<p->area()<<" "<<p->volume()
    	<<endl;
    Sphere sphere(3.0); //半径为3.0
    p=&sphere;
    cout<<"Shape："<<"球体"<<endl<<" ⾯积、体积："<<p->area()<<" "<<p->volume()
    	<<endl;
    Volumn volumn(3.0,2.0); //半径为3.0，⾼为2.0
    p=&volumn;
    cout<<"Shape："<<"圆柱体"<<endl<<" ⾯积、体积："<<p->area()<<" "<<p->volume()
    	<<endl;
    return 0;
}