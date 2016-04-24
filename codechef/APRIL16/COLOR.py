t = int(raw_input())
while t:
	t-=1
	n = int(raw_input())
	string = raw_input()

	#red
	red = 0
	for char in string:
		if char=='G' or char=='B':
			red+=1 
	blue = 0
	for char in string:
		if char=='G' or char=='R':
			blue+=1 
	green = 0
	for char in string:
		if char=='R' or char=='B':
			green+=1 

	print min(red,green,blue)