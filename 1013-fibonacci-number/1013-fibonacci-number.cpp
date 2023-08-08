class Solution {
public:
    int fib(int n) {
        if(n==1){
            return 1;}
        if(n==0){
            return 0;
        }
        int last=fib(n-2);
        int slast=fib(n-1);
        return last+slast ;
    }
};