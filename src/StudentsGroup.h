//============================================================================
// Name        : StudentsGroup.h
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 07 of the C++: difficult moments course
//============================================================================

#ifndef STUDENTSGROUP_H_
#define STUDENTSGROUP_H_

#include <fstream>
#include <list>
#include <memory>
#include <string>
#include <sstream>
#include <tuple>
#include <optional>

#include "studentsgroup.pb.h"

namespace sgpb {

class IRepository {
public:
	virtual void Open() = 0;
	virtual void Save() = 0;
};

class IMethods {
public:
	virtual double GetAverageScore(const sg::FullName& name) = 0;
	virtual std::string GetAllInfo(const sg::FullName& name) = 0;
	virtual std::string GetAllInfo() = 0;
};

class StudentsGroup : public IRepository, IMethods
{
private:
  std::shared_ptr<sg::StudentsGroup> group;

  std::optional<sg::Student> findStudent(
      const sg::FullName& a_name);
  public:
	StudentsGroup();
	virtual ~StudentsGroup();

	void addStudent(std::shared_ptr<sg::Student> pStudent);
  void deleteStudent(const sg::FullName& name);

  std::string GetStudentInfo(const sg::Student& a_student);
	//IMethod
	virtual double GetAverageScore(const sg::FullName& name);
	virtual std::string GetAllInfo(const sg::FullName& name);
	virtual std::string GetAllInfo();

	//IRepository
	virtual void Open();
	virtual void Save();

};

} /* namespace sg */

#endif /* STUDENTSGROUP_H_ */
