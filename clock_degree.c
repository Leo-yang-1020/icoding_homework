#include<stdio.h>
int main(){
	int T,i=0,minute,hour;
	int degree_hour,degree_minute,total_time,degree;
	scanf("%d",&T);
	for(;i<T;i++){
		scanf("%d:%d",&hour,&minute);
		if(hour>=12)
		hour-=12;
		if(minute%2==0){
			degree=30*hour-5.5*minute;
			if(degree<0)
			degree=degree*-1;
			if(degree>180)
			degree=360-degree;
			printf("%d\n",degree);
		}
		else{
			degree=60*hour-11*minute;
			if(degree<0)
			degree=degree*-1;
			if(degree>360)
			degree=720-degree;
			printf("%d/2\n",degree);
		}
	}
} 
