//  在有序数组中查找第一个大于等于x的元素的下标
int i = lower_bound(a + 1, a + n + 1, x) - a;
//  在有序vector中查找最后一个小于等于x的元素（假设存在）
int y = *--upper_bound(a.begin(), a.end(), x);