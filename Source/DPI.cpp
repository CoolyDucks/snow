#include <cstdio>
#include <cstdlib>
#include <cstring>

void say(const char* text);
int globle_math(const char* expr);
void globle_gmt(const char* version);
void globle_time(const char* tz);
void run_snow_file(const char* path){
    FILE* file=fopen(path,"r");
    if(!file){ printf("File not found: %s\n",path); return; }
    char line[512];
    while(fgets(line,sizeof(line),file)){
        line[strcspn(line,"\n")]=0;
        if(strncmp(line,"say(",4)==0){
            char* start=strchr(line,'"');
            char* end=strrchr(line,'"');
            if(start && end && end>start){
                char text[512];
                strncpy(text,start+1,end-start-1);
                text[end-start-1]='\0';
                say(text);
            }
        } else if(strncmp(line,"math {",6)==0){
            while(fgets(line,sizeof(line),file) && strncmp(line,"end",3)!=0){
                char* expr=strstr(line,"globle.math(");
                if(expr){
                    char* start=strchr(expr,'(');
                    char* end=strrchr(expr,')');
                    if(start && end && end>start){
                        char text[512];
                        strncpy(text,start+1,end-start-1);
                        text[end-start-1]='\0';
                        int result=globle_math(text);
                        printf("%d\n",result);
                    }
                }
            }
        } else if(strncmp(line,"time {",6)==0){
            while(fgets(line,sizeof(line),file) && strncmp(line,"end",3)!=0){
                char* expr;
                if((expr=strstr(line,"globle.gmt("))){
                    char* start=strchr(expr,'(');
                    char* end=strrchr(expr,')');
                    if(start && end && end>start){
                        char text[128];
                        strncpy(text,start+1,end-start-1);
                        text[end-start-1]='\0';
                        globle_gmt(text);
                    }
                }
                if((expr=strstr(line,"globle.time("))){
                    char* start=strchr(expr,'(');
                    char* end=strrchr(expr,')');
                    if(start && end && end>start){
                        char text[128];
                        strncpy(text,start+1,end-start-1);
                        text[end-start-1]='\0';
                        globle_time(text);
                    }
                }
            }
        }
    }
    fclose(file);
}

void start_DPI(){
    char input[512];
    printf("Welcome To Snow ❄️ Language Programming 1.0.0\nSay Y for continue\n>>> ");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]=0;
    if(input[0]!='y' && input[0]!='Y'){printf("Exiting Snow...\n"); return;}
    printf("What would you like to program using the Snow language? (Software tools / Mathematics / Games / All?)\n>>> ");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]=0;
    printf("We Building [Red Color] The IDE 🌛...\n\n");
    while(1){
        printf("The Snow IDE\nsay \"help\" for learning\nsay \"snow path/to/.snow\" for running\n🌛🪷\n>>> ");
        if(!fgets(input,sizeof(input),stdin)) break;
        input[strcspn(input,"\n")]=0;
        if(strncmp(input,"help",4)==0){
            printf("SNOW Help:\n- say(\"Hello\")\n- math { globle.math(...) } end\n- time { globle.gmt(...) } end\n- snow <file>\n- exit\n\n");
        } else if(strncmp(input,"snow ",5)==0){
            run_snow_file(input+5);
        } else if(strncmp(input,"say(",4)==0){
            char* start=strchr(input,'"');
            char* end=strrchr(input,'"');
            if(start && end && end>start){
                char text[512];
                strncpy(text,start+1,end-start-1);
                text[end-start-1]='\0';
                say(text);
            }
        } else if(strcmp(input,"exit")==0){
            printf("Exiting Snow IDE...\n");
            break;
        } else printf("Unknown command: %s\n",input);
    }
}
