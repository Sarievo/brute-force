Basic idea: We have a generator, a trivial solution and a potentially optimal solution that could be wrong.

Using a bash script: 
1. within a endless loop, we use the generator to generate the test cases using the cases' number as the random seed
2. we plug the test cases into the always-correct trivial solution and into the potentially optimal solution
3. compare their output against each other, if they're different, we are getting the wrong answer

We can test the solution thousand times in 1 minute.

Sometimes the brute-force solution is much easier to come up with, but it will very likely get a TLE. So we could use the trivial solution as a ground to test against further optimal solutions. But if the generator/checker is complex, it may not worth to do so and better put our energy to better use.
