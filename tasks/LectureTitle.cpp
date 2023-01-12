#include <iostream>

using namespace std;

struct Specialization{
    string value;
    explicit Specialization(string ss){
        value = ss;
    }
};

struct Course{
    string value;
    explicit Course(string ss){
        value = ss;
    }
};

struct Week{
    string value;
    explicit Week(string ss){
        value = ss;
    }
};

struct LectureTitle {
  string specialization;
  string course;
  string week;
  
  LectureTitle(Specialization new_spec, Course new_course, Week new_week){
      specialization = new_spec.value;
      course = new_course.value;
      week = new_week.value;
  }
};

