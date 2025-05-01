#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course {
public:
    int id;
    string name;
    string instructor;

    Course(int id, string name, string instructor) {
        this->id = id;
        this->name = name;
        this->instructor = instructor;
    }

    void displayCourse() {
        cout << "Course ID: " << id << ", Name " << name << ", Instructor: " << instructor << endl;
    }
};

class Student {
public:
    int id;
    string name;
    vector<int> enrolledCourses;

    Student(int id, string name) {
        this->id = id;
        this->name = name;
    }

    void enroll(int courseId) {
        enrolledCourses.push_back(courseId);
    }

    void displayStudent() {
        cout << "Student ID: " << id << ", Name: " << name << ", Enrolled in Courses: ";
        if (enrolledCourses.empty()) {
            cout << "None";
        } else {
            for (int cid : enrolledCourses) {
                cout << cid << " ";
            }
        }
        cout << endl;
    }
};

vector<Course> courses;
vector<Student> students;

void addCourse() {
    int id;
    string name, instructor;
    cout << "Enter Course ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Course Name: ";
    getline(cin, name);
    cout << "Enter Instructor Name: ";
    getline(cin, instructor);
    courses.push_back(Course(id, name, instructor));
    cout << "Course added successfully.\n";
}

void addStudent() {
    int id;
    string name;
    cout << "Enter Student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    students.push_back(Student(id, name));
    cout << "Student added successfully.\n";
}

void enrollStudent() {
    int studentId, courseId;
    cout << "Enter Student ID to enroll: ";
    cin >> studentId;
    cout << "Enter Course ID to enroll in: ";
    cin >> courseId;

    bool studentFound = false, courseFound = false;

    for (Student& s : students) {
        if (s.id == studentId) {
            studentFound = true;
            for (Course& c : courses) {
                if (c.id == courseId) {
                    courseFound = true;
                    s.enroll(courseId);
                    cout << "Enrollment successful.\n";
                    return;
                }
            }
        }
    }

    if (!studentFound) cout << "Student not found.\n";
    if (!courseFound) cout << "Course not found.\n";
}

void showCourses() {
    if (courses.empty()) {
        cout << "No courses available.\n";
        return;
    }
    for (Course& c : courses) {
        c.displayCourse();
    }
}

void showStudents() {
    if (students.empty()) {
        cout << "No students enrolled.\n";
        return;
    }
    for (Student& s : students) {
        s.displayStudent();
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- E-Learning Management System ---\n";
        cout << "1. Add Course\n";
        cout << "2. Add Student\n";
        cout << "3. Enroll Student in Course\n";
        cout << "4. Show All Courses\n";
        cout << "5. Show All Students\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCourse(); break;
            case 2: addStudent(); break;
            case 3: enrollStudent(); break;
            case 4: showCourses(); break;
            case 5: showStudents(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

