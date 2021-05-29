int compare_ints(const void * a, const void * b) {
    int arg1 = * (const int *) a;
    int arg2 = * (const int *) b;
    
    return arg1-arg2;
}


int findContentChildren(int* g, int gSize, int* s, int sSize){
    qsort(g, gSize, sizeof(int), compare_ints);
    qsort(s, sSize, sizeof(int), compare_ints);

    int child = 0, cookie = 0;
    while (child < gSize && cookie < sSize) {
        if (g[child] <= s[cookie]) ++child;
        cookie++;
    }
    return child;
}
