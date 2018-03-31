int reverse(int x) {
    int result = 0;
    while(x){
        int new = x % 10;
        int newResult = result * 10 + new;
        if((newResult - new) / 10 != result) return 0;
        x = x / 10;
        result = newResult;
    }

    return result;
}

//or

int reverse1(int x) {
   long y = x % 10;
   x = x / 10;

   while(x != 0){
       y = (y * 10) + (x % 10);
       x = x / 10;
   }
   if(y > INT_MAX || y < INT_MIN)
       return 0;
   else
       return y;
}
