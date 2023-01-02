#include <iostream>
#include <string>
#include "BigInt.h"
#include "Handler.h"
#include "Calculator.h"
#include "options.h"

// Name : Jamie Anzai
// ID : 5550091018

int main(int argc , char*argv[])
{
  option options;
  options = get_options(argc , argv);
  
  Calculator calculator; 
  std::string text;
if(options.verboseOutput == false){ 
  
  while(getline(std::cin, text)){
    if(text.size() != 0 && text[0] != '#'){ 
    if(text == "quit")break;
    calculator.formatTokens(text);
    calculator.calculate_();
    calculator.printAnswer();
    std::cout << "\n";
    }
  }
}else {
  while(getline(std::cin , text)){
      if(text.size() != 0 && text[0] != '#'){
      if(text == "quit") break;
      std::cout << text << " = ";
      calculator.formatTokens(text);
      calculator.calculate_();
      calculator.printAnswer(); 
      std::cout << "\n";
      }
    }
}

  return 0;
}
