class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> index(n);
        for(int i=0;i<n;i++){
            if(i%3==0) index[i]+="Fizz";
            if(i%5==0) index[i]+="Buzz";
            if(index[i].empty()) index[i]+= to_string(i);
        }
        return index;
    }
};