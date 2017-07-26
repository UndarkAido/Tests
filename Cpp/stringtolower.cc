//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -std=c++11 -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>

int main(){
  std::string str = "AaBbCcDdEeFfGg";
  for(char& c : str){
    c = tolower(c);
  }
  std::cout << str << std::endl;
}
