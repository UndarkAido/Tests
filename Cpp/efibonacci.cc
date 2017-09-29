//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit
// Self-executing header. Nice for testing without a terminal.

#include <iostream>

int efibonacci(int n){
  if(n >= 4){      // Positive Cases
    // F(n) = F(n-1) + F(n-2) + F(n-3)
    return efibonacci(n - 1) + efibonacci(n - 2) + efibonacci(n - 3);
  }else if(n <= 0){// Negative Cases
    // F(n-3) = F(n) - F(n-1) - F(n-2)
    return efibonacci(n + 3) - efibonacci(n + 2) - efibonacci(n + 1);
  }else{           // Special Cases of F(1) = 1, F(2) = 1, & F(3) = 1
    return 1;
  }
}

int main(){
  // Print results -15 to 15
  for(int i = -15; i <= 15; i++){
    std::cout << i << ": " << efibonacci(i) << "\n";
  }
}
