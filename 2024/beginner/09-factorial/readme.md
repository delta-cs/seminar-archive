# Faktoriál

Štěpán dostal za domácí úkol příklady, ale vyskytuje se v nich záhadný vykřičník. Na internetu se dozvěděl, že toto znaménko značí [faktoriál](https://cs.wikipedia.org/wiki/Faktoriál) čísla. Pomůžeš mu s tímto domácím úkolem?

## Faktoriál

$$
\textbf{Štěpán si přečetl, že faktoriál vypadá takto:}\newline\newline
Faktorial(n)=n * Faktorial(n - 1)\qquad ; n >= 0\newline\newline
$$

$$
\textbf{Nebo také takto:}\newline\newline
Faktorial(n)=\prod_{k=1}^n k\qquad ; n >= 0\newline\newline
$$

Neboli, faktoriál je násobek čísla a násobků všech předchozích čísel.

***Například*: 5! = 5 * 4 * 3 * 2 * 1 = 120 ; 6! = 6 * 5 * .. * 2 * 1**
**POZOR: 0! = 1** 

## Formát vstupu a výstupu
Naprvní řádce dostanete celé číslo n, které značí počet čísel ve vstupu. Na jednotlivých řádcích vstupu poté dostanete n celých čísel k~n~ a vy na každé z nich odpovíte jeho faktoriálem. Při neplatném vstupu vypište `Invalid input`. Jako neplatný vstup se považuje například číslo menší než nula.

**Pokud budete úlohu řešit v programovacím jazyce C/C++/C# nebo v jakýkoliv jiném staticky typovaném jazyce, nezapomeňte pro výsledky použít 64-bitová čísla (`unsigned long long` v C/C++, `ulong` v C#, `unsigned long` v Javě atd. V Pythonu, JavaScriptu a jim podobným jazycích toto řešit nemusíte.)**

## Příklady
### Příklad 1
#### Vstup
```
4
1
2
3
5
```

#### Výstup
```
1
2
6
120
```


### Příklad 2
#### Vstup
```
2
-12
6
```

#### Výstup
```
Invalid input
720
```



---

Veškeré výukové materiály se nachází na [https://github.com/delta-cs/seminar](https://github.com/delta-cs/seminar).

V případě, že vám řešení nebude uznáno a nebudete vědět proč, navštivte nejdříve [stránku s technickými pravidly](https://github.com/delta-cs/seminar/tree/main/studijni-materialy/03-tipy-k-reseni/01-technicka-pravidla) a ujistěte se, že program všechna splňuje.