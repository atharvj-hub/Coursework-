#include<stdio.h>
#include<string.h>
 
long long fact(int n)
{
    if(n <= 1)
        return 1;
    return n * fact(n - 1);
}
 
int main()
{
    char word[100];
    int freq[26] = {0}, i, len;
    printf("Enter a word: ");
    scanf("%s", word);
    len = strlen(word);
    for(i = 0; i < len; i++)
        freq[word[i] - 'a']++;
    long long result = fact(len);
    for(i = 0; i < 26; i++)
        result /= fact(freq[i]);
    printf("Number of ways to scramble \"%s\" = %lld\n", word, result);
    return 0;
}
