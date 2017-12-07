### Vector Data Structure
	This is intended to be most of the C++ vector library, which defines a class Vector and utilizes an array
	with certain restrictions (such as 'out of range' exceptions) and special functions a standard array
	doesn't. Also protects against seg faults.
	
### Functions
	.size()
	.capacity()
	.empty()
	.at(index)
	.front()
	.back()
	.insert(index, value)
	.erase(index)
	.assign(n, value)
	.push_back(value)
	.pop_back()
	.clear()
	.resize(size, value = 0)
	.reserve(n)
	
## Notes
	Why no push_front(value)? Although it is possible to code a function to handle this, even the standard
	vector library doesn't implement this due to the long runtime it would take to push every element back 
	a slot. 
	See Linked List.
