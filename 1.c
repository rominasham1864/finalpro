#include <stdio.h>
#include <string.h>
//rt=x rs=y rd=z
#define INT_MAX 2147483647
#define INT_MIN -2147483648
int s[32], Imm;
int situation[8];

int compare(char order){
    char orders[18][10]={"ADD", "SUB", "AND", "OR", "XOR", "ADDI", "SUBI", "ANDI", "XORI","ORI", "MOV", "SWP", "DUMP_REGS", "DUMP_REGS_F", "INPUT", "OUTPUT", "JUMP", "EXIT"};
    for(int i=0; i<18; i++){
       if(strcmp(touper(order,orders[i])==0)){ return i; break; }
    }
    return -1;}

void pzs(int a){
    if(a%2==0){ situation[0]=0; }
    else{ situation[0]=1; }
    if(a==0){ situation[1]=1; }
    else{ situation[1]=0; };
    if(a<0){ situation[2]=1; }
    else{ situation[2]=0; }}

void ovreflow(int i,int y,int x){
    if(i==1)
    {
        if(s[y] + s[x] < INT_MIN || s[y] + s[x] > INT_MAX)
        situation[5]=1;
        else
            situation[5]=0;
    }
    else if(i==2)
    {
        if(s[y] - s[x] < INT_MIN || s[y] - s[x] > INT_MAX)
        situation[5]=1;
        else
            situation[5]=0;
    }}

    void overflowIMM(int i,int Imm,int y){
    else if(i==5)
    {
        if(s[y] + Imm < INT_MAX && s[y] + Imm < INT_MAX)
        situation[5]=1;
        else
            situation[5]=0;
    }
    else if(i==6)
    {
        if(s[y] + Imm < INT_MAX && s[y] + Imm < INT_MAX)
        situation[5]=1;
        else
            situation[5]=0;
    }}


void ADD(int x, int y, int z){
    s[z]= s[y] + s[x];
    void pzs();
}
void SUB(int x, int y, int z){
    s[z]= s[y] - s[x];
    void pzs();
}
void AND(int x, int y, int z){
    s[z]= s[y] & s[x];
    void pzs();
}
void OR(int x, int y, int z){
    s[z]= s[y] | s[x];
    void pzs();
}
void XOR(int x, int y, int z){
    s[z]= s[y] ^ s[x];
    void pzs();
}
void ADDI(int z, int y, int Imm){
    s[z]= s[y] + Imm;
    void pzs();
}
void SUBI(int z, int y, int Imm){
    s[z]= s[y] - Imm;
    void pzs();
}
void ANDI(int Imm, int y, int z){
    s[z]= s[y] & Imm;
    void pzs();
}
void ORI(int Imm, int y, int z){
    s[z]= s[y] | Imm;
    void pzs();
}
void XORI(int Imm, int y, int z){
    s[z]= s[y] ^ Imm;
    void pzs();
}
void MOV(int y,char[] x)
{
    if(char[0]=S){ y=char[1];  s[x]=s[sr]; }
    else{ s[x]=(int)(char[0]); }
}
void SWP(int x, int y){
int m;
m=s[x];
s[x]=s[y];
s[y]=m;
}
void DUMP_REGS(){
    for (int i = 0; i < 32; i++){
        printf("%d ", s[i]);
    }fprintf("\n");
    for (int i = 0; i < 8; i++){
        printf("%d ", situation[i]);
    }
}
void DUMP_REGS_F(){
    FILE* fr;
    fr= fopen("regs.text", "r");
    for (int i = 0; i < 32; i++){
        fprintf("%d ", s[i]);
    }fprintf("\n");
    for (int i = 0; i < 8; i++){
        fprintf("%d ", situation[i]);
    }
}
void INPUT()
{
    scanf("%d", &s[0]);
}
void OUTPUT()
{
    printf("%d", s[0]);
}

//jump

int main(){
char[20] order;
int a, x, y, z;
FILE* f;
f= fopen("in.txt", "w");
fscanf(f ,"%s", order);
a=compare(order);
switch (a){
case 0: sscanf( ," S%d, S%d, S%d", &x, &y, &z); ADD(x , y, z); break;
case 1: scanf(" S%d, S%d, S%d", &x, &y, &z); SUB(x , y, z); break;
case 2: scanf(" S%d, S%d, S%d", &x, &y, &z); AND(x , y, z); break;
case 3: scanf(" S%d, S%d, S%d", &x, &y, &z); OR(x , y, z); break;
case 4: scanf(" S%d, S%d, S%d", &x, &y, &z); XOR(x , y, z); break;
case 5: scanf(" S%d, %d", &y, &Imm);ADDI(z , y, Imm); break;
case 6: scanf(" S%d, %d", &y, &Imm);SUBI(z , y, Imm); break;
case 7: scanf(" S%d, %d", &y, &Imm);ANDI(Imm , y, z); break;
case 8: scanf(" S%d, %d", &y, &Imm);XORI(Imm , y, z); break;
case 9: scanf(" S%d, %d", &y, &Imm);ORI(Imm , y, z); break;
case 10: scanf(" S%d, %d",&y, &x);MOV(y , x); break;
case 11: scanf("%d %d", &Imm, &y);SWP(y , x); break;
case 12: DUMP_REGS(); break;
case 13: DUMP_REGS_F(); break;
case 14: INPUT(); break;
case 15: OUTPUT(); break;
case 16: scanf("%d", &Imm); JUMP(Imm); break;
case 17: return 0;
}
}
