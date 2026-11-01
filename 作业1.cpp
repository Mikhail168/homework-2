#include<iostream>
#include<yaml-cpp/yaml.h>
#include<fstream>
class config{
public:
  void readYaml(){//读取.yaml文件并为a、b赋值
    try{
        YAML::Node node=YAML::LoadFile("test.yaml");
        a=node["a"].as<int>();
        b=node["b"].as<int>();
        std::cout<<"a= "<<a<<" b= "<<b<<std::endl;
    }
    catch(const YAML::Exception& e){
        std::cout<<"error reading .yaml file\n"<<e.what()<<std::endl;
        a=0;b=0;
    }
  }
  void changeVariety(){
    int temp;
    temp=a+b;
    b=temp;
    std::cout<<"a= "<<a<<" b= "<<b<<std::endl;
  }
  void writeIn(){//写入.yaml文件
    YAML::Node data;
    data["a"]=a;
    data["b"]=b;
    std::cout<<"a= "<<a<<" b= "<<b<<std::endl;
    std::ofstream fout("test.yaml");
    if (!fout) {
      std::cerr << "cannot open test.yaml for writing\n";
      return;
    }
    fout<<data;
  }

private:
  int a=0;
  int b=0;
};

int main(){
    config c1;
    c1.readYaml();
    c1.changeVariety();
    c1.writeIn();
    return 0;
}