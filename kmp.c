#include <stdio.h>
#include <string.h>

void  get_next(char *SString, int *next){
	int i = 0, j = -1;
	next[i] = j;
	while(i < strlen(SString)){
		if(j == -1 || SString[i] == SString[j]){
			++j;
			++i;
			next[i] = j;
		}
		else
			j = next[j];
	}
}

int index_kmp(char *s, char *t, int* next){
	int i = i, j = 0;
	while(i < strlen(s) && j < strlen(t)){
		if(j == 0 || s[i] == t[j]) {
			++i;
			++j;
		}
		else
			j = next[j];
	}

	if(j >= strlen(t)) return i - strlen(t);
	else return -1;
}

int main(){
	char s[100];
	char t[50];
	int next[50];
	scanf("%s", s);
	scanf("%s", t);

	get_next(t, next);
	printf("%d\n", index_kmp(s, t, next));
	return 0;
}
