# Počet různých čísel

Aneta si ráda hraje s čísly. Napiš program, který jí pro zadaný počet číslic `n` vrátí počet různých čísel, která mají `n` cifer

Program přijme na standardním vstupu celé číslo `n`, které představuje počet cifer. Program poté vypíše počet různých čísel, která mají přesně `n` cifer. 

Na druhém řádku program přijme cifru, která se nesmí vyskytovat v žádném čísle.

Číslo musí být platné - nesmí začínat nulou. (kromě čísla 0)

Záporná čísla nepočítáme.

## Příklady

### Příklad 1
#### Vstup
```
1
2
```

#### Výstup
```
9
```
---
### Příklad 2
#### Vstup
```
2
9
```

#### Výstup

```
72
```

## Vysvětlení výstupu

```
1
2
```
Čísla, které mají jednu cifru jsou čísla:
```
0
1
3
4
5
6
7
8
9
```
Z těchto čísel budeme ignorovat čísla, která mají v sobě cifru `2`. To je pouze číslo `2`. Zbývá nám tedy `9` různých čísel.

