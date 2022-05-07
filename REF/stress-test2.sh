# Reference from Errichto https://www.youtube.com/watch?v=JXTVOyQpSGM
for (( i = 1;; ++i )) {
  echo $si
  ./gen $i > in # use the case number as the random seed in Errichto's version
  # ./a < int > out1
  # ./brute < int > out2
  # diff -w out1 out2 || break
  diff -w <(./a < in) <(./brute < in) || break # test your solution against the brute-force solution
}
