//Student.cpp
#include "Student.h"

Student::Student(const char* n, int i):name(n),id(i){}

Student::~Student() {}

bool Student::addTalk(CareerTalk *careerTalk) {
    for(int i = 0; i < careerTalks.size(); i++){
        if(careerTalks[i]->conflict(careerTalk))//conflict may include the name
        {
            cout << careerTalk->companyName << " conflict with " << careerTalks[i]->companyName << endl;
            return false;
        }
            
    }
    careerTalks.push_back(careerTalk);

    //debug
    cout << "add " << careerTalk->companyName << endl; 
    return true;
}

bool Student::cancelTalk(CareerTalk *careerTalk) {
    bool find = false;
    for(int i = 0; i < careerTalks.size(); i++){
        if(careerTalks[i] == careerTalk){
            find = true;
            careerTalks.erase(careerTalks.begin()+i);
            break;
        }
    }
    return find;
}

void Student::queryTalk(int day) {
    for(int i = 0; i < careerTalks.size(); i++){
        if(careerTalks[i]->getDay() == day){
            careerTalks[i]->showStatus();
        }//if size == 0, print('\n') or not
    }
}

void Student::queryTalk(int day, int time) {
    for(int i = 0; i < careerTalks.size(); i++){
        if(careerTalks[i]->getDay() == day && time >= careerTalks[i]->getStartTime() && time < careerTalks[i]->getEndTime()){//maybe bug
            careerTalks[i]->showStatus();
        }//if size == 0, print('\n') or not
    }
}

bool Student::updateTalks(CareerTalk *careerTalk) {
    // if(careerTalks.find(cancelTalks.begin(), careerTalks.end(), careerTalk)==careerTalks.end())
    //     return false;
    bool find = false;
    bool conf = false;
    for(int i = 0; i < careerTalks.size(); i++){
        if(careerTalks[i] == careerTalk){//found
            find = true;
            // CareerTalk *tmp
            // careerTalks.erase(careerTalks.begin()+i);
            for(int j = 0; j < careerTalks.size(); j++){
                if(j!=i)
                    if(careerTalks[i]->conflict(careerTalks[j])){
                        conf = true;
                        break;
                    }
            }   
            if(conf){
                careerTalks.erase(careerTalks.begin()+i);
    } 
            break;
        }
    }
    if(!find || conf)
        return false;
    else
        return true;
}

void Student::showStatus() {
    cout <<"studentName:"<<name <<",id:"<<id<<endl;

    //debug
    cout << "size:" << careerTalks.size() << endl;
    for(int i =0; i< careerTalks.size();i++){
        careerTalks[i]->showStatus();
    }

}

int main()
{
    CareerTalk* talk1 = new CareerTalk("Tencent", 1, 10,12);
    CareerTalk* talk2 = new CareerTalk("Alibaba", 2, 12,14);
    CareerTalk* talk3 = new CareerTalk("Baidu", 3, 15,18);
    CareerTalk* talk4 = new CareerTalk("test4", 1, 11,12);
    CareerTalk* talk5 = new CareerTalk("test5", 1, 12,14);
    CareerTalk* talk6 = new CareerTalk("test6", 1, 13,18);    
    Student* stu1 = new Student("Li Hua", 22001);
    stu1->addTalk(talk1);stu1->addTalk(talk2);stu1->addTalk(talk3);
    stu1->addTalk(talk4);stu1->addTalk(talk5);stu1->addTalk(talk6);
    stu1->queryTalk(1);
    talk1->closeAccess();
    stu1->showStatus();
    // bool cancelState1 = stu1->cancelTalk(talk3);
    // stu1->showStatus();
}