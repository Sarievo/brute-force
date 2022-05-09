g++ a.cpp   -o a   # Your WA Solution
g++ gen.cpp -o gen # Your Generator
g++ cmp.cpp -o cmp # Your Trivial but *Always Right* Solution
for ((i = 1;;i++)) {
  ./gen $i > input # generate test cases and use the case number as the random seed
  ./a   < input > output 
  ./cmp < input > answer
  diff -Z output answer > /dev/null || break
#  diff -w <(./a < input) <(./cmp < input) || break
  if [ $? -ne 0 ]
  then
    echo Wrong answer at case $i
    bat input
    echo output
    bat output
    echo answer
    bat answer
    break
  fi
  echo "Passed test: " $i
}
