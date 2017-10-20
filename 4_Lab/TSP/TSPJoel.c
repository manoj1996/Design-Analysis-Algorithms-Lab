#include<stdio.h>
#include <stdlib.h>
#include<string.h>
struct Element
{
	int value;
	char direction;
};
int getNextMobileElement();
void changedirection(int);
void calculatecost();
struct Element records[12];
int city[12][12];
int size,mincost=0;
int main()
{
		int noofcities,i,j,m;
		scanf("%d",&noofcities);
		size=noofcities;
		for(i=1;i<=noofcities;i++)
		{
			char line[1024];
			scanf(" %[^\n]", line);	
			sscanf(line,"%d %d %d %d %d %d %d %d %d %d",&city[i][1],&city[i][2],&city[i][3],&city[i][4],&city[i][5],&city[i][6],&city[i][7],&city[i][8],&city[i][9],&city[i][10]);
		}
		for(i=1;i<=size;i++)
		{
			records[i].value=i;
			records[i].direction='L';
		}
		int pos=getNextMobileElement();int count=1;
		for(i=1;i<size;i++)
			mincost+=city[records[i].value][records[i+1].value];		
		mincost+=city[records[i].value][records[1].value];
		while(pos!=-1)
		{
			if(records[pos].direction=='L')
			m=pos-1;
			else if(records[pos].direction=='R')
			m=pos+1;
			changedirection(pos);
			struct Element temp=records[pos];		
			records[pos]=records[m];
			records[m]=temp;
			calculatecost(); //To calculate the minimum cost
			pos=getNextMobileElement();
		}
		printf("The minimum cost is : %d\n",mincost);		
	
	return 1;
}

void changedirection(int p)
{
	int i;
	for( i=1;i<=size;i++)
	{
		if(records[i].value>records[p].value)
			records[i].direction=records[i].direction=='L' ? 'R' : 'L';
	}	
}
int getNextMobileElement()
{
	int m=-1;
	int i;
	for(i=1;i<=size;i++)
	{	
		if((records[i].direction=='L') && i>1 && (records[i].value>records[i-1].value))
		{	
			if(m==-1)
				m=i;
			else if(records[i].value>records[m].value)
				m=i;
		}		
		else if((records[i].direction=='R')&&i<size && (records[i].value>records[i+1].value))
		{	
			if(m==-1)
				m=i;
			else if(records[i].value>records[m].value)
				m=i;
		}
	}
	return m;
}
void calculatecost()
{
	int tempcost=0,i;
	for(i=1;i<size;i++)
	{
		//printf("%d + ",city[records[i].value][records[i+1].value]);
		tempcost+=city[records[i].value][records[i+1].value];	
	}
	//printf("%d = ",city[records[i].value][records[1].value]);
	tempcost+=city[records[i].value][records[1].value];
	//printf("tempcost %d",tempcost);
	if(tempcost<mincost)
		mincost=tempcost;
}





