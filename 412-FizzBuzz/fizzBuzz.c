/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void itoa(char* str, int num){
    int i = 0;
    int j=0;
    char s[5];
    while(num){
        s[i] = '0' + (num%10);
        num /= 10;
        ++i;
    }
    while(i){
        *(str+(j++)) = s[--i];
    }
    *(str+j) = '\0';
}


char** fizzBuzz(int n, int* returnSize) {

    *returnSize = n;
    char** outputString = (char**)malloc(*returnSize * sizeof(char*));
    int i;
    for(i=1; i<=(*returnSize); ++i){
        if(i % 15 == 0){
            *(outputString + i -1) = (char*)malloc(strlen("FizzBuzz")+1);
            *(outputString + i -1) = "FizzBuzz";
        }
        else if(i % 5 == 0){
            *(outputString + i -1) = (char*)malloc(strlen("Buzz")+1);
            *(outputString + i -1) = "Buzz";
        }
        else if(i % 3 == 0){
            *(outputString + i -1) = (char*)malloc(strlen("Fizz")+1);
            *(outputString + i -1) = "Fizz";
        }
        else{
            outputString[i-1] = (char*)malloc(5*sizeof(char));
            itoa(outputString[i-1], i);
        }
    }
    return outputString;
}