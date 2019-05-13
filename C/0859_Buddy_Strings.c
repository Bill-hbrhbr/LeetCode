bool buddyStrings(char* A, char* B) 
{
    int i, j;
    char *lenA = A, *lenB = B, ch1, ch2;
    bool letter[26] = {false};
    bool equal = false, found = false;

    while (*lenA == *lenB){
        if (!*lenA && equal)
            return true;
        else if (!*lenA)
            return false;
        if (!equal && letter[*lenA - 'a'])
            equal = true;
        if (!equal)
            letter[*lenA - 'a'] = true;
        lenA++;
        lenB++;
    }
    ch1 = *(lenA++);
    ch2 = *(lenB++);
    while (*lenA == *lenB) {
        if (!*lenA)
            return false;
        lenA++;
        lenB++;
    }
    if (!(ch1 == *lenB++ && ch2 == *lenA++))
        return false;
    while (*lenA == *lenB) {
        if (!*lenA)
            return true;
        lenA++;
        lenB++;
    }
    return false;
}