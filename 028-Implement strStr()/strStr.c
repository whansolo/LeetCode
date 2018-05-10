int strStr(char* haystack, char* needle) {
    if(needle[0]=='\0') return 0;
    char* str_a = haystack;
    char* str_b = needle;
    size_t len_a = strlen(haystack);
    size_t len_b = strlen(needle);
    int a = len_a - len_b;
    while(a-- >= 0){
        size_t i;
        for(i = 0; i < len_b; ++i){
            if(str_a[i] != str_b[i]) break;
        }
        if(i == len_b) return (str_a - haystack);
        
        str_a++;
    }
    return -1;   
}


int strStr(char* haystack, char* needle) {
    int i,j;
    if(needle[0]=='\0')
        return 0;
    for(i=0;haystack[i]!='\0';i++){
        for(j=0;haystack[i+j]==needle[j];j++){
            if(needle[j+1]=='\0')
                return i;
            if(haystack[i+j+1]=='\0')
                return -1;
        }
    }
    return -1;
}