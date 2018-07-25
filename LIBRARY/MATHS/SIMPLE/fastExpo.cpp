//
// Created by bhagirathi on 3/2/2018.
//
int fast_exp(int base, int exp) {
    int result=1;
    while(exp>0) {
        if(exp%2==1)
            result=(result*base);
        base=(base*base);
        exp/=2;
    }
    return result;
}

