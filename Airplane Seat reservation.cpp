#include<iostream>
using namespace std;
void reservation(int arr[13][6],char col,int row,char check[13][6])
{

	if(col=='A')
	{
		arr[row][0] = 'X';
		check[row][0] = 'X';
	} 
	else if(col =='B')
	{
		arr[row][1] = 'X';
		check[row][1] = 'X';
	}	
	else if(col=='C')
	{
		arr[row][2] = 'X';
		check[row][2] = 'X';
	}
	else if(col=='D')
	{
		arr[row][3] = 'X';
		check[row][3] = 'X';
	}
	else if(col=='E')			
	{
		arr[row][4] = 'X';
		check[row][4] = 'X';
	}			
	else if(col=='F')
	{
		arr[row][5] = 'X';
		check[row][5] = 'X';
	}
}
void instructions()
{
	cout<<endl<<"Row 1 and 2 are first class "<<endl<<"Row 3 to 7 are business class "<<endl
    <<"Row 8 to 13 are economy class"<<endl;
	cout<<"Enter your desired row :  ";
	cout<<"Also Enter the seat you want( A , B , C , D , E , F ):  ";
}
void fair_calculation(int f , int b , int e)
{
	int fir,bus,eco,fair;
	fir=750*f;    bus=1500*b;   eco=500*e;
	cout<<"Fair calculation is:"<<endl<<"For first class:  750 X "<<f<<" = "<<fir<<endl;
	cout<<"For business class:  1500 X "<<b<<" = "<<bus<<endl;
	cout<<"For economy class:  500 X "<<e<<" = "<<eco<<endl;
	fair=fir+bus+eco;
	cout<<"Total fair is:  "<<fair; 
}

int main()
{
	int row=0,test;
	char col,ch,check[13][6];
	int arr[13][6],count[3];
	cout<<"     \tA\tB\tC\tD\tE\tF"<<endl;
	for(int o=0;o<3;o++)
	count[o]=0;
	for(int i=0;i<13;i++)
	{
		cout<<"Row: "<<(i+1)<<"\t";
		for(int j=0;j<6;j++)
		{
			arr[i][j]= '*' ;
			check[i][j]='*';
			cout<<static_cast <char>(arr[i][j])<<"       ";
		}
		cout<<endl;
	}
	instructions();
	while(test!=-1)
	{
		cin>>col>>row;
		switch (col)
		{
			case 'A':
				ch=0;
				break;
			case 'B':
				ch=1;
				break;
			case 'C':
				ch=2;
				break;
			case 'D':
				ch=3;
				break;
			case 'E':
				ch=4;
				break;
			case 'F':
			    ch=5;
			    break;
		}
		if(check[row][ch]=='X')
		{
			cout<<"enter valid seat ";
			continue;
		}
		if(row==1||row==2)
		{
			row-=1;
			count[0]++;
			reservation(arr,col,row,check);	
		}
		if(row>=3 && row<=7)
		{
			row-=1;
			count[1]++;
			reservation(arr,col,row,check);
		}
		if(row>=8 && row<=13)
		{
			row-=1;
			count[2]++;
			reservation(arr,col,row,check);
		}
		cout<<"Press 1 for continue "<<"Press -1 to quit:  ";
		cin>>test;
	}
	cout<<"     \tA\tB\tC\tD\tE\tF"<<endl;
	for(int i=0;i<13;i++)
	{
		cout<<"Row: "<<(i+1)<<"\t";
		for(int j=0;j<6;j++)
		{
			arr[i][j] ;
			cout<<static_cast <char>(arr[i][j])<<"       ";
		}
		cout<<endl;
	}
	fair_calculation(count[0],count[1],count[2]);
}
