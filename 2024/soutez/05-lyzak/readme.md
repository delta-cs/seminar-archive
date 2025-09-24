# Lyžák

Ahoj, jsem Olga, učitelka na lyžařském výcviku. Mám před sebou úkol rozdělit žáky do pokojů tak, aby byli všichni spokojení. Někteří žáci se chtějí ubytovat spolu, jiní se zase rozhodli, že by neměli být na pokoji s někým konkrétním. Mým úkolem je zajistit, aby rozdělení pokojů splnilo jejich přání a nikdo nebyl nespokojený.


Na začátku programu obdržíte následující 7 celých kladných čísel:

1. **Počet pokojů** – Určete, kolik pokojů je k dispozici.
2. **Počet volných míst na pokoji** – Pro každý pokoj obdržíte číslo, které udává, kolik žáků může být na konkretním pokoji.
3. **Počet žáků ve třídě** – Celkový počet žáků, které je třeba rozdělit.
4. **Počet kamarádů** – Kolik dvojic žáků si přeje být spolu na pokoji.
5. **Seznam kamarádů** – Každá dvojce žáků, kteří se chtějí ubytovat na stejném pokoji.
6. **Počet rivalů** – Kolik dvojic žáků se nahlásilo, že nechtějí být na pokoji spolu.
7. **Seznam rivalů** – Každá dvojce žáků, kteří nechtějí být na pokoji spolu.

Po zadání všech informací program vypíše, zda je možné žáky rozdělit tak, aby všichni co jsou kamarádi byli spolu na pokoji. Ba naopak ty co spolu být nechtějí, tak aby spolu nebyli.


## Formát vstupu

1. Počet pokojů (n)
2. n čísel, kolik žáků je na každém pokoji
3. Počet žáků ve třídě
4. Počet dvojic, které se chtějí ubytovat spolu (r)
5. r řádků, každý obsahující dva žáky, kteří se chtějí ubytovat spolu
6. Počet dvojic, které nechtějí být spolu (s)
7. s řádků, každý obsahující dva žáky, kteří nechtějí být spolu

## Formát výstupu

Program vrátí:

- **1**, pokud je možné žáky rozdělit tak, aby byli všichni spokojení,  
- **0**, pokud to není možné.

---

## Příklad 1

### Vstup
```
3
3 3 2
7
2
1 2
3 4
1
2 3
```

### Výstup
```
1
```

### Vysvětlení
- Máme 3 pokoje: první dva pokoje pro 3 žáky, třetí pro 2 žáky.
- celkem máme ve třídě 7 žáků
- spolu s žakem `1` chce být na pokoji žák `2` a s `3` chce být `4`
- Ale žák `2` rozhodně nesmí být na pokoji s `3`
- žákům `5`, `6` a `7` je jedno s kým budou
---
Ano je možné je rozdělit do pokoju aby byli všichni spokojený.\
Například:
1. pokoj => `1`, `2` a `7`
2. pokoj => `5` a `6`
3. pokoj => `3` a `4`

je samozřejmně více možnosti




## Příklad 2

### Vstup
```
2
3 7
5
2
1 2
2 5
1
1 5
```

### Výstup
```
0
```
### Vysvětlení
není možné protože `2` chce být s `1` a `5` ale `1` nechce být s `5`

