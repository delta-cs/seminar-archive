# Find Median (Najdi Median)

## Co je to median?
Medián je prostřední číslo ve skupině čísel, kdy má polovina čísel hodnotu vyšší než medián a polovina čísel hodnotu nižší než medián. Například medián čísel **2, 3, 3, 5, 7 a 10** je **4**.
\
\
Zjednodušeně, pokud vezmeme řadu čísel  *(př: 1,5,3)*
\
Musíme čísla seřadit *(z příkladu by vzniklo 1,3,5 nebo 5,3,1)*
\
Poté v seřazené řadě najdeme číslo uprostřed *(median příkladu je 3)*

## Tvar vstupu
- Dostanete na standartní vstup celé kladné číslo *K* - počet čísel ze kterých musíte najít median.
- Následně dostanete na vstup *K* čísel (celá čísla, můžou být i záporná)
- po každém čísle následuje nový řádek (i po prvním a posledním)
- pokud je *K* sudé číslo, tedy uprostřed jsou čísla 2, **bereme jako median průměr těchto dvou čísel** *(př: `2,3,5,6` uprostřed jsou čísla 3 a 5, median je tedy 4)*
\
> Pozor, median může být v tomto případě i desetinné číslo, je tedy nutné vypisovat float. Pokud je ale číslo celé, vypište jej bez desetinné čárky.

## Příkladové problémy
### Příklad 1
#### Vstup
```
3
1
5
3

```
#### Výstup
```
3

```
---
### Příklad 2
#### Vstup
```
6
1
2
8
1
4
2

```
#### Výstup
```
2

```