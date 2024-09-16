#include<stdio.h>
#include<string.h>
char str[100], pat[100], rep[100], ans[100];
int i, j, c, m, k, flag = 0;
void pattern() {
i = j = c = m = 0;
while (str[c] !=
'\0') {
if (str[m] == pat[i]) {
i++;
m++;
if (pat[i] ==
'\0') {
flag = 1;
for (k = 0; rep[k] !=
'\0'; k++, j++) {
ans[j] = rep[k];
}
i = 0;
c = m;
}
}
else {
ans[j] = str[c];
j++;
c++;
m = c;
i = 0;
}
}
ans[j] =
'\0';
}
int main() {
printf("ENTER THE MAIN STRING:");
gets(str);
printf("ENTER THE PATTERN STRING:");
gets(pat);
printf("ENTER THE REPLACE STRING:");
gets(rep);
pattern();
if (flag == 1) {
printf("THE FINAL STRING IS: %s \n"
, ans);
}
else {
printf("THE PATTERN STRING NOT FOUND \n");
}
return 0;
}