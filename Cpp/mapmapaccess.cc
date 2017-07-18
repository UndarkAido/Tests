//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -std=c++11 -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>
#include <map>

int main(){
  std::map<char, std::map<int, float> > mymap = {
    {
      'a',{
        {1, 1.1},
        {2, 1.2},
        {3, 1.3}
      }
    },{
      'b', {
        {1, 2.1},
        {2, 2.2},
        {3, 2.3}
      }
    },{
      'c', {
        {1, 2.1},
        {2, 2.2},
        {3, 2.3}
      }
    }
  };
  for(auto sub : mymap){
    std::cout << sub.first << '\n';
    for(auto item : sub.second){
      std::cout  << "  " << item.first << ", " << item.second << '\n';
    }
    std::cout << '\n';
  }
}
