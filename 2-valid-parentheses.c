bool isValid(char *s) {
    int len = strlen(s);
	int count = 0;
	int stack[(len / 2) + 1];

    // Remove trivial cases
    if (len % 2)
        return false;

	for (int i = 0; s[i] != '\0'; i++) {

        // Not enough brackets left to close the remaining open brackets in the stack
        if (count > len / 2)
            return false;

        // If char is open bracket add to stack
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[count] = s[i];
            count++;
            continue;
        }

        // If closing bracket but count is 0, there is no open bracket to close
        if (count == 0)
            return false;

        // If closing bracket closes the open bracket at the stack; ASCII arithmetic
        if ((s[i] - stack[count - 1] == 1) ||  (s[i] - stack[count - 1] == 2)) { 
            stack[count - 1] = 0;
            count--;
            continue;
        }

        return false;

    }
    
	// Check stack if empty
	return !stack[0];
}