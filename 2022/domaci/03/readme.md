# Najděte a odstraňte chybu

Dostal se k nám téměř fungující kód pro níže popsaný problém.

Program ale nefunguje, potřebovali bychom od tebe najít a opravit dané chyby, aby program začal znovu fungovat správně.

K dispozici máme 5 implementací (C, C++, C#, Python a Java). 

Ke splnění tohoto úkolu stačí opravit **jednu** z těchto implementací
a nahrát ji na odevzdávací platformu.

Tyto implementace lze nalézt v záložce "Problemset".

<img src="attachments.png?raw=true" width="400" alt="zadání úlohy a přiložené soubory">

# Greates common divisor

## Popis

Program dostává na standardním vstupu sekvenci dvojic celých čísel **a** a **b** oddělených **mezerou** a každá dvojice čísel je oddělena **novou řákdou** (`\n`).

Program na každou dvojici čísel odpovídá (vypisuje na standardní výstup) **GCD(a, b)** - celé číslo reprezentující největší společný dělitel těchto dvou čísel.

### GCD

**GCD** dvou celých čísel **je číslo**, které je největší možné, které dělí obě dvě vstupní čísla beze zbytku.

GCD(a, b) je vždy **kladné číslo**. Ale **a** i **b** mohou být záporná celá čísla.    

Příklady:

| Vstupní číslo | Výstupní řetězec |
|---------------|------------------|
| 7 11          | 1<br>            |
| 888 2         | 2<br>            |
| 905 5         | 5<br>            |


| Vstupní číslo | Výstupní řetězec |
|---------------|------------------|
| -7 11         | 1<br>            |
| -888 -2       | 2<br>            |
| 905 -5        | 5<br>            |

Každý (tedy i úplně poslední) řádek výstupu musí být ukončen novou řádkou (`\n`).

Program musí generovat odpovědi do té doby, než přečte všechna čísla ze standardního vstupu.

Lze předpokládat, že na vstupu budou pouze validní celá čísla.

## Ukázkový vstup a výstup

Vstup:
```
7 11
888 2
905 5

```
Výstup:
```
1
2
5

```

---

Vstup:
```
-7 11
-888 -2
905 -5

```
Výstup:
```
1
2
5

```
