bool isAnagram(char * s, char * t){
    int sum = 0;
    int alphabet[26] = {0};
    
    if (strlen(s) - strlen(t))
        return false;
    
    while(*s) {
        alphabet[*s++ - 97]++;
        alphabet[*t++ - 97]--;
    }

    for (int i = 0; i < 26; i++)
        if (alphabet[i])
            return false;

    return !sum;
}