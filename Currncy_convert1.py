import requests as rq
amt=float(input("Enter Amount:"))
f_currency=input("Enter From Currency:").lower()
t_currency=input("Enter To Currency:").lower()
url="https://cdn.jsdelivr.net/npm/@fawazahmed0/currency-api@latest/v1/currencies/{}.json".format(f_currency)
response=rq.get(url)
data=response.json()
if t_currency in data[f_currency]:
    exchange_rate=data[f_currency][t_currency]
    convert=amt*exchange_rate
    print(amt," ",f_currency.upper(),"=",f"{convert:.2f}"," ",t_currency.upper(),"\n","Exchange Rate:",f"{exchange_rate:.2f}")
else:
    print("Invalid Currency")