#include<iostream>
#include <utility>
#include<cmath>
#include<list>
#include<map>
using namespace std;

map<int,list<pair<int,int>> > mymap;
 map<int,list<pair<int,int> > > :: iterator itr;


void putpixelone (int m,int n ,int p)
{
  int flag  = 0;
  if(mymap.find(m) != mymap.end())
  {
    list<pair<int,int> > l = mymap.find(m)->second;
    list<pair<int,int> > :: iterator it1;
    for(it1 = l.begin();it1 != l.end();++it1)
    {
      
      if ((get<0>(*it1) == n)&&(get<1>(*it1) == p))
      {
        flag=1;
        break;
      }
      else
      continue;
  
        
        
      }
      if(flag !=1)
      mymap[m].push_back(make_pair(n,p));
      
    }
    
  else
	mymap[m].push_back(make_pair(n,p));
}


void putpixelall (int a , int b , int c, int x,int y ,int z)
{   
    
	putpixelone(a+x,b+y,c+z);
	putpixelone(b+x,a+y,c+z);
	putpixelone(c+x,b+y,a+z);
	putpixelone(a+x,c+y,b+z);
	putpixelone(c+x,a+y,b+z);
	putpixelone(b+x,c+y,a+z);
	putpixelone(-a+x,-b+y,c+z);
	putpixelone(-b+x,-a+y,c+z);
	putpixelone(c+x,-b+y,-a+z);
	putpixelone(-a+x,c+y,-b+z);
	putpixelone(c+x,-a+y,-b+z);
	putpixelone(-b+x,c+y,-a+z);
	putpixelone(a+x,-b+y,-c+z);
	putpixelone(-b+x,a+y,-c+z);
	putpixelone(-c+x,-b+y,a+z);
	putpixelone(a+x,-c+y,-b+z);
	putpixelone(-c+x,a+y,-b+z);
	putpixelone(-b+x,-c+y,a+z);
	putpixelone(-a+x,b+y,-c+z);
	putpixelone(b+x,-a+y,-c+z);
	putpixelone(-c+x,b+y,-a+z);
	putpixelone(-a+x,-c+y,b+z);
	putpixelone(-c+x,-a+y,b+z);
	putpixelone(b+x,-c+y,-a+z);
	putpixelone(-a+x,b+y,c+z);
	putpixelone(b+x,-a+y,c+z);
	putpixelone(c+x,b+y,-a+z);
	putpixelone(-a+x,c+y,b+z);
	putpixelone(c+x,-a+y,b+z);
	putpixelone(b+x,c+y,-a+z);
	putpixelone(a+x,-b+y,c+z);
	putpixelone(-b+x,a+y,c+z);
	putpixelone(c+x,-b+y,a+z);
	putpixelone(a+x,c+y,-b+z);
	putpixelone(c+x,a+y,-b+z);
	putpixelone(-b+x,c+y,a+z);
	putpixelone(a+x,b+y,-c+z);
	putpixelone(b+x,a+y,-c+z);
	putpixelone(-c+x,b+y,a+z);
	putpixelone(a+x,-c+y,b+z);
	putpixelone(-c+x,a+y,b+z);
	putpixelone(b+x,-c+y,a+z);
  putpixelone(-a+x,-b+y,-c+z);
	putpixelone(-b+x,-a+y,-c+z);
	putpixelone(-c+x,-b+y,-a+z);
	putpixelone(-a+x,-c+y,-b+z);
	putpixelone(-c+x,-a+y,-b+z);
	putpixelone(-b+x,-c+y,-a+z);
}

void drawsphere (int x,int y ,int z,int r)
{
	int i=0,j=0;
	int k0 = r;
	int k = k0;
	int s0 = 0;
	int s = s0;
	int v0 = r-1;
	int v = v0;
	int l0 = 2*v0;
	int l = l0;
	
	while (i<=k)
	{
		while (j<=k)
		{
			if (s > v)
			{
				k = k-1;
				v = v+l;
				l = l-2;
				
			}
			if((j<=k) && ((s != v) || (j != k)))
			{
				putpixelall (i,j,k,x,y,z);
			}
			s = s+2*j+1;
			j = j+1;
		}
		s0 = s0 + 4*i +2;
		i = i+1;
		
		while ((s0 > v0)&&(i <= k0))
		{
			k0 = k0-1;
			v0 = v0+l0;
			l0 = l0-2;
		}
		j = i;
		k=k0;
		v = v0;
		l = l0;
		s = s0;
	}
	
}

void showallpoints (map<int,list<pair<int,int> > > &mymap)
{
  int count = 0;
 
	for(itr = mymap.begin(); itr != mymap.end();++itr)
	{
	  list<pair<int,int> > l = itr->second;
	  list<pair<int,int> > :: iterator it;
	  for (it = l.begin(); it != l.end() ; ++it)
	  {
	    cout << itr->first << "," << get<0>(*it) <<"," << get<1>(*it) << endl;
	    count += 1;
	  }

}
cout << endl;
cout << count << endl;
}

void zeroneighbour (int i,int j,int k,map<int,list<pair<int,int> > > &mymap)
{
   if (mymap.find(i+1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i+1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j+1  && get<1>(*it1) == k+1)||(get<0>(*it1) == j-1  && get<1>(*it1) == k+1)||(get<0>(*it1) == j-1  && get<1>(*it1) == k-1) || (get<0>(*it1) == j+1  && get<1>(*it1) == k-1))
      cout <<i+1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
   if (mymap.find(i-1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i-1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j-1  && get<1>(*it1) == k-1)||(get<0>(*it1) == j+1  && get<1>(*it1) == k+1)||(get<0>(*it1) == j-1  && get<1>(*it1) == k+1) || (get<0>(*it1) == j+1  && get<1>(*it1) == k-1))
      cout <<i-1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
}

void oneneighbour (int i,int j,int k,map<int,list<pair<int,int> > > &mymap)
{
  if (mymap.find(i+1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i+1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j+1  && get<1>(*it1) == k)||(get<0>(*it1) == j  && get<1>(*it1) == k+1)||(get<0>(*it1) == j && get<1>(*it1) == k-1) || (get<0>(*it1) == j-1  && get<1>(*it1) == k))
      cout <<i+1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   if (mymap.find(i-1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i-1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j-1  && get<1>(*it1) == k)||(get<0>(*it1) == j+1  && get<1>(*it1) == k)||(get<0>(*it1) == j && get<1>(*it1) == k+1) || (get<0>(*it1) == j  && get<1>(*it1) == k-1))
      cout <<i-1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
   if (mymap.find(i) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j-1  && get<1>(*it1) == k+1)||(get<0>(*it1) == j+1  && get<1>(*it1) == k-1)||(get<0>(*it1) == j+1 && get<1>(*it1) == k+1) || (get<0>(*it1) == j-1  && get<1>(*it1) == k-1))
      cout <<i-1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
}
void twoneighbour (int i,int j,int k,map<int,list<pair<int,int> > > &mymap)
{
   if (mymap.find(i+1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i+1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if (get<0>(*it1) == j && get<1>(*it1) == k)
      cout <<i+1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
    if (mymap.find(i-1) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i-1)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if (get<0>(*it1) == j && get<1>(*it1) == k)
      cout <<i+1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
   
    if (mymap.find(i) != mymap.end())
   {
     
     list<pair<int,int> > l = mymap.find(i)->second;
     list<pair<int,int> > :: iterator it1;
    for (it1 = l.begin(); it1 != l.end();++it1)
    {
      if ((get<0>(*it1) == j-1  && get<1>(*it1) == k)||(get<0>(*it1) == j  && get<1>(*it1) == k-1)||(get<0>(*it1) == j+1 && get<1>(*it1) == k) || (get<0>(*it1) == j  && get<1>(*it1) == k+1))
      cout <<i-1 <<"," << get<0>(*it1) << "," <<get<1>(*it1) << endl;
      
      
    }
   }
}
int main()
{
	int cx,cy,cz;
	cin >> cx >> cy >> cz;
	int r ;
	cin >> r;
	drawsphere(cx,cy,cz,r);
	showallpoints(mymap);
	 cout << "Enter The Number" << endl;
  int j,k,l;
  cin >> j >> k >> l;
  int  y;
  cout << "Enter the adjacency : (0 to 2)"<< endl;
  cin >> y;
  if ( y == 0)
  zeroneighbour (j,k,l,mymap);
  else if (y ==1)
  oneneighbour(j,k,l,mymap);
  else if (y==2)
  twoneighbour(j,k,l,mymap);
  else
 cout << " adjacency should be in range of (0,2)" << endl;
  
}
