#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int lengthOfLongestSubstring(char* s) {
    if (*s == '\0')
    {
        return 0;
    }
    int count = 0;
    char* cur = s;
    char* next = s + 1;
    while (*cur != '\0')
    {
        int curcount = 0;
        if (*cur == *next)
        {
            while (*cur == *next)
            {
                curcount++;
                cur++;
                next++;
            }    
        }
        if (curcount > count)
        {
            count = curcount;
        }
        cur++;
        next++;
    }
    return count+1;
}
int main()
{
    char* s = "abcabcbb";
    int ret=lengthOfLongestSubstring(s);
    printf("%d", ret);
    return 0;
}
