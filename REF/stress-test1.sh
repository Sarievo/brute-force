# Reference from Coursera CP Stress-testing: https://www.coursera.org/learn/competitive-programming-core-skills/lecture/70ymh/stress-testing
for (( test=1;;test++ )) {
  echo Test $test
  ./generate > in
  ./solution < in > out
  ./solution_trivial < in > ans # trivial solutions will likely not pass the online judge but are useful for checking against the final solutions
  diff out ans
  if [ $? -ne 0 ]
  then
    echo Wrong answer
    break
  fi
}
