### Basic idea: 
We have a generator, ~~a trivial solution and a potentially optimal solution that could be wrong.~~
<br>2 solutions that we do not know right or wrong, we check these two answers against each other.

#### Using a bash script: 
1. within a endless loop, we use the generator to generate the test cases using the cases' number as the random seed
2. ~~we plug the test cases into the always-correct trivial solution and into the potentially optimal solution~~<br>we plug in the test-cases generator into two different solutions
3. compare their output against each other, if they're different, we are getting the wrong answer

Addtional: the test cases need to be generally small, so we're able to generate the edge cases in feasible time: consider generating all 1s or all 0s in range[1e18] and range[1e5].  

We can test the solution thousand times in 1 minute.

~~Sometimes the brute-force solution is much easier to come up with, but it will very likely get a TLE. So we could use the trivial solution as a ground to test against further optimal solutions.~~ Most of the time, there're several approaches to the same problem: the right solutions always produce identical answers, but the wrong solutions most likely wrong in different parts. And we can use this fact to check the correctness of the script ... Writing simple tests for easier problems will save us attempts during contests, but if the generator/checker is complex, it may not worth to do so and better put our energy to better use.
