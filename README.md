# brute-force
Ideas for doing brute-force and stress-testing during competitive programming.
- [x] How does this work?
- [x] Write a/serveral test scripts ~in fish shell script~, referencing to [Errichito's video](https://www.youtube.com/watch?v=JXTVOyQpSGM) and Coursera's [CC course](https://www.coursera.org/learn/competitive-programming-core-skills/lecture/70ymh/stress-testing)~, learn fish shell script on the go.~ (it turns out I do not need to write fish scripts for this)
- [x] But how this really works? Check out https://ali-ibrahim137.github.io/competitive/programming/2020/08/23/Stress-Testing.html
- [x] Try this out in at least 5 real problems at Codeforces.

![stress-testing](https://ali-ibrahim137.github.io//assets/img/Stress%20Testing/1.jpeg)
Image from Ali-Ibrahim


Using my `script.sh`:

Compile the generator as `gen`, the one of you solutions as `a` (the solution you want to check), the other one as `cmp` (the always correct solution, may it be slow), then run the script to check the testing results. PS: mswindows may insert \r$ when you edit the UNIX script file and cause it failed to run, use `sed 's/\r$//' file > file_fixed` to recover it.
