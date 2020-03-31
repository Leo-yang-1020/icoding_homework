#include<stdio.h>
#include<stdlib.h>
void search(const char *oldstr,const char *in,int *start,int *cnt_oldstr){ //oldstr是要寻找的字符串，in是被寻找的原字符串，start数组标记在原字符串中的起始位置
// cnt_oldstr表示找到的数量 
	int i=0,j=0;
	*cnt_oldstr=0;
	for(;;){
	while (oldstr[j] != '\0' && in[i] != '\0') {
			if (in[i] == oldstr[j]) {
				i++;
				j++;
			}
			else {
				i++;
				j = 0;
			}
		}
		if(oldstr[j]=='\0'){
			start[(*cnt_oldstr)]=i-j;
			(*cnt_oldstr)++;
			j=0;
		}else break;
	}
}
int str_replace(const char* in, char* out, int outlen, const char* oldstr, const char* newstr) {
	int len_old=0,len_newstr=0,len_oldstr=0;
	while (in[len_old] != '\0')
		len_old++;
	while (newstr[len_newstr] != '\0')
		len_newstr++;
	while(oldstr[len_oldstr]!='\0')
		len_oldstr++;
	int start[10]={0};
	int cnt_oldstr; 
	search(oldstr,in,start,&cnt_oldstr);
	int cnt_do=(outlen-1-start[0])/len_newstr;
	int i=1;
	for(;cnt_do>i;i++)
	start[i]+=i*(len_newstr-len_oldstr);
    int j,k=0,l;
	for(i=0,j=0;i<outlen-1&&j<len_old;){
		if(i!=start[k]){
		out[i++]=in[j++];
	}
		else{
			for(l=0;l<len_newstr&&k<cnt_do;l++){
				out[i]=newstr[l];
				i++;
			}
			k++;
		}
	}
	return cnt_do;
}

int main() {
	char in[] = "woainizzy";
	char out[13];
	char oldstr[] = "zzy";
	char newstr[] = "wzj";
	int start[5]={0};
	int num;
//	search(oldstr,in,start,&num);
//	printf("%d ",num);
//	int i;
//	for(i=0;i<num;i++)
//	printf("%d",start[i]);
	num = str_replace(in, out, 14, oldstr, newstr);
	printf("%d %s", num, out);

}
