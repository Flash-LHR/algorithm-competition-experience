for (int i = 1; i <= n; i++) a[i] = i;
do {
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
} while (next_permutation(a + 1, a + n + 1));