# Nakresli kruh
Martin má na hodině matematiky kreslit různě velké kruhy. Bohužel si však nepřinesl kružítko a tak má po ruce pouze psací stroj po dědovi a stoh různě velkých papírů. Napište program, který Martinovi pomůže kruh na psacím stroji *"nakreslit"*.


## Popis vstupu
na vstup dostanete postupně po sobě na nové řádky čísla:
- *`w`* - šířka papíru
- *`h`* - výška papíru
- *`x`* - souřadnice středu kruhu v ose x
- *`y`* - souřadnice středu kruhu v ose y
- *`r`* - poloměr kruhu
> - čísla budou vždy celá a kladná, pouze *`x`* a *`y`* mohou být i 0
>
> - souřadnice x a y jsou udané jako vzdálenost od levého horního rohu papíru, počínaje nulou (0) jako první políčko

## Specifikace programu

- Martin kreslí vyplněný kruh pomocí znaků hashtag (`#`)
- Kde není kruh, ale je pořád papír, musíte vypsat papír pomocí teček (`.`)
- Pozor, není zaručeno, že se celý kruh vejde uvnitř papíru. V tom případě ho osekněte tak, aby se vytisknula pouze část uvnitř papíru.
- Střed (*`x`*,*`y`*) bude vždy ležet uvnitř papíru
- Mezi znaky nedělejte mezery ani nevypisujte zprávy pro uživatele

## Příklady
### Příklad 1
#### Vstup
```
10
10
5
5
3
```
#### Výstup
```
..........
..........
.....#....
...#####..
...#####..
..#######.
...#####..
...#####..
.....#....
..........
```
#### Vysvětlení
Papír má velikost 10×10 znaků.
\
Střed kruhu je na souřadnicích `x=5`, `y=5` a má poloměr **3** znaky -> kruh je přibližně uprostřed papíru

### Příklad 2
#### Vstup
```
15
10
0
0
6
```
#### Výstup
```
#######........
######.........
######.........
######.........
#####..........
####...........
#..............
...............
...............
...............
```
#### Vysvětlení
Papír má velikost 15×10 znaků.
\
Střed kruhu je na souřadnicích `x=0`, `y=0` (0 znaků od levého horního rohu na obou osách -> střed leží na rohovém políčku v levém horním rohu)

### Příklad 3
#### Vstup
```
16
8
15
7
4
```
#### Výstup
```
................
................
................
...............#
.............###
............####
............####
...........#####
```
#### Vysvětlení
Velikost papíru: 16×8
\
Střed je v políčku v pravém dolním rohu papíru (souřadnice středu jsou o 1 menší než velikost papíru, protože souřadnice počítáme od nuly)

## malá nápověda :)
Definice kruhu: Kruh je množina všech bodů, které mají od daného bodu (středu) vzdálenost rovnou poloměru, nebo menší než poloměr
