# 4. Vysokohorská železnice

_Vlaky nesnesou jen tak nějaké stoupání, musí pěkně pomalu…_

Ve vstupu programu bude:

* Na 1. řádku tzv. minimální neskloněná dráha `mnd` (viz níže).
* Na 2. řádku souřadnice výchozí stanice - dvě celá čísla _x_, _y_ oddělená mezerou.
    * Souřadnice číslujeme od 0, _x_ zleva doprava, _y_ shora dolů,
* Na 3. řádku souřadnice cílové stanice - dvě celá čísla _x_, _y_ oddělená mezerou. Cíl bude mít vždy jiné souřadnice,
  než start.
* Na 4. řádku rozměry mapy (šířka `w`, pak výška `h`) - dvě celá čísla oddělená mezerou.
* Následuje prázdný řádek.
* Po něm bude výpis mapy horské krajiny - `h` řádků, na každém `w` celých čísel oddělených mezerami. Čísla znamenají
  nadmořskou výšku.

Železnice může být vedena pouze mezi sousedními políčky, ne šikmo. Pokud po železnici pojedeme, tak po zvýšení výšky o
1 musí následovat nejméně `mnd` úseků (polí), které jsou rovné nebo dolů. `mnd = 0` tedy znamená, že lze stoupat každý
krok.

Větší stoupání než o 1 není přípustné nikdy.

Vlaky jezdí po železnici tam i zpět. Hledejte tedy pouze takovou cestu, která ani v opačném směru neporuší pravidla o
stoupání. Viz příklady #2, #3.

Vlak na cestě nemůže couvat (jet na pole, ze kterého přijel), ale může jedno pole navštívit vícekrát, aby déle setrval
bez stoupání a dodržel `mnd` - viz příklad #4.

Vaším úkolem bude najít nejkratší cestu (pokud je více stejně dlouhých, vypište kteroukoli z nich) ze startovní stanice
do cílové, která splní požadavky. Ve výstupním souboru uveďte na řádky pod sebe souřadnice všech průjezdních bodů včetně
startovní a cílové stanice.

Pokud cesta neexistuje, nevypisujte nic.

## Příklad #1

### Vstup

```
2
0 0
1 3
4 5

0   0   0   1
2   1   1   1
3   4   4   1
2   3   3   1
2   2   2   2
```

### Výstup

```
0 0
1 0
2 0
3 0
3 1
3 2
3 3
3 4
2 4
1 4
1 3
```

Pro `mnd = 0` a zbytek zadání nezměněný by trasa byla

```
0 0
1 0
1 1
0 1
0 2
0 3
1 3
```

## Příklad #2

### Vstup

```
2
0 0
4 0
5 1

3   2   1   1   0
```

Výstup

```
```

### Vysvětlení

Při cestě z bodu `0 0` do `4 0` vlak pouze klesá, takže cesta do cíle je možná. V opačném směru však po stoupnutí na
výšku 1 nenásledují před dalším stoupání 2 rovné nebo klesající kroky, a toto zadání tudíž nemá řešení.

## Příklad #3

### Vstup

```
2
0 1
4 1
5 3

6   6   6   7   6
5   0   0   0   5
6   7   6   6   6
```

Výstup

```
```

### Vysvětlení

- Ze startu do cíle vede cesta "horem" (po nultém řádku).
- Z cíle do startu vede cesta "spodem" (po druhém řádku).

Neexistuje však jedna cesta, po které by se dalo jet tam i zpět, a toto zadání tudíž nemá řešení.

## Příklad #4

### Vstup

```
6
0 0
1 5
2 6

5   6
0   6
6   6
6   6
0   7
0   7
```

### Výstup

```
0 0
1 0
1 1
1 2
1 3
0 3
0 2
1 2
1 3
1 4
1 5
```

### Vysvětlení

Cesta může navštívit jeden bod vícekrát. Zde toho lze využít, když se cesta "zatočí" na čtveřici polí výšky 6, aby
dodržela `mnd` a mohla pokračovat dál.
