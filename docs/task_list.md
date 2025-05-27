
- ft_is_circular_sorted

Conditional swap push can be executed as soon as there are elements in B
Maybe a check to see if a double instruction can be made

## Phase 1: Binary Push above Median
The function will either execute PB or RROT A, depending on its score. The threshold to execute PB initially is above the median (50).
B will receive elements above the median, but when receiving these elements, will rotate the received element towards the bottom if it is greater than 75%
Double rotate operations here can be optimized in post when reading the instruction list

This will go on until half of the elements have been pushed, resulting in:
A = [0 - 50]
B = [75 - 100] [50 - 75]

Now PB's target is above 25, meaning B will receive elements from 25 to 50
When B receives elements now, it no longer rotates conditionally.
(Remember that conditional rotates can be double instructions)
A = [0 - 25]
B = [25 - 37.5] [75 - 100] [50 - 75] [37.5 - 50]

Rotate back
A = [0 - 25]
B = [75 - 100] [50 - 75] [37.5 - 50] [25 - 37.5]

Push Again
A = [0 - H2]
B = [H2 - H3] [H12 - H16] [H8 - H12] [H6 - H8] [H4 - H6] [H3 - H4]

Rotate back
A = [0 - H2]
B = [H12 - H16] [H8 - H12] [H6 - H8] [H4 - H6] [H3 - H4] [H2 - H3]

A = [ ]
B = [H12 - H16] [H8 - H12] [H6 - H8] [H4 - H6] [H3 - H4] [H2 - H3] [H1 - H2] [0 - H1]

A = [0 -- H8]
B = [H12 - H16] [H8 - H12]

A = [0 -- H8] [H8 - H10]
B = [H10 - H12] [H12 - H16]

A = [0 -- H8] [H8 - H10] [H10 - H12]
B = [H12 - H16]

A = [0 -- H8] [H8 - H10] [H10 - H12] [H12 - H14] [H14 - H16]
B = []

A = [0 -- H8] 
B = [H8 - H10] [H10 - H12] [H12 - H14] [H14 - H16]

## Phase 2: Reverse Push

A = [0 - 3.125] [3.125 - 6.25] 
B = [75 - 100] [50 - 75] [25 - 50] [12.5 - 25] [6.25 - 12.5] 

## Phase 2: Swap Push
When phase 1 ends, it should look something like this:
B = [100 - 75] [75 - 50] [50 - 25] [25 - 12.5] [12.5 - 6.25] [6.25 - 3.125] ...

When pushing back to A, perform a simple check to see if the next element is smaller
If so, swap before pushing. This also checks if the element in A is smaller than the previous element, so a double op can occur
