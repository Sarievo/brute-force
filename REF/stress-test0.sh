# this stress-test only tests about runtime error / crashes
for (( test=1;;test++ )) {
  echo Test $test
  ./generate > in
  ./solution < in > out
  if [ $? -ne 0 ]
  then
    echo Runtime error
    break
  fi
}
