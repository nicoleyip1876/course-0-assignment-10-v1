#include <iostream>

struct Fraction {
  int numerator;
  int denominator;
};

/* Asks user for number input
 * Returns:
 *   integer: user_input_1, the number the user inputs
 */
Fraction UserInput() {
  std::cout << "Enter a numerator: " << std::endl;
  Fraction user_input;
  std::cin >> user_input.numerator;

  std::cout << "Enter a denominator: " << std::endl;
  std::cin >> user_input.denominator;

  return user_input;
}

// returning the greatest common factor
int GreatestCommonFactor(int num1, int num2) {
  for (int i = num1; i > 1; i--) {
    if ((num1 % i == 0) && (num2 % i == 0)) {
      //std::cout << i << std::endl;
      return i;
    }
  }
  return 1;
}

// adding the simplified fraction code
Fraction Simplify(Fraction value) {
  int gcf = GreatestCommonFactor(value.numerator, value.denominator);
  Fraction result;
  result.numerator = value.numerator / gcf;
  result.denominator = value.denominator / gcf;
  return result;
}

/* Asks user for operator
 * Returns:
 *   char: user_input_operator, the operator that the user enters
 */
char OperatorsInput() {
  std::cout << "Enter operator (+ - * / % =):" << std::endl;
  char user_input_operator;
  std::cin >> user_input_operator;
  return user_input_operator;
}

// Common denominator function. Multiply the opposie demoninators with each
// other
Fraction SameDenom(char input_operator,int value_numerator,int value_denominator,int value2_numerator,int value2_denominator){
  // starts here of identify common denominator (formally was repeating so I put this in a function)
  Fraction three;

  int modified_dem1 = value_denominator;
  int modified_dem2 = value2_denominator;
  int modified_num1 = value_numerator;
  int modified_num2 = value2_numerator;

  modified_dem2 = value_denominator * value2_denominator;
  modified_num2 = value2_numerator * value_denominator;
  //std::cout << modified_num2 << "/" << modified_dem2 << std::endl;

  // Example: 15 * 7, then 7 * 15

  modified_num1 = value2_denominator * value_numerator;
  modified_dem1 = value2_denominator * value_denominator;
  //std::cout << modified_num1 << "/" << modified_dem1 << std::endl;
  // This code part ends (the part where we identify the common denominator by multiply the opposite denom)

  if (input_operator == '+') {
    three.numerator = modified_num1 + modified_num2;
    three.denominator = modified_dem1;
    Fraction simplified = Simplify(three);
    std::cout << simplified.numerator << "/" << simplified.denominator;
    //returns the simplified version of adding 2 fractions
    return three;

  } else if (input_operator == '-') {
      three.numerator = modified_num1 - modified_num2;
      three.denominator = modified_dem1;
      Fraction simplified = Simplify(three);
      std::cout << simplified.numerator << "/" << simplified.denominator;
      //returns the simplified version of subtracting 2 fractions
      return three;

  } else if (input_operator == '*') {
      three.numerator = modified_num1 * modified_num2;
      three.denominator = modified_dem1;
      Fraction simplified = Simplify(three);
      std::cout << simplified.numerator << "/" << simplified.denominator;
      //returns the simplified version of multiplying 2 fractions
      return three;

  } else if (input_operator == '/') {
      three.numerator = modified_num1 / modified_num2;
      three.denominator = modified_dem1;
      Fraction simplified = Simplify(three);
      std::cout << simplified.numerator << "/" << simplified.denominator;
      // print out the simplified version of dividing 2 fractions
      return three;
 
  } else if (input_operator == '%') {
      three.numerator = modified_num1 % modified_num2;
      three.denominator = modified_dem1;
      Fraction simplified = Simplify(three);
      std::cout << simplified.numerator << "/" << simplified.denominator;
      // return out the simplified version of modding  2 fractions 
      return three;
  } else {
      return three;
  }
}


/* Asks user for operator, input, and executes the equation. These are
 * repetitive steps so we call this function 4 times. Args:
 *   user_input_from_main: user input from main
 *   user_input_operator: operator that user input
 *   new_user_input: new user input
 * Returns:
 *   integer: answer, output of the equation
 */
Fraction CallingOtherFunctions(Fraction user_input_from_main,char user_input_operator) {
  Fraction answer;
  Fraction new_user_input;

  if ((user_input_operator == '+' || user_input_operator == '-') || (user_input_operator == '%') || (user_input_operator == '/') || (user_input_operator == '*')) {
    new_user_input = UserInput();
    // I don't know how to bring the [VALUE OF] user_input_1 from the main function. You can bring values from previous function to functions using arguements.

    // this takes the user input from of operator, user_input from the main function, and a new user_input.
    answer = SameDenom(user_input_operator, user_input_from_main.numerator,user_input_from_main.denominator, new_user_input.numerator, new_user_input.denominator);
    return answer;
  } else {
    answer = Simplify(user_input_from_main);
    std::cout << answer.numerator << "/" << answer.denominator;
    return answer;
  } 
}

int main() {
  std::cout << "This code is calculator. Enter = for value to be returned." << std::endl;

  Fraction answer = UserInput();
  answer = Simplify(answer);
  char user_input_operator = 'a';

  while (!(user_input_operator == '=')) {
    user_input_operator = OperatorsInput();
    answer = CallingOtherFunctions(answer, user_input_operator);
  }
  return 0;
}