# Swap
01234 -> 10234

# Push

# Rotate

# Reverse Rotate


sa/b (swap a/b): Swap the first 2 elements at the top of stack a/b.
	Do nothing if there is only one element or none.
ss : sa and sb at the same time.

pa/b (push a/b): Take the first element at the top of b/a and put it at the top of a/b.
	Do nothing if b is empty.

ra/b (rotate a/b): Shift up all elements of stack a/b by 1.
	The first element becomes the last one.
rr : ra and rb at the same time.

rra/b (reverse rotate a/b): Shift down all elements of stack a/b by 1.
	The last element becomes the first one.
rrr : rra and rrb at the same time.

# INIT:
	A: 856312
	B: 
_________________
# SA:
	A: 856321
	B: 
_________________
# PB PB PB:
	A: 856
	B: 123
_________________
# RA RB: (First becomes last)
	A: 685
	B: 312
_________________
# RRA RRB: (Last becomes first)
	A: 856
	B: 123
_________________
# PA PA PA:
	A: 856321
	B: