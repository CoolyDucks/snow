#include <cstdio>
#include <cstdlib>
#include <cstring>

class Object {
public:
    char name[64];
    int id;
    Object(const char* n,int i){
        int j;
        for(j=0;j<63 && n[j];j++) name[j]=n[j];
        name[j]='\0';
        id=i;
    }
    void show(){ printf("%s #%d\n",name,id); }
};

void say(const char* text){ printf("%s\n",text); }
