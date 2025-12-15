
vector<int> linear_sieve_mu(int N) {
    vector<int> mu(N+1, 0), primes;
    vector<char> is_comp(N+1, 0);
    mu[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (!is_comp[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }
        for (int p : primes) {
            long long x = 1LL * i * p;
            if (x > N) break;
            is_comp[x] = 1;
            if (i % p == 0) {
                mu[x] = 0;
                break;
            } else {
                mu[x] = -mu[i];
            }
        }
    }
    return mu;
}

vector<ll> mobius_inversion_all(const vector<ll>& f, const vector<int>& mu) {
    int N = (int)f.size() - 1;
    vector<ll> g(N+1, 0);
    for (int d = 1; d <= N; ++d) {
        if (mu[d] == 0) continue;
        for (int m = d; m <= N; m += d) {
            g[m] += (ll)mu[d] * f[m/d];
        }
    }
    return g;
}