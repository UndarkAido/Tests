//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>

int main(){
  for(int i = -2; i <= 2; i++){
    std::cout << i << " is " << (i ? "true" : "false") << '.' << std::endl;
  }
}
