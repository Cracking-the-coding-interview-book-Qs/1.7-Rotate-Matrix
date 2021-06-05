//ASSUMPTION:
//I have assumed it to be a square matrix

#include<iostream>

//isse baar baar std:: nhi likhna padta
using namespace std; 

//swap element by element
void RotateMat(int a[3][3],int r,int c)
{
	int n=r;//it can also be c as its a square matrix
	
	for(int layer=0;layer<n/2;layer++)
	{
		int first=layer;
		int last=n-1-layer;
		
		for(int i=first;i<last;i++)
		{
			int offset=i-first;
			
			//save the top row element
			int top=a[first][i];
			
			//left -> top
			a[first][i]=a[last-offset][first];
			
			//bottom -> left
			a[last-offset][first]=a[last][last-offset];
			
			//right -> bottom
			a[last][last-offset]=a[i][last];
			
			//saved top -> right
			a[i][last]=top;
		}
	}
	
}

int main()
{
	int a[3][3],r,c;

	cout<<"\nHow many rows do you want? => ";
	cin>>r;
	cout<<"\nHow many coulumns do you want? => ";
	cin>>c;

	cout<<"\nStart feeding matrix one by one \n";

	//feeding matrix
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"\nElement a"<<i+1<<j+1<<" => ";
			cin>>a[i][j];
		}
	}
	
	//calling our rotation function
	RotateMat(a,r,c);
	
	cout<<"\nAfter rotation  \n";

	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<" "<<a[i][j]<<" ";
		}
		cout<<"\n";
	}

return 0;
}
