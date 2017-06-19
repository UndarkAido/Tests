//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -g -fsanitize=address -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

// https://en.wikipedia.org/wiki/AddressSanitizer

int main(int argc, char **argv){
  int *array = new int[100];
  delete [] array;
  return array[argc]; // BOOM
}
