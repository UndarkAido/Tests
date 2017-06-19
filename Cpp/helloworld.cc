//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>

int main(){
  std::cout << "Hello, World!" << std::endl;
}
