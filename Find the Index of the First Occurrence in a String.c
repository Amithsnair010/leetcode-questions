//Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
int strStr(char *haystack, char *needle) {
    if (!*needle) {
        return 0;
    }

    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len > haystack_len) {
        return -1;
    }

    for (int i = 0; i <= haystack_len - needle_len; i++) {
        int j;
        for (j = 0; j < needle_len; j++) {
            if (haystack[i + j] != needle[j]) {  
                break;
            }
        }

        if (j == needle_len) {  
            return i;
        }
    }
    return -1;
}
