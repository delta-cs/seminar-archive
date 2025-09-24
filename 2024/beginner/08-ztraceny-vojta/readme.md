# Ztracený Vojta
Vojta rád běhá orientační běh. Vedlejším účinkem této aktivity ale je to, že se velmi často ztrácí.

Vojta si ale vymyslel nový způsob, jak se vždy v mapě najít:
- Jeho mapa je rozdělená na čtvercovou mřížku
- Vždycky po chvilce běhu, nebo když se rozhodne hodně zatočit si zapíše kolik čtverečků od posledního zapsáni zhruba uběhl

Napište Vojtovi program, který na základě jeho zápisků zjistí, na jakém čtverečku mapy právě Vojta je.

## Popis vstupu

- na 1. řádku dostanete pozici startu závodu na mapě na ose `X`
- na 2. řádku dostanete pozici startu závodu na ose `Y`
- na 3. řádku dostanete počet Vojtových zápisků `Z`
- Následuje 2*`Z` řádků Vojtových zápisků (jeden zápis = 2 řádky)
\
Zápisky jsou kolik uběhl od poslední pozice po ose `X` *(na prvním řádku zápisu)* a `Y` *(na druhém řádku zápisu)*


- Vypište 2 řádky:
    \
1: Vojtova pozice na ose `X`
    \
2: Vojtova pozice na ose `Y`


> - počet zápisků `Z` bude vždy **celé kladné číslo, může ale být i 0**
\
(v případě nuly se nějak Vojtovi podařilo ztratit už na startu, jeho pozice je tedy pozice startu)
> - zbytek čísel budou vždy **celá**, mohou ale být **záporná**  (a samozřejmě také 0)
> - mřížka mapy je číslovaná na ose `X` **z leva do prava** a na ose `Y` **od zhora dolů**
\
(pokud tedy vojta například uběhl na `X` **-2** a na `Y` **-1**, uběhl od poslední pozice **2** čtverce **doleva** a **1** čtverec **nahoru** )


## Příkladové vstupy
### Př. 1
Vstup:
```
1
1
2
3
1
-2
2
```
Výstup:
```
2
4
```
Vysvětlení:

Vojta startuje na čtverci se souřadnicemi `X`=1 a `Y`=1 a podle 3. řádku víme, že si udělal 2 zápisky
\
Při prvním zápisku uběhl po ose `X` 3 čtverce doprava a na `Y` 1 čtverec dolů (nachází se tedy na pozici `X`=4, `Y`=2)
\
Při druhém zápisu uběhl 2 čtverce doleva a 2 čtverce dolů, nachází se tedy na pozici `X`=2, `Y`=4, což je náš výsledek

### Př. 2
Vstup:
```
0
0
4
1
-10
5
3
0
0
-3
2
```
Výstup:
```
3
-5
```

### Př. 3
Vstup:
```
20
30
0
```
Výstup:
```
20
30
```