# Kůň na šachovnici

## Zadání  
Napište program, který na základě pozice koně na šachovnici určí všechny pozice, na které se kůň může přesunout. Kůň se může pohybovat do tvaru písmene L. (pokud neznáte šachy použíte google)


## Typ vstupu  
Na vstupu program obdrží na jednom řádku souřadnice reprezentující pozici koně na šachovnici. Pozice je zadána ve formátu `sloupecřádek`, kde:  
- `sloupec` je jedno písmeno od `a` do `h`,  
- `řádek` je číslo od `1` do `8`.  



## Typ výstupu  
Na výstupu program vypíše všechny pozice, na které se dáma může přesunout. Pozice budou vypsány jako seznam řetězců (např. `b2`, `c3`, apod.), přičemž:  
- Pozice musí být seřazeny **abecedně** podle sloupce a řádek.  
- Výstup by neměl obsahovat výchozí pozici dámy.


## Příklady  

### Příklad 1  
#### Vstup  
```
a1
```

#### Výstup  
```
b3 c2
```


### Příklad 2  
#### Vstup  
```
d4
```

#### Výstup  
```
b3 b5 c2 c6 e2 e6 f3 f5
```


### Příklad 3  
#### Vstup  
```
h8
```

#### Výstup  
```
f7 g6
```  
