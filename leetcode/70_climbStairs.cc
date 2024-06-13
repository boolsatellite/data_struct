int climbStairs(int n) {
    if(n == 2) return 2;
    if(n == 1) return 1;
    if(n == 0) return 0;

    int* arr = new int[n+1];
    arr[1] = 1;
    arr[2] = 2;

    int i = 3;
    for( ;i <= n ; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    int ret = arr[n];
    delete [] arr;
    return ret; 
}