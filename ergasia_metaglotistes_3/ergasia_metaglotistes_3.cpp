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
using namespace std;

string next = "";
string sentence = "";
int nextIndex =0;
void A();
void B();
void E();

void nexttoken()
{
    next = sentence.;
    cout<<next;
    nextIndex++;
}

void S()
{
    if(next == "[")
    {
        nexttoken();
        A();
        if(next == "]")
        {
            cout<<"true";
        }
        else
            cout<<"false1";
    }
    else
        cout<<"false2";
}

void A()
{
    B();
    E();
}

void B()
{
    if(next == "x" || next == "y")
    {
        nexttoken();
    }
    else
    {
        S();
    }
    return;
}

void E()
{
    if(next == ":" || next == "+")
    {
        nexttoken();
        A();
    }
    else
        return;
}

int main()
{
    do{
            cout<<"write your sentence: ";
            cin>>sentence;
            nexttoken();
            if(S() && next ==-1)
            {
                cout<<"TRUE";
            }
        }while(sentence=="stop");

    return 0;
}





