/*Given an integer num, return the number of digits in num that divide num.

An integer val divides nums if nums % val == 0.*/
int countDigits(int num){
    int t,sum=0;
    int n=num;
    while(n>0){
        t=n%10;
        if(num%t==0){
            sum+=1;
        }
        n/=10;
    }
    return sum;
}
