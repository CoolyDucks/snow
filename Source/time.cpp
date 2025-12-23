#include <cstdio>
#include <ctime>

void globle_gmt(const char* version){ printf("GMT version %s initialized\n",version); }

void globle_time(const char* tz){
    time_t t=time(nullptr);
    struct tm* tm_info=localtime(&t);
    char buffer[26];
    strftime(buffer,26,"%Y-%m-%d %H:%M:%S",tm_info);
    printf("[%s] Current time zone: %s\n",buffer,tz);
}
