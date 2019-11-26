int mx_sqrt(int x) {
    if (x == 1) return 1;
    if (x < 0) return 0;
    int left = 0; 
    int right = x / 2 + 1;
    int mid;
    if (right > 46340) right = 46341;
    while (left <= right) { 
        mid = (right - left) / 2 + left;
        if (mid * mid == x) return mid;
        else if (mid * mid > x) right = mid;
        else left = mid;
        if (left + 1 == right) return 0;
    } 
    return 0;
} 
