#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    Student(const string& name, int age) : name(name), age(age) {}
};
class Group {
public:
    Student* students;
    int size;
    Group() : students(nullptr), size(0) {}
    Group(const Group& other) : size(other.size) {
        students = new Student[size];
        for (int i = 0; i < size; i++) {
            students[i] = other.students[i];
        }
    }
    ~Group() {
        delete[] students;
    }
};

int main() {
    Student student1("Mykhailo", 20);
    Student student2("Mykola", 21);
    Group group1;
    group1.students = new Student[2];
     group1.students[0] = student1;
    group1.students[1] = student2;
    group1.size = 2;
    Group group2 = group1;
    cout << "Інформація про групу 1::" << endl;
    for (int i = 0; i < group1.size; i++) {
        cout << "Ñòóäåíò " << i + 1 << ": " << group1.students[i].name << ", " << group1.students[i].age << " ðîê³â" << endl;
    }

    cout << "²íôîðìàö³ÿ ïðî Ãðóïó 2 (êîï³ÿ Ãðóïè 1):" << endl;
    for (int i = 0; i < group2.size; i++) {
        cout << "Студент" << i + 1 << ": " << group2.students[i].name << ", " << group2.students[i].age << "рокыв << endl;
    }
    return 0;
}
