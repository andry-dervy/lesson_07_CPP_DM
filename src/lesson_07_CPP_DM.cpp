//============================================================================
// Name        : lesson_07_CPP_DM.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 07 of the C++: difficult moments course
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>

#include "StudentsGroup.h"
//----------------------------------------------------------------------------
int getRandomNum(int min, int max)
{
  const static auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  static std::mt19937_64 generator(seed);
  std::uniform_int_distribution<int> dis(min, max);
  return dis(generator);
}
//----------------------------------------------------------------------------
/*
1. Установить библиотеку protobuf.
2. С помощью компилятора protobuf в отдельном пространстве имен сгенерировать классы
   a. FullName с полями имя, фамилия, отчество (отчество опционально).
   b. Student с полями полное имя, массив оценок, средний балл.
   c. StudentsGroup с полем массив студентов.
3. Создать класс StudentsGroup, который реализует интерфейсы:
class IRepository {
  virtual void Open() = 0; // бинарная десериализация в файл
  virtual void Save() = 0; // бинарная сериализация в файл
};
class IMethods {
  virtual double GetAverageScore(const FullName& name) = 0;
  virtual string GetAllInfo(const FullName& name) = 0;
  virtual string GetAllInfo() = 0;
};
//*/
void task_2_3()
{
  std::cout << "Task 2, 3" << std::endl;

  std::cout << "\nTest 1\n" << std::endl;

  const int NUMBER_ESTIMATIONS = 5;
  const int MIN_ESTIMATION = 0;
  const int MAX_ESTIMATION = 100;

  sgpb::StudentsGroup group;
  std::shared_ptr<sg::Student> st1 = std::make_shared<sg::Student>();
  {
    sg::FullName* pname = new sg::FullName;
    pname->set_m_surname("Family");
    pname->set_m_name("Name");
    pname->set_m_patronymic("Patronymic");
    st1->set_allocated_m_fullname(pname);

    for(int i = 0; i < NUMBER_ESTIMATIONS; ++i)
      st1->add_m_estimation(getRandomNum(MIN_ESTIMATION,MAX_ESTIMATION));
  }
  group.addStudent(st1);

  std::cout << group.GetAllInfo() << std::endl;

  std::cout << "\nTest 2\n" << std::endl;

  std::cout << group.GetAllInfo(st1->m_fullname()) << std::endl;

  std::cout << "\nTest 3\n" << std::endl;
  {
    std::shared_ptr<sg::Student> st = std::make_shared<sg::Student>();
    {
      sg::FullName* pname = new sg::FullName;
      pname->set_m_surname("Petrov");
      pname->set_m_name("Ivan");
      st->set_allocated_m_fullname(pname);

      for(size_t i = 0; i < NUMBER_ESTIMATIONS; ++i)
        st->add_m_estimation(getRandomNum(MIN_ESTIMATION,MAX_ESTIMATION));
    }
    group.addStudent(st);
  }

  std::cout << group.GetAllInfo();

  std::cout << "\nTest 4\n" << std::endl;

  std::cout << "Save group." << std::endl;
  group.Save();

  sgpb::StudentsGroup group_two;
  std::cout << "Open group_two." << std::endl;
  group_two.Open();
  std::cout << group_two.GetAllInfo();

  std::cout << std::endl;
}
//----------------------------------------------------------------------------
int main()
{
  //--------------------------------------------------------------------------
  // Task 2, 3
  //*
  task_2_3();
  //*/
  //--------------------------------------------------------------------------
  return 0;
}

