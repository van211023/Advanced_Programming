//Student.h
#include "CareerTalk.h"
#include <vector>
class Student{
private:
    /**
     * 说明：
     * name：毕业生姓名
     * id：毕业生学号
     * careerTalks：毕业生已预约的宣讲会
     */
    const char* name;
    const int id;
    std::vector<CareerTalk*> careerTalks;

public:
   //构造函数，careerTalks初始化为空
   Student(const char* name, int id);

   //析构函数
   ~Student();

   /**
    * 函数功能：预约某宣讲会并更新该毕业生的careerTalks。
    * 若宣讲会开放预约并且与已预约的其他宣讲会没有时间冲突，则将该宣讲会添加进careerTalks的尾部，并返回true。
    * 否则，不添加进careerTalks，返回false，预约失败；若已预约该宣讲会，则也预约失败。
    */
   bool addTalk(CareerTalk* careerTalk);

   /**
    * 函数功能：取消已预约的宣讲会
    * 若已经预约了该宣讲会，则从careerTalks移除，并返回true。
    * 否则，返回false，取消失败；取消一个未预约的宣讲会是取消失败。
    */
   bool cancelTalk(CareerTalk* careerTalk);

   /**
    * 函数功能：查询某天某时已预约的具体宣讲会，打印这些宣讲会的信息
    * day取值范围为[1, 5]，表示查询星期几的宣讲会
    * time取值范围为[8, 17]，表示查询[time, time + 1)时间范围内预约的宣讲会。例如，某预约的宣讲会时间为11:00-13:00，则((time == 11) || (time == 12))情况下能查询到
    * 调用所有查询到的宣讲会的打印函数
    */
   void queryTalk(int day, int time);

   /**
    * 函数功能：查询某天已预约具体宣讲会，打印这些宣讲会的信息
    * day取值范围为[1, 5]，表示查询星期几的宣讲会
    * 调用所有查询到的宣讲会的打印函数
    */
   void queryTalk(int day);

   /**
    * 函数功能：根据某调整了信息的宣讲会更新careerTalks
    * 若调整后的宣讲会时间与其他预约的宣讲会时间冲突，则取消预约，从careerTalks里删除，并返回false
    * 若没有预约这场宣讲会，返回false
    * 若调整后无冲突，则调整成功，返回true
    */
   bool updateTalks(CareerTalk* careerTalk);

   //打印毕业生信息，格式为：第一行："studentName:毕业生姓名,id:毕业生学号"，接下来每一行对应一条预约宣讲会的信息，按careerTalks中的顺序打印
   //注意：1）预约的宣讲会信息的打印格式与宣讲会本身打印格式相同 2）为英文标点，标点前后均无空格，其中末尾需要换行，具体也可见调用示例部分。
   void showStatus();
};