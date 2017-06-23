// BRUTE FORCE METHOD FOR DRAWING FILLED CIRCLE.

#include<iostream>
#include <map>
#include <list>
using namespace std;



map<int,list<int> > mymap;
map<int,list<int> >::iterator it;
void showallpoints(map<int,list<int> >&mymap)
{
	for( it=mymap.begin();it!=mymap.end();it++)
	{
		list<int>temp=it->second;
		for(list<int>::iterator p=temp.begin();p!=temp.end();p++)
		{
			cout<<"("<<it->first<<","<<*p<<")"<<endl;
			
		}
	}
}
void putpixel (int m,int n,map<int,list<int> >&mymap)
 {
 	map<int,list<int> >::iterator it;
 	if(mymap.find(m)!=mymap.end())
 	{
	 
 	it=mymap.find(m);
 	list<int> temp=it->second;
 	list<int>::iterator p;
 	for(p=temp.begin();p!=temp.end();p++)
 	{
 		if( *p == n)
 		return;
 	
	 }
	 mymap[m].push_back(n);
}
else
mymap[m].push_back(n);
 	return;
 	
 }
 
 void putpixelall (int a,int b ,int cx, int cy)
 {
 	putpixel(a+cx,b+cy,mymap);
 	putpixel(-a+cx,b+cy,mymap);
 	putpixel(-a+cx,-b+cy,mymap);
 	putpixel(a+cx,-b+cy,mymap);
 }
void DrawFilledCircle (int x1, int y1, float radius)
{
	int integerRadius = radius;
	
	
	for(int i=0 ; i<integerRadius;i++)
	{
		for(int j=0;j<integerRadius;j++)
		{
			if ((i*i)+(j*j)-(radius*radius)<0)
			putpixelall(i,j,x1,y1);
		}
	}
  }  
  
  int main()
  {
  	int centerX,centerY;
  	cin >> centerX >> centerY;
  	float Radius;
  	cin >> Radius;
  	
  	DrawFilledCircle(centerX,centerY,Radius);
  	showallpoints(mymap);
  }
