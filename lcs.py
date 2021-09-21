def lcs(x,y,m,n):
	if(m == 0 or n == 0):
		return 0

	#if two positions have equal characters, then
	#we should consider it in the sequence
	#so we increment the answer by 1
	if(x[m-1] == y[n-1]):
		return 1 + lcs(x, y, m-1, n-1)
	else:
		#else, we have to check the sequences in both the strings
		#and take the max length from both of them
		return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n))



def main():
	x = "aggtab"
	y = "gxtxayb"

	m = len(x)
	n = len(y)

	print(lcs(x,y,m,n))


if __name__ == "__main__":
	main()