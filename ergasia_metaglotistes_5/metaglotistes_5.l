%{
#include <string.h>


char lett[] = {'A','B','C','D','E'};
int checkDouble(char *o)
{
int letIndex[] = {0,0,0,0,0};
int i ;
for ( i = 0 ; i<strlen(o) ; i++)
{
if(o[i]=='A')
{
letIndex[0]++;
}
if(o[i]=='B')
{
letIndex[1]++;
}
if(o[i]=='C')
{
letIndex[2]++;
}
if(o[i]=='D')
{
letIndex[3]++;
}
if(o[i]=='E')
{
letIndex[4]++;
}
}
for (i = 0 ; i < 5 ; ++i)
{
if(letIndex[i]>1)
{
printf("%s: To gramma %c iparxei %d fores\n",o,lett[i],letIndex[i]);
return 0;
}
else
{
return 1;
}
}
}
%}
  
rima             Dinetai
geomOntot        trigono|tetragono|gonia
%%
{rima}              {printf("%s: Einai rima.\n",yytext);}
{geomOntot}                {printf("%s: Einai geometriki ontotita.\n",yytext);}
[A-E]{1,4}                  {char *j=yytext;if(checkDouble(j) == 1){printf("%s: Einai onoma geometrikis ontotitas.\n",j);}}
.                            {;}
%%
main( argc, argv )
int argc;
char **argv;
{
++argv, --argc; /* skip over program name */
if ( argc > 0 )
yyin = fopen( argv[0], "r" );
else
yyin = stdin;
yylex();
}
