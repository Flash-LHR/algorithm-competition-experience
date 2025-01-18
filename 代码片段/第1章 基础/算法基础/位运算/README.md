```c++
void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}
```

```c++
int binary_count1(int a) {
    int count = 0;
    while (a) {
        if (a & 1) ++count;
        a >>= 1;
    }
    return count;
}
 
int binary_count2(int a) {
    int count = 0;
    while (a) {
        a -= a & (-a);
        ++count;
    }
    return count;
}
```

