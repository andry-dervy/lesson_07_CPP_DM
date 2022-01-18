//============================================================================
// Name        : StudentsGroup.cpp
// Author      : andry antonenko
// IDE         : Eclipse IDE
// Description : lesson 07 of the C++: difficult moments course
//============================================================================

#include "StudentsGroup.h"

namespace sgpb {

StudentsGroup::StudentsGroup()
{
  group = std::make_shared<sg::StudentsGroup>();
}

StudentsGroup::~StudentsGroup() {}

std::optional<sg::Student> StudentsGroup::findStudent(
    const sg::FullName& name)
{
  //std::optional<const sg::Student&> stu;

  for(auto& st: group->m_students())
	{
		if( name.m_surname() != st.m_fullname().m_surname() )
			continue;
		if( name.m_name() != st.m_fullname().m_name() )
			continue;
		if(	name.has_m_patronymic() != st.m_fullname().has_m_patronymic() )
			continue;
		if( name.has_m_patronymic() && (name.m_patronymic() != st.m_fullname().m_patronymic() ) )
			continue;
		return st;//const_cast<sg::Student> (st);
	}

	return std::nullopt;
}

void StudentsGroup::addStudent(std::shared_ptr<sg::Student> pStudent)
{
	if(pStudent == nullptr) return;

	if(findStudent(pStudent->m_fullname()) != std::nullopt) return;

	sg::Student* newStudent = group->add_m_students();

	*newStudent = *pStudent;
}

std::string StudentsGroup::GetStudentInfo(const sg::Student& a_student)
{
  std::stringstream ss;

  ss << "The student: " << a_student.m_fullname().m_surname()
      << " " << a_student.m_fullname().m_name()
      << " " << a_student.m_fullname().m_patronymic() << "\n";

  ss << "Estimations: ";
  for(const auto& a: a_student.m_estimation())
    ss << a << " ";

  ss << "\nAverage Score: " << std::fixed
      << GetAverageScore(a_student.m_fullname());

  return ss.str();
}

//IMethod
double StudentsGroup::GetAverageScore(const sg::FullName& name)
{
  std::optional<sg::Student> student = findStudent(name);

	if(!student.has_value()) return -1;

	if(student->m_estimation().size() == 0) return 0;

	double AverageScore = 0;
	for(const auto& a: student->m_estimation())
	{
		AverageScore += a;
	}

	student->set_m_middle_estimation(AverageScore / student->m_estimation().size());

	return student->m_middle_estimation();
}

std::string StudentsGroup::GetAllInfo(const sg::FullName& name)
{
  std::optional<sg::Student> student = findStudent(name);

	if(!student.has_value())
	{
		std::stringstream ss;
		ss << "The student " << name.m_surname()
				<< " " << name.m_name()
				<< " " << name.m_patronymic()
				<< " wasn't find.";
		return ss.str();
	}

//	std::stringstream ss;
//
//	ss << "The student: " << name.m_surname()
//			<< " " << name.m_name()
//			<< " " << name.m_patronymic() << "\n";
//
//	ss << "Estimations: ";
//	for(const auto& a: student->m_estimation())
//		ss << a << " ";
//
//	ss << "\nAverage Score: " << std::fixed << GetAverageScore(name);
//
	return GetStudentInfo(*student);
}

std::string StudentsGroup::GetAllInfo()
{
	std::stringstream ss;

	for(const auto& st: group->m_students())
	{
		ss << GetStudentInfo(st) << std::endl;
	}

	return ss.str();
}

//IRepository
void StudentsGroup::Open()
{
  std::ifstream in("StudentsGroup.bin", std::ios_base::binary);
  if(!group->ParseFromIstream(&in)) std::cout << "\n Error parsing!\n";
}

void StudentsGroup::Save()
{
	std::ofstream out("StudentsGroup.bin", std::ios_base::binary);
	group->SerializeToOstream(&out);
}

} /* namespace sg */
