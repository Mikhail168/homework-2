#include<iostream>
#include<cmath>
#define PI 3.14

class shape{//基类
public:
  void area(){

  }
  void perimeter(){

  }
  virtual ~shape(){
    std::cout<<"基类已完成析构\n";
  }
protected:
  double peri=0;double Area=0;
};

class triangle:public shape{//三角类
public:
  void writeIn(){
    std::cout<<"enter a、b、c value: \n";
    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
  }
  bool judge(){
    if(a<=0||b<=0||c<=0||a>=b+c||a<=b-c||a<=c-b||b>=a+c||b<=a-c||b<=c-a||c>=a+b||c<=a-b||c<=b-a){
        std::cout<<"不存在此三角形\n";
        return false;    
    }
    else{
        return true;
    }
    
  }
  void area(){
    if(judge()==false){
        std::cout<<"area=--\n";
    }
    else{
           p=(a+b+c)/2;
           Area=std::sqrt(p*(p-a)*(p-b)*(p-c));
           std::cout<<"area="<<Area<<std::endl;
        }  
  }
  void perimeter(){
    if(judge()==false){
        std::cout<<"perimeter=--\n";
    }
    else{
      peri=a+b+c;
      std::cout<<"perimeter="<<peri<<std::endl;
    }

  }
private:
  double a=0;double b=0;double c=0;double p=0; 
};

class rectangle:public shape{//矩形类
public:
  void writeIn(){
    std::cout<<"enter d、e value: \n";
    std::cin>>d;
    std::cin>>e;
  }
  bool judge(){
    if(d<=0||e<=0){
        std::cout<<"不存在此矩形\n";
        return false;
    }
    else{
        return true;
    }
  }
  void area(){
    if(judge()==false){
        std::cout<<"area=--\n";
    }
    else{
      Area=d*e;
      std::cout<<"area="<<Area<<std::endl;
    }
  }
  void perimeter(){
    if(judge()==false){
        std::cout<<"perimeter=--\n";
    }
    else{
      peri=(d+e)*2;
      std::cout<<"perimeter="<<peri<<std::endl;
    }
  }
private:
  double d=0;double e=0;
};

class circle:public shape{//圆类
public:
  void writeIn(){
    std::cout<<"enter r value: \n";
    std::cin>>r;
  }
  bool judge(){
    if(r<=0){
        std::cout<<"不存在此圆形\n";
        return false;
    }
    else{
        return true;
    }
  }
  void area(){
    if(judge()==false){
        std::cout<<"area=--\n";
    }
    else{
      Area=PI*r*r;
      std::cout<<"area="<<Area<<std::endl;
    }
  }
  void perimeter(){
    if(judge()==false){
        std::cout<<"perimeter=--\n";
    }
    else{
       peri=2*PI*r;
       std::cout<<"perimeter="<<peri<<std::endl;
    }   
  }
private:
  double r=0;
};

int main(){
    triangle tri1;
    tri1.writeIn();
    tri1.area();
    tri1.perimeter();

    rectangle rec1;
    rec1.writeIn();
    rec1.area();
    rec1.perimeter();

    circle c1;
    c1.writeIn();
    c1.area();
    c1.perimeter();//实例化该三类

    return 0;
}