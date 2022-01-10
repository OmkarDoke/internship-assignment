def ToWord(N):
    Result=''
    Unit=['','One','Two','Three','Four','Five','Six','Seven','Eight','Nine','Ten'
    ,'Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
    Decimal=["","",'Twenty','Thirty','Fourty','Fifty','Sixty','Seventy','Eighty','Ninety']
    if N>99:
        Result= Unit[N//100]+" Hundred"
    if N%100!=0:
        N%=100
        if N>19:
            Result=Result+" "+Decimal[N//10]+" "+Unit[N%10]
        else:
            Result=Result+" "+Unit[N%20]#+" "+Unit[N%10]    
    return Result


num=int(input("Enter number:"))
Base=['','Thousand','Million','Billion','Trillion','Quadrillion','Quintillion','Sextillion','Septillion',
'Octillion','Nonillion','Decillion','Undecillion','Duodecillion','Tredecillion','Quatttuor-decillion',
'Quindecillion','Sexdecillion','Septen-decillion','Octodecillion','Novemdecillion','Vigintillion']
ind=0
Res=''
# print(ToWord(num))
while  num:
    Res=ToWord(num%1000)+" "+Base[ind]+" "+Res
    num//=1000
    ind+=1

print(Res)    