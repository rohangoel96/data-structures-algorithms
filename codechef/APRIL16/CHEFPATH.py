t = int(raw_input())
while t:
	t-=1
	n,m = map(int, raw_input().split())
	if n%2==0 or m%2==0:
		print "Yes"
	else:
		print "No"