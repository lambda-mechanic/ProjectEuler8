# ProjectEuler8
My C++ solution to PE 8 at https://projecteuler.net/archives

The problem is stated as follows:



*The four adjacent digits in the 1000-digit number that have 
the greatest product are 9 × 9 × 8 × 9 = 5832.

*73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450*

*Find the thirteen adjacent digits in the 1000-digit number 
that have the greatest product. What is the value of this product?*

My solution firstly reorganizes the 1000-digit number given. This is simply
one way of solving the problem. Other solutions can easily be created for the
dataset inputted as-is.
The number is pasted into a text file and then all the line breaks are deleted 
so that the number is displayed on a single line of a txt file.
The std::getline() function is used in order to capture the number as a
string. Then the number is combed through 13 digits at a time using a for loop. 
The substr's pos value is 'i' and its len value is 13. This ensures each time
the loop iterates, and i increases by 1, all the values will move right by one.
The substring is then converted to a long long using std::stoll(). A second for
loop follows, nested within the first, that 'chops' each digit off of the 
converted substring long long by finding the result of a % 10 operation on it. 
The long long is then divided by ten, in order to make the second last digit the
new last digit, before the digit which is chopped is set to a place in an array
called long long input[13]. Finally, still within the nested for loop, the
input[j], where j is the nested for loop's iterative variable, is multiplied by
a variable called long long constant(initalized to 1) before becoming constant's
new value. After exiting the nested for loop, but still within the first for 
loop, an if else statement tests to see whether constant's new value is greater 
than a long long called product. If so, product is set to constant and constant 
is set to 1 again. Otherwise, constant is simply set to 1 again. This ensures 
that constant is always 1 when the loop reiterates to test the next set of 
values and that product is always equal to the largest product calculated sofar.

