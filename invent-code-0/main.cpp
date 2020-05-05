#include <iostream>
#include <string>
using namespace std;

// Point Struct
struct Point {
  int x;
  int y;
};

Point CreatePoint() {
  Point p;
  std::cout << "Enter a X coordinate" << std::endl;
  std::cin >> p.x;

  std::cout << "Enter a Y coordinate" << std::endl;
  std::cin >> p.y;
  return p;
}

// Rectangle Struct
struct Coordinate {
  int x;
  int y;
};

struct RecPoint {
  Coordinate point_1;
  Coordinate point_2;
};

//user enters in rectangle coordinates
RecPoint RectanglePoint() {

  RecPoint r; 

  std::cout << "Enter the x coordinate" << std::endl;
  std::cin >> r.point_1.x;

  std::cout << "Enter the second x coordinate" << std::endl;
  std::cin >> r.point_2.x;

  std::cout << "Enter the y coordinate" << std::endl;
  std::cin >> r.point_1.y;

  std::cout << "Enter the second y coordinate" << std::endl;
  std::cin >> r.point_2.y;

  return r;
} 

struct appearance {
  int age;
  // we didn't go over which type can handle multiple characters like output to name, eye color, location
  //eye_color;
  unsigned short height;
  unsigned short weight;
  char gender;
};

struct name {
  //first name, middle name, last name
};

struct date {
  unsigned short month;
  unsigned short day;
  unsigned short year;
};

struct location {
  //address
};


struct License {
  appearance vaibhav_looks;
  //name vaibhav_name;
  date vaibhav_issue_date;
  date vaibhav_expiration_date;
  date vaibhav_birthday;
  //location vaibahv_location;
};

appearance VaibhavAppearance() {
  appearance vaibhav;
  std::cout << "What is Vaibhav age? " << std::endl;
  std::cin >> vaibhav.age;
  if ((vaibhav.age > 110) || (vaibhav.age < 16)) {
    std::cout << "What is Vaibhav age? " << std::endl;
    std::cin >> vaibhav.age;
  }

  std::cout << "What is Vaibhav height in inches? " << std::endl;
  std::cin >> vaibhav.height;
  if (vaibhav.height > 108) {
    std::cout << "What is Vaibhav height in inches? " << std::endl;
  std::cin >> vaibhav.height;
  }

  std::cout << "What is Vaibhav weight in pounds? " << std::endl;
  std::cin >> vaibhav.weight;

  std::cout << "What is Vaibhav gender? Enter M for male or F for female " << std::endl;
  std::cin >> vaibhav.gender;
  if ((vaibhav.gender != 'M') && (vaibhav.gender != 'F')) {
    std::cout << "What is Vaibhav gender? Enter M for male or F for female " << std::endl;
    std::cin >> vaibhav.gender;
  }
  return vaibhav;
}

date SimplifyDate() {
  date vaibhav;
  std::cin >> vaibhav.month;
  if (vaibhav.month > 12) {
    std::cout << "Try again. Enter month" << std::endl;
    std::cin >> vaibhav.month; 
  }
  std::cout << "Enter day" << std::endl;
  std::cin >> vaibhav.day;
  if (vaibhav.day > 31) {
    std::cout << "Enter day" << std::endl;
    std::cin >> vaibhav.day; 
  }
  return vaibhav;
}

date SimplifyYear() {
 date vaibhav;
  std::cout << "Enter year" << std::endl;
  std::cin >> vaibhav.year;
  if (vaibhav.year > 2020) {
    std::cout << "Enter year? " << std::endl;
    std::cin >> vaibhav.year;
  }
  return vaibhav;
}

date VaibhavDate() {  
  date vaibhav;
  //std::cout << "Enter name" << std::endl;
  //std::cin >> vaibhav.name;

  //std::cout << "Eye color?" << std::endl;
  //std::cin >> vaibhav.eye_color;

  //std::cout << "Location?" << std::endl;
  //std::cin >> vaibhav.location;

  //expire date, issued date
  std::cout << "What is his birthday? Enter month" << std::endl;
  SimplifyDate();
  SimplifyYear();

  std::cout << "When was license issued? Enter month" << std::endl;
  SimplifyDate();
  SimplifyYear();

  std::cout << "When does his license expired? Enter month" << std::endl;
  SimplifyDate();
  std::cout << "Enter year" << std::endl;
  std::cin >> vaibhav.year;

  return vaibhav;
}

// Calendar Struct
struct Calendar {
  unsigned short month;
  unsigned short day;
  unsigned short hour;
  unsigned short minute;
};

Calendar AppointmentTime() {
  Calendar v;
  std::cout << "Enter the month of the appointment" << std::endl;
  std::cin >> v.month;
  if (v.month > 12) {
    std::cout << "Try again. Enter month" << std::endl;
    std::cin >> v.month; 
  }

  std::cout << "Enter the day of the appointment" << std::endl;
  std::cin >> v.day;
  if (v.day > 31) {
    std::cout << "Try again. Enter day" << std::endl;
    std::cin >> v.day; 
  }

  std::cout << "Enter the hour of the appointment. [Military time]" << std::endl;
  std::cin >> v.hour;
  if (v.hour > 24) {
    std::cout << "Try again. Enter hour" << std::endl;
    std::cin >> v.hour; 
  }

  std::cout << "Enter the minute of the appointment" << std::endl;
  std::cin >> v.minute;
  if (v.minute > 60) {
    std::cout << "Try again. Enter minute" << std::endl;
    std::cin >> v.minute; 
  }

  return v;
}

//checking if vaibhav appointment matches with second appointment
Calendar CheckMatch(Calendar second_appointment, Calendar v) {
  if ((second_appointment.month == v.month) && (second_appointment.day == v.day) && (second_appointment.hour == v.hour) && (second_appointment.minute == v.minute)) {
      std::cout << "Invalid apointment. Same day" << std::endl;
    } 
  else {
    std::cout << "Confirmed!" << std::endl;
    }
  return second_appointment;
} 

//asking user for second appointment
Calendar SecondAppointmentAsk(Calendar v) {
Calendar second_appointment;
 char schedule_again;
  std::cout << "Would you like to schedule another appointment. Enter Y for yes or N for no" << std::endl;
  std::cin >> schedule_again;
  if (schedule_again == 'Y') {
    second_appointment = AppointmentTime();
    Calendar match = CheckMatch(second_appointment, v);
    cout << "month that matches is: " << match.month;
  }
  else if (schedule_again == 'N') {
    std::cout << "No problem. See you soon!";
  }
  else {
    std::cout << "You did not enter a Y or N. Goodbye" << std::endl;
  }
  return second_appointment;
}

int main() {
// Point Struct
  Point p = CreatePoint();
  std::cout << "X: " << p.x << std::endl;
  std::cout << "Y: " << p.y << std::endl;

// Rectangle Struct
  RecPoint r = RectanglePoint();
  std::cout << "The rectangle is: "<< std::endl; 
  std::cout << "(" << r.point_1.x << "," << r.point_1.y << ")" << std::endl;
  std::cout << "(" << r.point_1.x << "," << r.point_2.y << ")" << std::endl;
  
  std::cout << "(" << r.point_2.x << "," << r.point_1.y << ")" << std::endl;
  std::cout << "(" << r.point_2.x << "," << r.point_1.y << ")" << std::endl;

  // Driver License Struct
  License vaibhav;
  vaibhav.vaibhav_looks = VaibhavAppearance();
  vaibhav.vaibhav_issue_date = VaibhavDate();
  vaibhav.vaibhav_expiration_date = VaibhavDate();
  vaibhav.vaibhav_birthday = VaibhavDate();

  // Calendar Struct
  std::cout << "You are here to enter an appointment. All appointments are for this year, 2020 only. You can only make a max of 2 appointments at a time" << std::endl;
  
  char name;
  std::cout << "What is your name that I shall make the appointment under?" << std::endl;
  std::cin >> name;

  Calendar you = AppointmentTime();
  std::cout << you.month << "/" << you.day << "/2020" << std::endl;
   
  Calendar second_appointment = SecondAppointmentAsk(you);
  cout << "This is the day you confirmed " << second_appointment.day;

}
