int a = 0, b = n-1;
  while (a <= b) {
  int k = (a+b)/2;
  if (array[k] == x) {
  // x found at index k
  }
  if (array[k] < x) a = k+1;
  else b = k-1;
}

int k = 0;
for (int b = n/2; b >= 1; b /= 2) {
while (k+b < n && array[k+b] <= x) k += b;
}
if (array[k] == x) {
// x found at index k
}


// binary search on answer
int bin_ans(int upr){
	int x = -1;
	for (int jmp = upr; jmp >= 1; jmp /= 2) {
		while (!valid(x+jmp)) x += jmp;
	}
	return x+1;
}


