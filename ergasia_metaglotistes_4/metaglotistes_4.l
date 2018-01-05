%{

int i = 0;
%}
  
num             [0-9]
letter          [a-zA-Z]
ident           {letter}({letter}|{num})*
type            integer|boolean|floar|char
startOfDecl     var
separator       ,
endOfStatement  ;
colon           :
%%
{startOfDecl}              {printf("Startofdeclaration ");}
{separator}                {printf("separator ");}
{colon}                    {printf("colon ");}
integer|boolean|floar|char {printf( "type ");}
{endOfStatement}           { ++i;printf("endof%dstatement ",i);}
{ident}                    {printf( "intentifier ");}
[ \t\n]+                   {;}
.                          {printf( "Unrecognized character ");}
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
