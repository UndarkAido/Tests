//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0, 1, 2, 3, 4};
    auto it = v.end() - 1;
    std::cout << *it << std::endl;
    v.push_back(5);
    std::cout << *it << std::endl;
    v.insert(v.begin(), -1);
    std::cout << *it << std::endl;
    for(auto i : v){
        std::cout << i << ' ';
    }
    v.erase(it);
}
