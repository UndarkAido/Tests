//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>
#include <vector>
#include <ctype.h>
#include <functional>

std::string removeMentions(std::string content);
void scan(std::string& content, const unsigned long i, const unsigned long oldi, const int frontSize);

int main(){
  std::string content = "potato <@305058659799400448> words <@!305058659799400448> hi <@!305058659799400448>";
  content = removeMentions(content);
  std::cout << content << std::endl;
}

std::string removeMentions(std::string content){
  unsigned long i;
  unsigned long oldi;
  for(i = content.size() - 22, oldi = i + 1; i < oldi; i = std::min(i - 1, content.size() - 22)){
    if(content.substr(i, 3) == "<@!"){
      scan(content, i, oldi, 3);
    }else if(content.substr(i, 2) == "<@"){
      scan(content, i, oldi, 2);
    }
    oldi = i;
  }
  return content;
}

void scan(std::string& content, const unsigned long i, const unsigned long oldi, const int frontSize){
  bool isMention = true;
  for(int n = i + frontSize; n < i + frontSize + 18 && isMention; n++){
    isMention = isdigit(content.at(n));
  }
  if(isMention && content.at(i + frontSize + 18) == '>'){
    if(content.size() > i + frontSize + 19 && content.at(i + frontSize + 19) == ' '){
      content = content.substr(0, i) + content.substr(i + frontSize + 20);
    }else{
      content = content.substr(0, i) + content.substr(i + frontSize + 19);
    }
  }
}
