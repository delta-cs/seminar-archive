# Typy trojúhelníků
Je potřeba napsat program, který bude rozeznávat typ trojúhelníku.\
Trojúhelníky mohou být:

<ol start="0">
  <li>nejde sestrojit</li>
  <li>různostranný</li>
  <li>rovnoramenný</li>
  <li>rovnostranný</li>
</ol>


## Nejde sestrojit

Trojúhelník lze sestrojit pokud platí trojúhelníková nerovnost

- a <= b + c
- b <= a + c
- c <= a + b

## Různostranný

Trojúhelník je různostranný pokud jsou všechny strany jiné

- a ≠ b ≠ c

## Rovnoramenný

Trojúhelník je rovnoramenný pokud jsou přesně dvě strany stejné

- a = b ≠ c
- c = a ≠ b
- b = c ≠ a

## Rovnostranný

Trojúhelník je rovnostranný pokud jsou přesně tři strany stejné
- a = b = c
- c = a = b
- b = c = a

## Typ vstupu

Na vstupu programu bude (na samostatných řádcích)

- `a` – délka strana a (celé kladné číslo),
- `b` – délka strana b (celé kladné číslo),
- `c` – délka strana c (celé kladné číslo),

## Typ výstupu

Vracejte číselnou hodnotu podle:

- 0 pro nejde sestrojit
- 1 pro různostranný
- 2 pro rovnoramenný
- 3 pro rovnostranný

## Příklady
### Příklad 1
#### Vstup
```
1
1
11
```

#### Výstup
```
0
```
---
### Příklad 2
#### Vstup
```
11
5
8
```

#### Výstup
```
1
```
---
### Příklad 3
#### Vstup
```
8
8
3
```

#### Výstup
```
2
```
---
### Příklad 4
#### Vstup
```
8
8
8
```

#### Výstup
```
3
```
