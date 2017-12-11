import random



class ekfrash:
    name='ekfrash'
    def gen(self):
        if(random.choice([1,2])==1):
            return([oros()])
        else:
            return [ekfrash(),'+',oros()]

class oros:
    name='oros'
    def gen(self):
        if(random.choice([1,2])==1):
            return([paragontas()])
        else:
            return [oros(),'*',paragontas()]

class paragontas:
    name='paragontas'
    def gen(self):
        return random.choice([['a'],['b'],['c']])


e=[ekfrash()]
go=True

print('ekfrash =>\n')
while(go):
    for x in range(0,len(e)):
        if(type(e[x])!=str):
            for y in e.pop(x).gen():
                e.insert(x,y)
                x=x+1
            break
        else:
            if(x==len(e)-1):
                go=False
    for m in e:
        try:
            print(m.name, end=' ')
        except AttributeError:
            print(m, end=' ')
    print(' =>\n')

        

