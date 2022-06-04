Red='\033[0;31m'
NoRed='\033[0m' # No Color, ref at https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux

Green='\033[0;32m' # ref https://www.digitalocean.com/community/questions/how-to-change-the-color-of-the-output-in-linux-bash
NoGreen='\033[0m'


for ((i=1;;i++)) {
  ./gen $i > input # generate test cases and use the case number as the random seed
  ./a      < input > output
  ./cmp    < input > answer
  diff -Z output answer > /dev/null # || break
  # diff -w <(./a < input) <(./cmp < input) || break
  if [ $? -ne 0 ]
  then
    echo -e ${Red}Wrong answer at case${NoRed} $i
    echo input
    cat input
    echo output
    cat output
    echo answer
    cat answer
    break
  fi
  echo -e ${Green}Passed test${NoGreen} $i
}

