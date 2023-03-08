//CareerTalk.cpp
#include "CareerTalk.h"

CareerTalk::CareerTalk(const char* cN, int d, int s, int e) :companyName(cN),day(d),startTime(s),endTime(e) {open=true;}

CareerTalk::~CareerTalk() {}

const char* CareerTalk::getName() {
    return companyName;
}

int CareerTalk::getDay() {
    return day;
}

int CareerTalk::getStartTime() {
    return startTime;
}

int CareerTalk::getEndTime() {
    return endTime;
}

void CareerTalk::adjustInfo(int d, int s, int e) {
    day = d;
    startTime = s;
    endTime = e;
}

void CareerTalk::openAccess() {
    open = true;

}

void CareerTalk::closeAccess() {
    open = false;
}

bool CareerTalk::isOpen() {
    return open;
}

bool CareerTalk::conflict(CareerTalk *ct) {
    if(ct->day != day)
        return false;
    if(startTime < ct->startTime&& endTime > ct->startTime || startTime > ct->startTime&&startTime < ct->endTime || startTime==ct->startTime)   
        return true;
    else 
        return false;
}

void CareerTalk::showStatus() {
    cout << "companyName:" << companyName << ",day:" << day << ",startTime:" 
    << startTime << ",endTime:" << endTime << ",isOpen:" << (isOpen()?"true":"false") << endl;
}

// int main()
// {
//     CareerTalk* talk1 = new CareerTalk("Tencent", 1, 10, 12);
//     talk1->showStatus();
//     talk1->adjustInfo(1,9,11);
//     talk1->closeAccess();
//     talk1->showStatus();
//     return 0;
// }