#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
// cấu trúc lưu thông tin sinh viên
class Student{
 public:
 string ID;
 string name;
 int age;
 string className;
 float gpa;
};

// lưu trữ thông tin nhiều sinh viên
vector<Student>StudentList;

// hàm nhập thông tin sinh viên
void addStudent(Student &a){
    cout << "nhap ID sinh vien" <<endl;
       getline(cin,a.ID);
    cout << "nhap ten sinh vien " << endl;
       getline(cin,a.name);
    cout << "nhap tuoi sinh vien " << endl;
       cin >> a.age;
       cin.ignore();
    cout << "nhap lop sinh vien " << endl;
       getline(cin,a.className);
    cout << "nhap gpa cua sinh vien" << endl;
       cin >> a.gpa;
       cin.ignore();
}

// hàm xuất thông tin sinh viên
void outputStudentInfo(Student a){
    cout << " THONG TIN SINH VIEN" << endl;
    cout << "ID :  " << a.ID << endl;
    cout << "Ho & Ten : " << a.name << endl;
    cout << "Tuoi : " << a.age << endl;
    cout << "Lop : " << a.className << endl;
    cout << "GPA : " << a.gpa << endl;
}

// thêm nhiều sinh viên 
void inputMultiStu(){
   int term =0;
   cout << "chon so luong sinh vien can nhap" << endl;
   cin >> term;
   cin.ignore();
   for(int i=1;i<=term;i++){
      Student tempStudent;
      cout << "---sinh vien thu " << i <<"---" << endl;
      addStudent(tempStudent);
      StudentList.push_back(tempStudent);
   }
}

// in ra toan bo sinh vien
void displayAllStudents(){
   int n=StudentList.size();
   for(int i=0;i<n;i++){
      outputStudentInfo(StudentList[i]);
   }
}

// tìm sinh viên bằng ID
void searchStudentById(){
cout << "ID sinh vien ban can tim" <<endl;
string termID;
getline(cin,termID);
for(int i=0;i<StudentList.size();i++){
   if(StudentList[i].ID == termID){
      outputStudentInfo(StudentList[i]);
      return;
   }
}
cout << "ID khong ton tai" << endl;
}

//Xóa sinh viên
void deleteStudentById(){
   cout << "ID sinh vien ban can xoa" <<endl;
   string termID;
   getline(cin,termID);
   for(int i=0;i<StudentList.size();i++){
   if(termID == StudentList[i].ID){
      StudentList.erase(StudentList.begin()+i);
      cout << "Xoa thanh cong sinh vien " << termID << endl;
      return;
     }
   }
   cout << "ID khong ton tai" << endl;
   return;
}



// Main...
int main(){
int choice=99;
while(choice != 0){
cout << "---Khoi tao danh sach hoc sinh thanh cong!---" << endl;
cout << "---------------------------------------------" << endl;
cout << "0 de thoat" << endl;
cout << "1 de nhap them sinh vien (ban can chon so luong truoc khi nhap sinh vien)" << endl;
cout << "2 de in ra danh sach sinh vien( in ra tat ca sinh vien )" << endl;
cout << "3 de tim sinh vien theo ID" << endl;
cout << "4 de xoa sinh vien theo ID" << endl;
cout << "---------------------------------------------" << endl;
cout << "nhap lua chon" << endl;
choice = 0;
cin >> choice;
cin.ignore();
switch (choice){
case 0:
   cout << "dang thoat..." << endl;
   break;
case 1:
   inputMultiStu();
   break;
case 2:
   displayAllStudents();
   break;
case 3:
   searchStudentById();
   break;
case 4:
   deleteStudentById();
   break;
default:
cout <<"lua chon khong hop le"<< endl;
break;
}
}
return 0;
}