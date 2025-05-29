
- ft_is_circular_sorted

Conditional swap push can be executed as soon as there are elements in B
Maybe a check to see if a double instruction can be made

Q1 = [0 - 25]	Q4  = [75    - 100]
O1 = [0 - 12.5]	O8  = [87.5  - 100]
H1 = [0 - 6.25] H16 = [93.75 - 100]

## Phase 1: Binary Push above Median
The function will either execute PB or RROT A, depending on its comparison to the median. The threshold to execute PB initially is above the median (50%).
B will receive elements above the median, but when receiving these elements, will rotate the received element towards the bottom if it is greater than 75%
Double rotate operations here can be optimized in post when reading the instruction list

This will go on until half of the elements have been pushed, resulting in:
A = [0 - 50]
B = [75 - 100] [50 - 75]

Now PB's target is above 25, meaning B will receive elements from 25 to 50
(Remember that conditional rotates can be double instructions)

A = [0 - 25]
B = [37.5 - 50] [75 - 100] [50 - 75] [25 - 37.5]

A = [0 - 12.5]
B = [18.75 - 25] [37.5 - 50] [75 - 100] [50 - 75] [25 - 37.5] [12.5 - 18.75]

Finally, we decide that 6.25% is enough of a split
A = [ ]
B = [0 - 6.25] [18.75 - 25] [37.5 - 50] [75 - 100] [50 - 75] [25 - 37.5] [12.5 - 18.75] [6.25 - 12.5]

Push back to A rotating towards the minimum element
A = {0 - 25}
B = [37.5 - 50] [75 - 100] [50 - 75] [25 - 37.5]


