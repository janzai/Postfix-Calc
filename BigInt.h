#ifndef MESA_CISC187_PROJECT03_BIGINT_H
#define MESA_CISC187_PROJECT03_BIGINT_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

 // Name : Jamie Anzai
 // Student ID : 5550091018

class BigInt{

  std::string digits;  

  public : 

  BigInt() = default;
  
  BigInt(std::string num){
    digits = "";
    for (int i = num.size() - 1; i >= 0; i--){
      digits.push_back(num[i]);
    }
  }

  int length() const {
    return digits.length();
  }
  std::string getDigits(){
    return digits;
  }
  BigInt &operator=(const BigInt &a) {
    digits = a.digits;
    return *this;
  }
  BigInt &operator+=(BigInt b){
    if(this->length() > b.length()){
      std::swap(this->digits, b.digits);
    }
    int la = this->length();
    int lb = b.length();

    BigInt final;
    int carry = 0;
    int i = 0;
    int sum;

    while(i < la){
      sum = (digits[i] - '0') + (b.digits[i] - '0') + carry;
      final.digits.push_back('0' + sum%10);
      carry = sum/10;
      i++;
    }
      while(i < lb){
      sum = (b.digits[i] - '0') + carry;
      final.digits.push_back('0' + sum%10);
      carry = sum/10;
      i++;
    }
    if(carry){
      final.digits.push_back('0' + carry);
    }
    return *this = final; 
  }
  BigInt operator+(BigInt b){
    *this += b;
    return *this; 
  }
  BigInt &operator*=(BigInt b){
    std::reverse(digits.begin() , digits.end());
    std::reverse(b.digits.begin() , b.digits.end());
    if(digits == "0" || b.digits == "0"){
      digits = "0";
      return *this;
    }
    std::vector<int> num(this->length() + b.length() , 0);

    for(int i = this->length() - 1; i >= 0; i--){
      for(int j = b.length() - 1; j >= 0; j--){
        num[i+j+1] += (this->digits[i] - '0') * (b.digits[j] - '0');
        num[i+j] += num[i+j+1] / 10;
        num[i+j+1] %= 10;
      }
    }

    int i = 0;
    while(i < num.size() && num[i] == 0){
      i++;
    }
    std::string finalDigits;
    while(i < num.size()){
      finalDigits.push_back(num[i++] + '0');
    }
    BigInt final(finalDigits);
    return *this = finalDigits; 
  }
  BigInt operator*(BigInt b){
    *this *= b;
    return *this;
  }
  BigInt &operator^=(BigInt b){
    if(b.digits == "0" || this->digits == "0"){
      BigInt tmp("0");
      *this = tmp;
      return *this;
    }
    BigInt tmp = *this;
    BigInt one("1");
    BigInt iterator("1");

    while(iterator.digits != b.digits){
      *this*=tmp;
      iterator+=one;
    }
    return *this;
  }
  BigInt operator^(BigInt b){
    *this ^= b;
    return *this; 
  }
};
inline std::ostream &operator<<(std::ostream &os , BigInt x){
  std::string y = x.getDigits();
  for(int i = y.length() -1; i >= 0; i--){
    os << y[i];
  }
  return os;
}
#endif
