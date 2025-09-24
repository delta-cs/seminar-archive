# Automat

Automat na kafe patří pro programátory mezi základní potřebu pro přežití. Proto je také nutné aby správně fungoval a vracel mince.

Vaším úkolem je napsat algoritmus pro vracení mincí, konkrétně české mince o hodnotách `1, 2, 5, 10, 20, 50`


## Vstup

- Na prvním řádku bude číslo ***C*** - cena kafe
- Následuje číslo ***V*** - počet vhozených mincí
- Poté dostanete ***V*** řádků s hodnotami vhozených mincí


## Výstup

- Vypište postupně na jednotlivé řádky hodnoty mincí, které má automat vrátit v sestupném pořadí
- Musíte vrátit co nejméně mincí *(vracet 50kč jako 50×1kč není správně)*
- V případě, že nebyla vhozena dostatečná částka pro zaplaceni kafe, vypište `nelze vydat`

## Příklady

1)
input:
```
17
3
5
10
5
```
output:
```
2
1
```
vysvětlení:
- Cena kafe ***C***=17 a bylo vhozeno ***V***=3 mincí v celkové hodnotě 20
- Je třeba vrátit 3 *(20-17=3)*
- Mince hodnoty 3 neexistuje, můžeme ale vrátit mince 2 a 1 *(nutno vypsat v sestupném pořadí)*

2)
input:
```
60
2
50
2
```
output:
```
nelze vydat
```