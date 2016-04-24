#include<bits/stdc++.h>

using namespace std;

#define ll long long

string A;
ll H[251234];
ll pow26mod[251234], invpow26mod[251234], mod = 1e9 + 7;

ll pow(ll X, ll Y, ll M) { // O(logY) to calculate (X ^ Y) % M
	ll ret = 1;
	while(Y) {
		if(Y % 2) {
			ret *= X;
			ret %= M;
		}
		Y /= 2;
		X *= X;
		X %= M;
	}
	return ret;
}

ll inverse(ll A, ll M) { // calculates (1/A) % M, (M MUST BE PRIME)
	return pow(A, M - 2, M);
}

void precompute_mod26() { // linearly compute pow(26, i, mod) as well as pow(1/26, i, mod)
	pow26mod[0] = 1;
	invpow26mod[0] = 1;
	for(int i = 1; i < 251234; i += 1) { 
		pow26mod[i] = pow26mod[i - 1] * 26;
		pow26mod[i] %= mod;
		invpow26mod[i] = inverse(pow26mod[i], mod);
	}
}

ll prefixhash(string A, ll * H) { // takes O(N) time to pre compute hash[A[0...i]] for all i
	int slen = A.size();
	H[0] = A[0] - 'a';
	for(int i = 1; i < slen; i += 1) {
		H[i] = H[i - 1] + (A[i] - 'a') * pow26mod[i]; // A[i] - 'a' does [a, z] to [0, 25]
		H[i] %= mod;
	}
}

ll substringhash(ll * H, int i, int j) { // post prefixhash construction, O(1) to return a subtring's hash
	ll ret = H[j];
	if (i > 0) ret -= H[i - 1];
	if(ret < 0) ret += mod;
	ret *= invpow26mod[i];
	return ret % mod;
}

int main() {

}