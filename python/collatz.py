#usage: python3 collatz.py [number] [iterations]

import sys

if len(sys.argv) >= 3:
	n = int(sys.argv[1])

	for counter in range(int(sys.argv[2])):
		print(n)
		if n % 2 == 0:
			n = n / 2
		else:
			n = 3 * n + 1
	print(n)
else:
	print("usage: python3 collatz.py [number] [iterations]")


