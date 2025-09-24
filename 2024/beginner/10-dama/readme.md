# Dáma na šachovnici

## Zadání  
Napište program, který na základě pozice dámy na šachovnici určí všechny pozice, na které se dáma může přesunout. Dáma se může pohybovat horizontálně, vertikálně a diagonálně v libovolném směru.


## Typ vstupu  
Na vstupu program obdrží na jednom řádku souřadnice reprezentující pozici dámy na šachovnici. Pozice je zadána ve formátu `sloupecřádek`, kde:  
- `sloupec` je jedno písmeno od `a` do `h`,  
- `řádek` je číslo od `1` do `8`.  



## Typ výstupu  
Na výstupu program vypíše všechny pozice, na které se dáma může přesunout. Pozice budou vypsány jako seznam řetězců (např. `b2`, `c3`, apod.), přičemž:  
- Pozice musí být seřazeny **abecedně** podle řádku a sloupce.  
- Výstup nebude obsahovat výchozí pozici dámy.


## Příklady  

### Příklad 1  
#### Vstup  
```
a1
```

#### Výstup  
```
a2 a3 a4 a5 a6 a7 a8 b1 b2 c1 c3 d1 d4 e1 e5 f1 f6 g1 g7 h1 h8
```


### Příklad 2  
#### Vstup  
```
d4
```

#### Výstup  
```
a1 a4 a7 b2 b4 b6 c3 c4 c5 d1 d2 d3 d5 d6 d7 d8 e3 e4 e5 f2 f4 f6 g1 g4 g7 h4 h8
```


### Příklad 3  
#### Vstup  
```
h8
```

#### Výstup  
```
a1 a8 b2 b8 c3 c8 d4 d8 e5 e8 f6 f8 g7 g8 h1 h2 h3 h4 h5 h6 h7
```  
