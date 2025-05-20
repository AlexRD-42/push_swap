1) Neural Net (Online)
Given that the maximum input size is known, a neural net could determine the best instruction

- Would require creating a function to determine the best instruction anyways for training
- Would be limited to an input size (Could be improved with a least squares fit)
- Would be extremely annoying to do with norminette

Assuming one layer, 512 x 11 weights and 11 biases

2) Look Ahead (Online)
An algorithm that instead of taking the best local step, tries to approximate the best global step through calculating N steps

- Would require asssigning scores for each instruction given a determined input
- Would quickly grow out of control if no input reduction is applied (11^N)
	Could choose the 4 best (4^N)
	Or all scores that satisfy a minimum score, with a growing requirement for total running score

3) Linear approximation
Derive a linear function from the array, and determine distance to best position from the delta of (f(x) - x)

This could be done by just getting the pos difference between the sorted array and the current array

4) Pre-Sort
Pre-sort the array and determine the best instruction set

___

Is it good to push half of the elements to B at start?
