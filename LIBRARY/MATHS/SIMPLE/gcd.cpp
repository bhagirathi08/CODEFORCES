//
// Created by bhagirathi on 3/23/2018.
//
long long gcd(long long a, long long b) {
    if (!b) return a;
    else return (gcd(b, a%b));
}
