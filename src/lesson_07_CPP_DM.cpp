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


}

//----------------------------------------------------------------------------
int main()
{
  //--------------------------------------------------------------------------

  //--------------------------------------------------------------------------
  return 0;
}

