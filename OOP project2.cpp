#include <iostream>
#include <vector>
using namespace std;
class Student
{
    private:
        string name;
        int id;
    public:
        Student(string n,int d): name(n),id(d)
        {
        }
        string getName()
        {
            return name;
        }
        int getId()
        {
            return id;
        }
};
class Course
{
    private:
        vector<Student*> studnets;
    public:
        string courseName;
        Course(string name):courseName(name)
        {}
        void addStudent(Student &s)
        {
            studnets.push_back(&s);
        }
        void listStudents()
        {
            cout<<"Students in "<<courseName<<endl;
            for(int i = 0;i<studnets.size();i++)
            {
                cout<<"- "<<"Name "<<studnets[i]->getName()<<" -"<<" Id: "<<studnets[i]->getId()<<endl;
            }
        }
};
class Teacher
{
    private:
        string name;
        vector<Course*>courses;
    public:
        Teacher(string n): name(n)
        {}
        void assignCourse(Course*course)
        {
            cout<<name<<" is assigned to course "<<course->courseName<<endl;
        }
};
class Department
{
    private:
        vector<Course>courses;
        vector<Teacher*>teachers;
    public:
        void addCourse(Course c)
        {
            courses.push_back(c);
        }
        void addTeacher(Teacher* teacher)
        {
            teachers.push_back(teacher);
        }
        void displayData()
        {
            for(auto&Course:courses)
            {
                Course.listStudents();
            }
        }
};
class School
{
    private:
        Department dept;
    public:
        void addDepartment(Department department)
        {
            dept = department;
        }
        void showDepartmentInfo()
        {
            dept.displayData();
        }
};
int main()
{
    //create students
    Student Student1("Mohamed",1);
    Student Student2("Ahmed",2);
    Student Student3("Ibrahim",3);
    Student Student4("Norhan",4);
    //create course and add student
    Course course1("Math");
    course1.addStudent(Student1);
    course1.addStudent(Student2);
    course1.addStudent(Student3);
    Course course2("oop");
    course2.addStudent(Student4);
    //create teacher and assign courses
    Teacher teacher("Mrs.WaffaShalsh");
    Teacher teacher2("Mr.John");
    teacher.assignCourse(&course2);
    teacher2.assignCourse(&course1);
    //create department
    Department department;
    department.addTeacher(&teacher);
    department.addTeacher(&teacher2);
    department.addCourse(course1);
    department.addCourse(course2);
    // create school and assign department
    School school;
    school.addDepartment(department);
    school.showDepartmentInfo();
    return 0;
}
