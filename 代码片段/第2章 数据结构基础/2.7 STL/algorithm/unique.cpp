a.erase(unique(a.begin(), a.end()), a.end()) //  vector去重
int m = unique(a + 1, a + n + 1) - (a + 1); //  数组去重