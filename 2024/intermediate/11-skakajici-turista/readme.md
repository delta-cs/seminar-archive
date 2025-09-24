# Skákající turista

Napiš program, který spočítá, kolika způsoby se může turista dostat na poslední horskou chatu, pokud může přejít buď o 1,2....`n` chaty dopředu. Program vrátí počet originálních kombinací kterými se turista muže dostat na konec trasy.

## vysvětlení
Program na první řadku vstupu dostane pocet horských chat. (`n`)\
Například když na vstupu bude 4 tak si představíme 4 horské chat.

1. chata kde turista začíná
2. chata na které se muže zastavit ale nemusí
3. další chata na které se muže zastavit ale nemusí
4. chata kde turista musí skončit

Další řadek vstupu bude obsahovat maximmalní počet chat který muže turysta zdolat za 1 den. (`k`)\
Například pokud na vstupu bude 3 znamená to že za 1 den muže turista se posunout o 1, 2 nebo 3 chaty dal (pro 4 by to bylo 4, 3, 2 nebo 1 atd.)

takže pro naše vymyšlené zadani kde máme 4 chaty a turysta muže chodit až po 3 chatách najednou by možné řešení byli


-  A -> B -> C -> D
-  A -> C -> D
-  A -> B -> D
-  A -> D

1. možnost turysta každý den naštíví 1 chatu
2. možnost turysta první den přeskočí chaatu B a jde rovnou do C
3. možnost sice nevynechá chatu B ale naopak vynechá chatu C
4. možnost turysta přeskočí všechny chaty a hned 1. dorazí do cíle 

takže by náš program vrátil pro tenhle teoretický scenař vrátil 4

## Typ vstupu
Na prvním řádku dostane program celé kladné číslo `n` (počet chat) a na dalším řádku celé kladné číslo `k` které určuje kolik maximálně chat je schopen zvládnout za 1 den

## Typ výstupu
Program vráti počet možností kolika způsoby se turysta může dostat do cílové chaty.
