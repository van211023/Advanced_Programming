//CareerTalk.h
#include <iostream>
using namespace std;
class CareerTalk{
public:
    /**
     * 说明：
     * companyName: 举办企业名称，例如："Baidu"
     * day：取值范围[1,5]，表示在周几举办
     * startTime：取值范围[8,17]，表示几点开始（显然不可能18：00开始）
     * endTime：取值范围[9:18]，表示几点结束（显然不可能8点结束）
     * open：取值true表示开放预约通道，false表示关闭预约通道
     */
    const char* companyName;
    int day;
    int startTime;
    int endTime;
    bool open;

public:
    //构造函数，初始化CareerTalk对象，初始化时预约通道默认为开
    CareerTalk(const char* cN, int d, int s, int e);

    //析构函数
    ~CareerTalk();

    //返回宣讲会举办企业名称
    const char* getName();

    //返回宣讲会举办日期
    int getDay();

    //返回宣讲会开始时间
    int getStartTime();

    //返回宣讲会结束时间
    int getEndTime();

    //修改宣讲会的具体信息
    void adjustInfo(int d, int s, int e);

    //开放预约通道
    void openAccess();

    //关闭预约通道
    void closeAccess();

    //返回是否开放预约，开放返回true，否则返回false
    bool isOpen();

    //判断另一宣讲会是否和this宣讲会冲突，冲突返回true，否则返回false
    bool conflict(CareerTalk* ct);

    //打印宣讲会的信息，格式为"companyName:举办企业名称,day:举办日期,startTime:开始时间,endTime:结束时间,isOpen:是否开放预约"
    //注意：1）开放预约输出true, 关闭预约输出false 2）为英文标点，标点前后均无空格，其中末尾需要换行，具体也可见调用示例部分。
    void showStatus();
};