#include<iostream>
//鬼知道快不快的快读
//#define OPTIMIZE //取消注释可以优化速度，但是读完后需要按ctrl+z 
using namespace std;
struct INPORT
{
    #ifdef OPTIMIZE
		inline char qget() 
		{
	        static const int inlen = 1 << 18 | 1;
	        static char buf[inlen], *s, *t;
	        return (s == t) && (t = (s = buf) + fread(buf, 1, inlen, stdin)), s == t ? -1 : *s++;
	    }
    	#define read() qget()
    #else
    	#define read() getchar()
    #endif
    inline INPORT& operator>>(int &x) {
        static char c11, boo;
        for (c11 = read(), boo = 0; !isdigit(c11); c11 = read()) {
            if (c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for (x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
    inline INPORT& operator>>(short &x) {
        static char c11, boo;
        for (c11 = read(), boo = 0; !isdigit(c11); c11 = read()) {
            if (c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for (x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
    inline INPORT& operator>>(long long &x) {
        static char c11, boo;
        for (c11 = read(), boo = 0; !isdigit(c11); c11 = read()) {
            if (c11 == -1) return *this;
            boo |= c11 == '-';
        }
        for (x = 0; isdigit(c11); c11 = read()) x = x * 10 + (c11 ^ '0');
        boo && (x = -x);
        return *this;
    }
    inline INPORT& operator>>(string &x)
	{
    	x.clear();
    	char ch=read();
    	while(ch!='\n'&&ch!=' ')
    	{
    		x+=ch;
    		ch=read();
		}
	}
} fin;

int main()
{
    int a,b,c,d;
    fin>>a>>b>>c>>d;
    return 0;
}