//
// Created by bhagirathi on 3/23/2018.
//
int prime[10005];

void sieve(){
    prime[0]=0;
    prime[1]=0;
    prime[2]=1;
    int i,j;
    for(i=2;i<10005;i++)
        prime[i]=1;

    for(i=2;i<10005;i++)
    {
        if(prime[i]==1)
        {
            for(j=2*i;j<10005;j+=i)
                prime[j]=0;
        }
    }
}
