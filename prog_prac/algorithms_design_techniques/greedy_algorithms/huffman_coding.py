from heapq import heappush, heappop, heapify
from collections import defaultdict

def HuffmanEncode(ch_freq):
	heap = [[freq,[sym,""]] for sym,freq in ch_freq.items()]
	heapify(heap)
	while len(heap) > 1:
		lo = heappop(heap)
		hi = heappop(heap)
		for pair in lo[1:]:
			pair[1] = '0' + pair[1]
		for pair in hi[1:]:
			pair[1] = '1' + pair[1]
		heappush(heap,[lo[0]+hi[0]]+lo[1:]+hi[1:])
	return sorted(heappop(heap)[1:],key = lambda p:(len(p[-1]),p))

inputText = "Hello World"
ch_freq = defaultdict(int)
for ch in inputText:
	ch_freq[ch] += 1

huffCodes = HuffmanEncode(ch_freq)
print("Symbol\tFrequency\tHuffman Code")
for p in huffCodes:
	print("%s\t%s\t\t%s"%(p[0],ch_freq[p[0]],p[1]))
