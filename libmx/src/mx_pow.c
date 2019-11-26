double mx_pow(double n, unsigned int pow) {
    if (pow <= 0) return 1;
    double c = n;
    for(--pow; pow > 0; pow--)
        n = n * c;
    return n;  
}
