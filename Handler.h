#ifndef MESA_CISC187_PROJECT3_HANDLER_H
#define MESA_CISC187_PROJECT3_HANDLER_H

#include "BigInt.h"
#include <string>
#include <stack>

// Name : Jamie Anzai
// ID : 5550091018

struct Handler{
  virtual bool handle(std::string) = 0;
  virtual void performCalc(std::stack<BigInt>& , std::string&) = 0;
  virtual ~Handler() = default;
};


struct addHandler : public Handler{
  bool handle(std::string x){ 
    if(x == "+") return true;  
    return false;
  }
  void performCalc(std::stack<BigInt> &stack , std::string &x){ 
    if(stack.size() > 1){    
    BigInt tmp1 = stack.top();
    stack.pop();
    BigInt tmp2 = stack.top();
    stack.pop();
    tmp1 += tmp2;
    stack.push(tmp1);
    }else {
      std::cout << "Invalid arguments : Not enough operands to execute addition operation. \n";
      if(stack.size() == 1){
        BigInt tmp = stack.top();
        stack.pop();
        std::cout << tmp << std::endl;
      }
    }
  }
};
struct multiplyHandler : public Handler{
  bool handle(std::string x){
    if(x == "*") return true;
    return false;
  }
  void performCalc(std::stack<BigInt> &stack , std::string &x){
    if(stack.size() > 1 ){ 
    BigInt *newNum = new BigInt();
    BigInt tmp1 = stack.top();
    stack.pop();
    BigInt tmp2 = stack.top();
    stack.pop();
    *newNum = tmp1 * tmp2; 
    stack.push(*newNum);
    } else {
      std::cout << "Invalid arguments : Not enough operands to execute multiply operation. \n";
      if(stack.size() == 1){
        BigInt tmp = stack.top();
        stack.pop();
        std::cout << tmp << std::endl;
      }
    }
  }
};
struct exponentiateHandler : public Handler{
  bool handle(std::string x){
    if(x == "^") return true;
    return false;
  }
  void performCalc(std::stack<BigInt> &stack , std::string &x){ 
    if(stack.size() > 1 ){ 
    BigInt *newNum = new BigInt();
    BigInt tmp1 = stack.top();
    stack.pop();
    BigInt tmp2 = stack.top();
    stack.pop();
    *newNum = tmp2 ^ tmp1; 
    stack.push(*newNum);
    }else{
      std::cout << "Invalid arguments : Not enough operands to execute multiply operation. \n";
      if(stack.size() == 1){
        BigInt tmp = stack.top();
        stack.pop();
        std::cout << tmp << std::endl;
      }
    }
  }
};
struct operandHandler : public Handler{
  bool handle(std::string x){
    for(int i = 0; i < x.length();i++){
      if(!isdigit(x[i])) return false; 
    }
    return true;
  }
  void performCalc(std::stack<BigInt> &stack , std::string &x){
    for(char c : x){
      if(c != '0'){ 
        x.erase(0 , x.find_first_not_of('0')); 
      }
    }
    BigInt *newNum = new BigInt(x);
    stack.push(*newNum);
       
    
  }
};



#endif
