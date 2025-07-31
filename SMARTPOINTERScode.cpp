#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Student; // forward declaration

class Course {
private:
    string name;
    weak_ptr<Student> owner;

public:
    Course(const string& name) : name(name) {
        cout << "Course Created: " << name << endl;
    }

    void assignOwner(shared_ptr<Student> student) {
        owner = student;
    }

    string getName() {
        return name;
    }

    void showOwner();

    ~Course() {
        cout << "Course Destroyed: " << name << endl;
    }
};

class Student {
public:
    string name;
    int age;
    vector<shared_ptr<Course>> enrolledCourses;

    Student(const string& name, int age) : name(name), age(age) {
        cout << "Student Created: " << name << endl;
    }

    void enrollCourse(shared_ptr<Course> course) {
        enrolledCourses.push_back(course);
        cout << name << " enrolled in course: " << course->getName() << endl;
    }

    void showCourses() {
        cout << name << "'s Enrolled Courses:\n";
        for (auto& course : enrolledCourses) {
            cout << " - " << course->getName() << endl;
        }
    }

    ~Student() {
        cout << "Student Destroyed: " << name << endl;
    }
};

void Course::showOwner() {
    if (auto spt = owner.lock()) {
        cout << "Course " << name << " is owned by: " << spt->name << endl;
    } else {
        cout << "Course " << name << " has no valid owner now." << endl;
    }
}

class School {
public:
    unique_ptr<string> schoolName;
    vector<shared_ptr<Student>> students;

    School(const string& name) {
        schoolName = make_unique<string>(name);
        cout << "School Created: " << *schoolName << endl;
    }

    void addStudent(shared_ptr<Student> student) {
        students.push_back(student);
        cout << "Added Student: " << student->name << " to " << *schoolName << endl;
    }

    void showAllStudents() {
        cout << "Students in " << *schoolName << ":\n";
        for (auto& student : students) {
            cout << " - " << student->name << endl;
        }
    }

    ~School() {
        cout << "School Destroyed: " << *schoolName << endl;
    }
};

int main() {
    {
        School mySchool("Chitkara University");

        auto student1 = make_shared<Student>("Om Aggarwal", 20);
        auto student2 = make_shared<Student>("Anjali Sharma", 19);

        mySchool.addStudent(student1);
        mySchool.addStudent(student2);

        auto course1 = make_shared<Course>("Web Development");
        auto course2 = make_shared<Course>("Data Structures");

        course1->assignOwner(student1);
        course2->assignOwner(student2);

        student1->enrollCourse(course1);
        student1->enrollCourse(course2);
        student2->enrollCourse(course2);

        mySchool.showAllStudents();
        student1->showCourses();
        student2->showCourses();

        course1->showOwner();
        course2->showOwner();
    }

    cout << "\nAll objects are automatically destroyed without memory leaks!" << endl;

    return 0;
}