bool isPalindrome(char * s){
    // Make placeholder arr (reusing the memory of s) for the cleaned up string
    char *arr = s;

    // Append valid characters to arr
    for (char *c = s; *c; c++) {
        if (*c > 64 && *c < 91) {
            *arr = tolower(*c);
            arr++;
        }
        else if (*c > 96 && *c < 123) {
            *arr = *c;
            arr++;
        }
        else if (*c > 47 && *c < 58) {
            *arr = *c;
            arr++;
        }
    }

    // Close the cleaned up string
    *arr = '\0';

    // Check if palindrome
    arr = s;
    for (int i = 0, len = strlen(arr); i < len / 2; i++)
        if (arr[i] != arr[len - i - 1])
            return false;

    return true;

}