//
// Created by bhagirathi on 3/31/2018.
//
double ncr[1005][1005];

void comb(){
    ncr[0][0]=ncr[1][0]=ncr[1][1]=1.0;
    for (int i = 2; i <1005 ; ++i) {
        ncr[i][0]=1.0;
        for (int j = 1; j <=i ; ++j) {
            ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
}

