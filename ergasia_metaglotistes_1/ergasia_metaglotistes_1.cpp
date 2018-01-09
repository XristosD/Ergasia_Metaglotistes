#include <iostream>
#include <string>
#include <iostream>
using namespace std;



int main()
{
    bool read =true;
    string line = "";
    string lifo = "$";
    string drill  = "";
     cout << "write your code. At the end type 'end!' \n"  ;
    while(read)
        {

         cin >> line;
         if(line == "end!") { read = false; break;}
         for( int i = 0 ; i < line.length() ; i++)
            {
            if(line[i] == '(')
               {
                drill = drill + "("+lifo[lifo.length()-1]+", "+line[i]+")   ->   ("+lifo[lifo.length()-1]+line[i]+")        ";
                lifo.append( "(" );
                drill = drill + lifo+"\n";
               }
            else if(line[i] == ')')
            {
                if( lifo[lifo.length()-1] == '(' )
                   {
                    drill = drill + "("+lifo[lifo.length()-1]+", "+line[i]+")   ->   (e)        ";
                    lifo.erase(lifo.length()-1);
                    drill = drill + lifo+"\n";
                   }
                   else
                    {
                      drill = drill + "(" + lifo[lifo.length()-1]+ ", " + line[i] + ")   ->   (" + lifo[lifo.length()-1] + line[i] + ")     ";
                      lifo.append( ")" );
                      drill = drill + lifo+"\n";
                    }
            }
         else
         {
              drill = drill + "("+lifo[lifo.length()-1]+", "+line[i]+")   ->   ("+lifo[lifo.length()-1]+")           "+lifo+"\n";
         }
         }

    }


    if(lifo == "$")
    {
        cout << "YES";
    }
    else
    {

        cout << "NO";
    }
string choise = "";
    cout << "\nPrint the drill? (y/n)";
    cin >> choise;
    if( choise == "y" )
    {
        cout << "The DPA has two states:  (start state) ---EOF---> (end state) (start state) ---.---> (start state)\n";
         cout << drill<<"\n\n\n";
    }


    return 0;
}





