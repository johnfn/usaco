/*
ID: johnfn2
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define REPS(i,m,n) for(int (i)=(m);(i)<(int)(n);++(i))
#define FE(i, x) for(typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define BITS(var,pos) ((var) & (1<<(pos)))
#define INF 99999999

int scan(){
    int t;
    scanf("%d", &t);
    return t;
}
int gcd(int a, int b)
{
    if (a==0) return b;
    if (b==0) return a;
  int c = a % b;
  while(c != 0)
  {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
int main(){
    freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
    long a, b, c, d, e, f, g, h, i, j, k, l;
    j = scan(); k = scan(); l = scan(); a = scan(); b = scan(); c = scan();
    d = scan(); e = scan(); f = scan(); g = scan(); h = scan(); i = scan();

    // :)
    long xtop = -(-d*h*l+d*i*k+e*g*l-e*i*j-f*g*k+f*h*j);
    long xbot =  (a*e*i-a*f*h-b*d*i+b*f*g+c*d*h-c*e*g);
    long ytop = -(-a*h*l+a*i*k+b*g*l-b*i*j-c*g*k+c*h*j);
    long ybot = (-a*e*i+a*f*h+b*d*i-b*f*g-c*d*h+c*e*g);
    long ztop = -(-a*e*l+a*f*k+b*d*l-b*f*j-c*d*k+c*e*j);
    long zbot = (a*e*i-a*f*h-b*d*i+b*f*g+c*d*h-c*e*g);

    long xgcd = gcd(xtop, xbot); xtop /= xgcd;  xbot /= xgcd; 
    long ygcd = gcd(ytop, ybot); ytop /= ygcd;  ybot /= ygcd; 
    long zgcd = gcd(ztop, zbot); ztop /= zgcd;  zbot /= zgcd; 

    long mx = max( max(xbot, ybot), zbot);
    xtop *= mx / xbot; ytop *= mx / ybot; ztop *= mx / zbot; //take a leap of faith...
    if (xtop < 0   || ytop < 0   || ztop < 0   || mx < 0){
        cout << "NONE" << endl;
        return 0;
    }
    cout << xtop << " " << ytop << " " << ztop << " " << mx << endl;
    return 0;
}
