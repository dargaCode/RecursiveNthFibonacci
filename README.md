# Recursive Nth Fibonacci (With Memoization)
<strong>Language: C</strong>

Apparently recursive Fibonacci is a popular way to teach the value of memoization, and now that I’ve done it I totally see why.

Just for fun, I let the “naive” (non-memoized) solution try to calculate the 75th Fibonacci number.

After half an hour, the stack was 40 million recursive calls deep, but that’s still only 0.0000000000004% percent of the way done!

With memoization, the result is instant. 

I take 2n rather than n recursive calls, just because I think it makes the code more readable. 

Fun stuff! It’s easy, but makes me feel smart, which is a nice combo. 

<img src ="http://41.media.tumblr.com/46b2ea1406ead9c1c7f0d1996d9af2ca/tumblr_inline_nvrxexjs4e1tvc5hi_1280.png" height="400">
