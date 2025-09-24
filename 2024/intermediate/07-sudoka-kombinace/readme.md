# Najdi počet řešení sudoku

Moje babička hrozně ráda hraje sudoku 9×9. Ale vždy, když nějaké vyřeší, neví, jestli náhodou nemá víc řešení, a bojí se, že se ochudila o nějaké.  
Aby se babička už nemusela trápit, napiš program, který spočítá, kolik řešení má zadané sudoku.

## Typ vstupu

Program dostane na vstupu sudoku 9×9, které bude částečně vyplněné.  
Máte zaručeno, že sudoku bude z velké části doplněné (aby program neběžel dlouho).  
Na každém řádku bude 1 řádek sudoku s čísly `1-9` nebo `.`.  
Prázdné hodnoty budou označeny `.`.  
Jednotlivá čísla a prázdné hodnoty na řádku budou odděleny mezerou.

Například pro sudoku:

![Sudoku](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/800px-Sudoku-by-L2G-20050714.svg.png)

by vstup vypadal takto:
```
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
```
## Typ výstupu
Na výstupu program vrátí číslo, kolik má zadané sudoku řešení.  
Například pro uvedené sudoku existuje jen jedno řešení (můžete si to schválně zkusit vyřešit! :D).

Pokud sudoka nemá řešení program vypíše `0`
## Příklad
#### Vstup
```
5 . . 8 2 . . 6 .
. 4 1 . . 6 . . 7
. . . . . . 5 . .
. . 6 . 1 . . 4 .
1 . . . . 2 . . .
2 5 . . 3 . . 7 .
. . . 1 . . . . 9
6 . . 5 . 3 . . 1
4 . . . 6 . . 3 .
```
#### Výstup
```
4
```
### Vysvětlení
Program má 4 řešení což jsou:
#### Řešení 1
![Řešení 1](https://i.imgur.com/BoP4riy.png)
#### Řešení 2
![Řešení 2](https://i.imgur.com/fvpVOwz.png)
#### Řešení 3
![Řešení 3](https://i.imgur.com/a0JJ75D.png)
#### Řešení 4
![Řešení 4](https://i.imgur.com/fIo8O16.png)

