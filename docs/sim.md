PB		34715826
PB		3471582	6
PB		347158	62
RROT	34715	628
PB		34715	862
RROT	3471	8625
PB		3471	5862
PB		347		58621
RROT	34		586217
PB		34		758621
PB		3		7586214

## Phase 1: Binary Push above Median
The function will either execute PB or RROT A, depending on its score. The threshold to execute PB initially is above the median (50).
B will receive elements above the median, but when receiving these elements, will rotate the received element towards the bottom if it is greater than 75%
Double rotate operations here can be optimized in post when reading the instruction list

This will go on until half of the elements have been pushed, resulting in:
A = [0 - 50]
B = [75 - 100] [50 - 75]

Now PB's target is above 25, meaning B will receive elements from 25 to 50
When B receives elements now, it will rotate it towards the bottom if it is LOWER than 37.5
This will go on until half of current length of A. When this ends, it will rotate all elements it pushed to the bottom back to the top
(note this chunking costs 12.5% N operations for the back rotations, 6.25% N operations for the conditional rotates)
A = [0 - 25]
B = [75 - 100] [50 - 75] [37.5 - 50] [25 - 37.5]

Now PB's target is above 12.5, meaning B will receive elements from 12.5 to 25
B rotates elements below 18.75, same as before, resulting in:
A = [0 - 12.5]
B = [75 - 100] [50 - 75] [37.5 - 50] [25 - 37.5] [18.75 - 25] [12.5 - 18.75]

This repeats until the minimum range is found, let's say we're happy with 3 passes.
A = [ ]
B = [75 - 100] [50 - 75] [37.5 - 50] [25 - 37.5] [18.75 - 25] [12.5 - 18.75] [6.25 - 12.5] [0 - 6.25]


Target above 12.5:
A = [0 - 12.5]
B = [75 - 100] [50 - 75] [25 - 50] [12.5 - 25]

Target above 6.25 (and let's end it here by pushing everything once we're done)
A = [ ]
B = [75 - 100] [50 - 75] [25 - 50] [12.5 - 25] [6.25 - 12.5] [0 - 6.25]
