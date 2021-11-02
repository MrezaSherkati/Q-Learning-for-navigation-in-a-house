#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include <windows.h>
using namespace std;
int q[6][6];
float y=0.8;

int getmax(int random2,int reward[][6]){
	
	int max=0;
	for(int i=0;i<6;i++){
			
			if(reward [random2][i]==0 || reward [random2][i]==100){
			if(max<q[random2][i])
			max=q[random2][i];
			
		}
		
		}
		return max;
}

void process(int random,int reward[][6]){

	int counter=0;
		int saver[6];
		for(int j=0;j<6;j++){
			
			if(reward [random][j]==0 || reward [random][j]==100){
			saver[counter]=j;
			counter++;
		}
		
		}

		int random2=0;
		random2=rand()%(counter);
		q[random][saver[random2]]=reward[random][saver[random2]]+y*(getmax(saver[random2],reward));	
		
	
		if(saver[random2]!=5){
		process(saver[random2],reward);
		}
		    else if(saver[random2]==5){
	    for(int i=0;i<6;i++){
		for (int j=0; j<6;j++){
			cout<<q[i][j]<<"     ";
		}
		cout<<endl;
	}			
	
		}
	else{
		cout<<"no result";
	}

}



int main(){
	srand(time(0));
	int reward[6][6];
	for(int i=0; i<6;i++){
		for(int j=0; j<6;j++){
			reward[i][j]=50;
			
		}
	}
	reward [0][4]=0;
	reward [1][3]=0;
	reward [1][5]=100;
	reward [2][3]=0;
	reward [3][1]=0;
	reward [3][2]=0;
	reward [3][4]=0;
	reward [4][0]=0;
	reward [4][3]=0;
	reward [4][5]=100;
	reward [5][1]=0;
	reward [5][4]=0;
	reward [5][5]=100;
	
	int q[6][6];
	for(int i=0; i<6;i++){
		for(int j=0; j<6;j++){
			q[i][j]=0;
			
		}
	}

	for(int i=0;i<100;i++){
		int random=0;
		random=rand()%6;
        process(random,reward);
        cout<<endl<<endl<<endl;	
	}
	
	
	return 0;
}


