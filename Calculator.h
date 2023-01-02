#ifndef MESA_CISC187_PROJECT3_CALCULATOR_H
#define MESA_CISC187_PROJECT3_CALCULATOR_H

#include "BigInt.h"
#include "Handler.h"
#include <vector>
#include <string>
#include <stack>
#include <memory>
#include <sstream>
#include <iostream>

// Name : Jamie Anzai
// ID : 5550091018

class Calculator{ 
  std::vector<std::unique_ptr<Handler>> chain;
  std::vector<std::string> formattedTokens; 
  std::stack<BigInt> stack;
  public : 
  
  Calculator(){
    chain.push_back(std::unique_ptr<Handler>(new addHandler));
    chain.push_back(std::unique_ptr<Handler>(new multiplyHandler));
    chain.push_back(std::unique_ptr<Handler>(new exponentiateHandler));
    chain.push_back(std::unique_ptr<Handler>(new operandHandler));
  }

  void calculate_(){ 
    for(int i = 0; i < formattedTokens.size();i++){      
      for(const auto &it: chain){
        if(it->handle(formattedTokens[i]) == true){
          it->performCalc(stack , formattedTokens[i]);  
        }
      }
    }
    formattedTokens.clear();
}
  void formatTokens(std::string x){
    std::istringstream iss(x);
    std::string word; 

    while(iss >> word){
      formattedTokens.push_back(word);
    }
  }
  void printAnswer(){
    if(stack.size() == 1 ){
    std::cout << stack.top() << std::endl;
    stack.pop();
    }
    else if(stack.size() > 1){
      std::cout << "Error: Could not produce a result.\nToo few operators in problem.\nOperands still on problem stack: \n";
      int i = 0;
      while(!stack.empty()){
        BigInt tmp = stack.top();
        stack.pop();
        std::cout << i << ": " << tmp << std::endl;
        i++;
      }
    }
}
};
#endif
