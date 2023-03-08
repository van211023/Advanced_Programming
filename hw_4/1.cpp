#include<iostream>
#include<string.h>
using namespace std;

class Port{
 protected:
    char* brand;//品牌
    char style[32];//葡萄酒类型，有 tawny, ruby, vintage 类型
    int bottles;
 public:
    Port(const char * br = "none", const char * st = "none", int b = 0){
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style, st);
    bottles = b;
    }
    Port(const Port & p){//拷贝构造函数
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    } 
    virtual ~Port() { delete [] brand; } //析构函数
    Port & operator=(const Port & p);
    Port & operator+=(int b); // adds b to bottles
    Port & operator-=(int b); // subtracts b from bottles, if available
    int BottleCount() const { return bottles; }
    virtual void Show() const;
};


Port & Port::operator=(const Port & p){
    if(strlen(this->brand)>0)   
        delete []this->brand;
    this->brand = new char[strlen(p.brand)+1];
    strcpy(this->brand,p.brand);
    strcpy(this->style, p.style);
    this->bottles = p.bottles;
    return *this;
}
Port & Port::operator+=(int b){
    this->bottles += b;
    return *this;
}
Port & Port::operator-=(int b){
    if(this->bottles > b)
        this->bottles -= b;
    else 
        this->bottles = 0;
    return *this;
}
void Port::Show() const{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}
//Show()方法按下面的格式显示信息：
//Brand: Gallo
//Kind: tawny
//Bottles: 20
//VintagePort 类派生自 Port 类，如下所示：
class VintagePort : public Port {// style necessarily = "vintage"
 private:
    char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
    int year; // vintage year
 public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y){
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    strcpy(style, "vintage");
    nickname = new char[strlen(nn)+1];
    strcpy(nickname,nn);
    bottles = b;
    year = y;
    }
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
};

VintagePort::VintagePort(const VintagePort & vp){
    brand = new char[strlen(vp.brand)+1];
    strcpy(brand,vp.brand);
    strcpy(style, "vintage");
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    bottles = vp.bottles;
    year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp){
    if(strlen(brand)>0)
        delete []brand;
    
    brand = new char[strlen(vp.brand)+1];
    strcpy(brand,vp.brand);
    strcpy(style, "vintage");
    if(strlen(nickname)>0)
        delete []nickname;
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    bottles = vp.bottles;
    year = vp.year;
    return *this;
}
void VintagePort::Show() const{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}
//Show()方法按下面的格式显示信息：
//Brand: Taylor's
//Kind: vintage
//Bottles: 20
//Nickname:The Noble
//Year:5
int main()
{
    Port p("Gallo","tawny",20);
    
    p.Show();
    p += 2;
    p.Show();
    p-=3;
    p.Show();
    VintagePort vp("Taylor's",20,"The Noble",5);
    vp.Show();
    vp+=12;
    vp.Show();
    vp-=1;
    vp.Show();
    p = vp;
    p.Show();
    return 0;

}