t = int(raw_input())
while t!=0:
	t-=1
	r,g,b = map(int,raw_input().split())
	k = int(raw_input())
	if r>=k and g>=k and b>=k:
		print k*3-2
	elif (r<k and g>=k and b>=k) or (r>=k and g<k and b>=k) or (r>=k and g>=k and b<k):
		print min(r,g,b) + 2*(k-1) + 1
	else:
		temp = [item for item in [r,g,b] if item not in [max(r,g,b)]]
		ans = 0
		for i in temp:
			ans+=i
		print ans+k
