# Algo_progs
#Summary
There are three programs:

(1) 'rand' creates random ints from 0 to 1000. The count is passed as an argument.

e.g. "./rand 10"

Output:
187
777
243
842
293
808
887
860
634
712

(2) 'double_num' just doubles values it gets from stdin or a file

e.g.
from stdin: './rand 10 | ./double_num'

Output:
double
1762
1180
204
1784
972
1678
740
1196
1750
1562

from file: 'double_num -path ./rand_dig_100.txt'

Output:
double
910
28
436
92
1884
1706
454
1850
...

(3) 'my_sort' is able to sort numbers it get from stdin or file. Available sorting algorithms are atm 'bubble sort' (--bubble), 'selection sort' (--selection), 'insertion sort' (--insertion) and 'quick sort' (--quick)

e.g.
'./rand 10 | ./my_sort --bubble'
or
'./my_sort --path ./rand_dig_100.txt --quick'

That's it.
