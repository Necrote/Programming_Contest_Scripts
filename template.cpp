#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define s(n)                        scanf("%d",&n)
#define sc(n)                       scanf("%c",&n)
#define sl(n)                       scanf("%ld",&n)
#define sll(n)                      scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define ssp(n)                      scanf("%[^\n]%*c",n)
#define prt(x)                      printf("%d\n",x);
#define plt(x)                      printf("%lld\n",x);

#define INF                         0x3f3f3f3f
#define EPS                         1e-6

#define bitcount                    __builtin_popcount
#define bitcountl                   __builtin_popcountl
#define bitcountll                  __builtin_popcountll
#define gcd                         __gcd

#define forall(i,a,b)               for(int i=a;i<b;i++)
#define forrall(i,a,b)              for(int i=a-1; i>=b; --i)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define all(a)                      a.begin(), a.end()
#define rall(a)                     a.rbegin(),a.rend()

#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define mp                          make_pair

#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define strjoin( x, y )              x ## y
#define MOD                          1000000007
#define ADD(X,Y)                     ((X) = ((X) + (Y)%MOD) % MOD)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef stringstream ss;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef long long ll;
typedef long double ld;

//***********************************************************//
//******************** Utility Functions ********************//
//***********************************************************//

void initMOD(ll &a)
{
    if(a > MOD)
        a %= MOD;
}

ll addMOD(ll a, ll b)
{
    ll c = a + b;
    return (c < MOD ? c : c%MOD );
}

ll subtractMOD(ll a, ll b)
{
    ll c = a - b;
    return (c < MOD ? c : c%MOD );
}

ll multiplyMOD(ll a, ll b)
{
    initMOD(a);
    initMOD(b);

    ll c = a * b;
    return (c < MOD ? c : c%MOD );
}

inline long long int frll()
{
    register long long int c=getchar();
    long long int x=0LL, neg=0LL;       //Bool neg is better?
    for(; ((c<48LL || c>57LL) && c != '-' && c!=EOF); c = getchar());
    if(c==EOF)
        return EOF;
    if(c=='-')
    {
        neg = 1LL;
        c = getchar();
    }
    for(; c>47LL && c<58LL ; c = getchar()) 
        x = (x<<1LL) + (x<<3LL) + c - 48LL;
    if(neg)
        x = -x;
    
    return x;
}

inline int fri()
{
    register int c=getchar();
    int x=0, neg=0;                     //Bool neg is better?
    for(; ((c<48 || c>57) && c != '-' && c!=EOF); c = getchar());
    if(c==EOF)
        return EOF;
    if(c=='-')
    {
      neg = 1;
      c = getchar();
    }
    for(; c>47 && c<58 ; c = getchar()) 
      x = (x<<1) + (x<<3) + c - 48;

    if(neg)
        x = -x;
    
    return x;
}

#ifdef DEBUG
      #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
      #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
      #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
      #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
      #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
      #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
#else
      #define trace1(x)           
      #define trace2(x,y)         
      #define trace3(x,y,z)       
      #define trace4(a,b,c,d)     
      #define trace5(a,b,c,d,e)   
      #define trace6(a,b,c,d,e,f) 
#endif

void jibunNoSoln(int t)
{

}

int main()
{
    #ifdef SMALL
        freopen("A-small-attempt0.in","rt",stdin);
        freopen("A-small.out","wt",stdout);
    #endif
    #ifdef LARGE
        freopen("A-large.in","rt",stdin);
        freopen("A-large.out","wt",stdout);
    #endif

    int t;
    s(t);
    forall(p,0,t)
    {
        printf("Case #%d: ",p+1);
        jibunNoSoln(p+1);
    }

    return 0;
}