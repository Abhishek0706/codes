int p = 31;

vll hh(100001, 0);
vll pw(100001, 0);

void calculate(string s) {
	int n = s.length();
	f(i, 0, n) {
		if (i == 0) {
			hh[i + 1] = s.at(i) - 'a';
			pw[i] = 1;
		}
		else {
			hh[i + 1] = (p * (hh[i]) + (s.at(i) - 'a'))mm;
			pw[i] = (p * pw[i - 1])mm;
		}
	}
}

int gethash(int index, int length) {

	return (hh[index + length] - (pw[length] * hh[index])mm + M)mm;
}

// call calculate at the beginning in main
