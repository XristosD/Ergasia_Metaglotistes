/*
έστω τα σύνολα:            B1 = lookahead(B->x) = { x }
                                    B2 = lookahead(B->y) = { y }
                                    B3 = lookahead(B->S) = { ] }
                                    E1 = lookahead(L->:A) = { : }
                                    E2 = lookahead(L->+A) = { + }
                                    E3 = lookahead(L->ε) = { ] }

                                    οπότε επειδή B1 ∩  B2 ∩  B3 = ∅
                                    και Ε1 ∩ Ε2 ∩ Ε3 = ∅
                                    η γραμματική G είναι LL(1)
*/

#include <iostream>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

char next ;
string sentence = "";
int nextIndex =0;
bool A();
bool B();
bool E();

void nexttoken()
{
    next = sentence[nextIndex];
    nextIndex++;
}

bool S()
{
    if(next == '[')
    {
        nexttoken();
        if (A())
        {
            if(next == ']')
            {
                nexttoken();
                return 1;
            }
            else
                return 0;
        }
        else return  0;

    }
    else
        return 0;
}

bool A()
{
    if(B())
    {
        if(E())
        {
            return 1;
        }
        else return 0;
    }
    else return 0;
}

bool B()
{
    if(next == 'x' || next == 'y')
    {
        nexttoken();
        return true;
    }
    else if (S())
    {
       return 1 ;
    }
    else return 0;
}

bool E()
{
    if(next == ':' || next == '+')
    {
        nexttoken();
        return A();
    }
    else
        return 1;
}

int main()
{
    do{
            nextIndex = 0;
            cout<<"\nwrite your sentence: ";
            cin>>sentence;
            nexttoken();
            if(S() && next == NULL )
            {
                cout<<"TRUE";
            }
            else cout<<"FALSE";
        }while(sentence!="stop");

    return 0;
}





