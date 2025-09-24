# Ověř, zda je sudoku validní

Moje babička hrozně ráda hraje sudoku 9×9. Ale občas se stane, že udělá chybu a vloží dvě stejná čísla do jednoho řádku, sloupce nebo čtverce 3×3.  
Aby si mohla být jistá, že její sudoku je správné, napiš program, který ověří, zda je zadané sudoku validní.

## Typ vstupu

Program dostane na vstupu sudoku 9×9, které bude částečně vyplněné.  
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
Na výstupu program vrátí `True`, pokud je sudoku validní, nebo `False`, pokud obsahuje chybu.  
Například pro uvedené sudoku je validní, takže výstup bude `True`.

Pokud by někde ve sloupci, řádku nebo čtverci 3×3 byly dvě stejná čísla, výstup by byl `False`.

## Příklad 1
#### Vstup
```
5 3 . . 7 . . . . 
6 . . 1 9 5 . . . 
. 9 8 . . . . 6 . 
8 . . . 6 . . . 3 
4 . . 8 . 3 . . 1 
7 . . . 2 . . . 6 
. 6 . . . . 2 8 . 
. . . 4 1 9 . . 5 
. . . . 8 . . 7 7
```
#### Výstup
```
False
```
### Vysvětlení
Sudoku není validní, protože v posledním řádku je dvakrát číslo `7`.

## Příklad 2

#### Vstup
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
#### Výstup
```
True
```
### Vysvětlení
Sudoku je validní, protože žádné číslo se neopakuje v žádném řádku, sloupci ani čtverci 3×3.


