```
in: a string word and a string pattern.
out: does pattern match the word? true or false

the pattern: consists of characters * ? a-z
* = can be 0-any number of characters a-z
? = can be a character a-z

sub-problem 0: no * ? only a-z (easy)
sol: one for loop to check characters

sub-problem 1: no * only ? a-z (easy)
sol:
if size_s != size_p:
    return false 
for i size_s:
    if p[i] is character and pi!=si:
        return false
return true

full problem: * only matters when size of p and s are not equal.

ex1:
s: acabacaba
p: a*c*a
gi
  a c a b a c a b a
? 1 0 0 0 0 0 0 0 0 
* 1 1 1 1 1 1 1 1 1 => if mi-1: 1 else: 0
c 0 1 0 0 0 1 0 0 0
* 0 1 1 1 1 1 1 1 1
a 0 0 1 0 1 0 1 0 1 

m[0][0] = (p[0] == s[0])
m[0][j] = 0

a-z => m[i][j] = m[i-1][j] = 1 &&  
```