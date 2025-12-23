#include <cstdio>

int globle_math(const char* expr){
    int result=0, current=0;
    char op='+';
    for(int i=0; expr[i]; i++){
        char c=expr[i];
        if(c>='0' && c<='9') current=current*10 + (c-'0');
        if((c<'0' || c>'9') && c!=' ' || expr[i+1]=='\0'){
            if(op=='+') result+=current;
            else if(op=='-') result-=current;
            else if(op=='*') result*=current;
            else if(op=='/') result/=current;
            op=c;
            current=0;
        }
    }
    return result;
}
