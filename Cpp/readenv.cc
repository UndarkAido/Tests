//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -std=c++11 -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>
#include <cstdlib>

int main(){
  auto envc = std::getenv("EXAMPLE_ENV_VAR");
  int envi = 0;
  try {
    envi = envc ? std::stoi(envc) : 0;
  } catch(...) {}
  if(envi > 0){
    std::cout << "Positive";
  }else if(envi < 0){
    std::cout << "Negative";
  }else{
    std::cout << "Default";
  }
  std::cout << std::endl;
}
